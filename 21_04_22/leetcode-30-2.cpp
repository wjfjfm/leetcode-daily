// 字符串滚动哈希

#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MODE 1000003
typedef long long ll;

class Solution {
private:
    bool hash[MODE] = {};
    bool visited[30] = {};
    int pow_list[20];
    int pow_N;
    int N = 0;
    int num_word;

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

    void get_word_hash(vector<pair<int, int>> &word_hash, vector<string> &words) {
        int hash_num;
        for (string s: words) {
            hash_num = 0;
            for(char c: s) {
                hash_num = (hash_num * 26 + (c - 'a')) % MODE;
            }
            word_hash.push_back(make_pair(hash_num, pow(26, s.size())));
            N += s.size();
        }
    }

    void get_hash(const vector<pair<int, int>> &word_hash, int n, int hash_num) {
        if (n == 0) {
            hash[hash_num] = 1;
        }
        else for(int i=0; i<num_word; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            const int new_hash = (((ll)hash_num * (ll)word_hash[i].second) + word_hash[i].first) % MODE;
            get_hash(word_hash, n-1, new_hash);
            visited[i] = false;
        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        num_word = words.size();
        assert(num_word < 30);
        vector<pair<int, int>> word_hash;
        get_word_hash(word_hash, words);
        get_hash(word_hash, num_word, 0);
        pow_N = pow(26, N );
        const int s_size = s.size();
        int hash_num = 0;
        for(int i=0; i<N; i++) {
            hash_num = (hash_num * 26 + (s[i] - 'a')) % MODE;
        }
        vector<int> result;
        hash_num = hash_num < 0? hash_num + MODE : hash_num;
        if (hash[hash_num]) result.push_back(0);
        for(int i=N; i<s_size; i++) {
            hash_num = (hash_num * 26 + (s[i] - 'a') - (s[i-N] - 'a') * pow_N) % MODE;
            hash_num = hash_num < 0? hash_num + MODE : hash_num;
            cout << hash_num << ' ';
            if (hash[hash_num]) result.push_back(i-N+1);
        }
        cout << endl;
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
