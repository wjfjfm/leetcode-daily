// 字符串滚动哈希

#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MODE 1000003
typedef long long ll;

class Solution {
private:
    bool hash[MODE] = {};
    int N, NN, num_word, s_size;
    int pow(int a, int b) {
        ll result = 1;
        ll base = (ll)a;
        while (b) {
            if (b & 1) {
                result = (result * base) % MODE;
            }
            base = (base * base) % MODE;
            b >>= 1;
        }
        return (int)result;
    }

    inline int mulpow(int m, int a, int b) {
        return  ((ll)m * (ll)pow(a, b)) % MODE;
    }

    void get_word_hash(vector<string> &words) {
        int hash_num;
        for (string s: words) {
            hash_num = 0;
            for(char c: s) {
                hash_num = (hash_num * 26 + (c - 'a')) % MODE;
            }
            hash[hash_num] = true;
        }
    }

    bool check_ans(string &s, vector<string> &words, int start) {
        vector<string> tmp;
        for(int i=start; i<start+NN; i+=N) {
            tmp.push_back(s.substr(i, N));
        }
        sort(tmp.begin(), tmp.end());
        for(int i=0; i<num_word; i++) {
            if (tmp[i] != words[i]) return false;
        }
        return true;
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        num_word = words.size();
        s_size = s.size();
        N = words[0].size();
        NN = N * num_word;

        get_word_hash(words);
        int hash_num = 0;
        vector<int> result0, result;
        int count[N];
        memset(count, 0, N * sizeof(int));
        const int pow_N = pow(26, N);
        for(int i=0; i<N; i++) {
            hash_num = (hash_num * 26 + (s[i] - 'a')) % MODE;
        }

        hash_num = hash_num < 0? hash_num + MODE : hash_num;
        if (hash[hash_num]) {
            count[0]++;
            if (num_word == 1)
                result0.push_back(0);
        }

        for(int i=N; i<s_size; i++) {
            hash_num = (hash_num * 26 + (s[i] - 'a') - (s[i-N] - 'a') * pow_N) % MODE;
            hash_num = hash_num < 0? hash_num + MODE : hash_num;
            const int index = (i + 1) % N;

            if (hash[hash_num]) count[index]++;
            else count[index] = 0;

            if (count[index] >= num_word)
                result0.push_back(i - NN + 1);
        }

        sort(words.begin(), words.end());

        for(int i: result0) {
            if (check_ans(s, words, i))
                result.push_back(i);
        }
        return result;

    }
};

int main() {
    string s;
    vector<int> result;
    vector<string> words = {"foo","bar"};
    s = "barfoothefoobarman";
    result = Solution().findSubstring(s, words);
    cout << s;
    for (int i: result) cout << ' '<< i;
    cout << endl;

    s = "a";
    words = {"a"};
    result = Solution().findSubstring(s, words);
    cout << s;
    for (int i: result) cout << ' '<< i;
    cout << endl;

    s = "wordgoodgoodgoodbestword";
    result = Solution().findSubstring(s, words);
    cout << s;
    for (int i: result) cout << ' '<< i;
    cout << endl;

    s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
    words = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
    result = Solution().findSubstring(s, words);
    cout << s;
    for (int i: result) cout << ' '<< i;
    cout << endl;
}
