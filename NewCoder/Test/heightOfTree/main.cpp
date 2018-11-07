/*
声明一个数组height存储深度，child位置的值为parent位置的值加一，然后维护全局最大值即可。
本题最大BUG，通不过全部测试的原因是题目要求是二叉树，但是测试用例中有多叉树，引入第二个数组存储该节点的子节点数量，大于2不做深度判断，即减去多余分支的判断。

原题链接
https://www.nowcoder.com/practice/4faa2d4849fa4627aa6d32a2e50b5b25?tpId=85&&tqId=29897&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking

测试用例:（多叉树）
291 0 1 0 2 0 3 0 4 2 5 4 6 3 7 7 8 6 9 4 10 9 11 0 12 5 13 5 14 14 15 11 16 0 17 6 18 9 19 13 20 8 21 13 22 15 23 21 24 9 25 17 26 18 27 27 28 26 29 27 30 19 31 4 32 31 33 11 34 10 35 7 36 27 37 22 38 16 39 12 40 24 41 12 42 32 43 2 44 14 45 14 46 6 47 18 48 1 49 12 50 22 51 13 52 15 53 53 54 54 55 53 56 18 57 42 58 25 59 21 60 44 61 7 62 7 63 30 64 64 65 12 66 9 67 42 68 13 69 47 70 34 71 53 72 25 73 26 74 30 75 7 76 51 77 70 78 70 79 8 80 26 81 43 82 41 83 41 84 79 85 58 86 72 87 25 88 57 89 36 90 56 91 40 92 13 93 63 94 6 95 12 96 23 97 17 98 93 99 59 100 67 101 2 102 19 103 93 104 20 105 53 106 55 107 8 108 54 109 83 110 64 111 75 112 25 113 17 114 83 115 84 116 116 117 46 118 62 119 10 120 63 121 23 122 58 123 31 124 92 125 75 126 57 127 31 128 102 129 123 130 129 131 92 132 2 133 128 134 134 135 6 136 130 137 43 138 136 139 68 140 72 141 95 142 32 143 27 144 87 145 10 146 83 147 22 148 71 149 90 150 43 151 71 152 77 153 114 154 50 155 43 156 116 157 20 158 30 159 104 160 149 161 4 162 20 163 111 164 125 165 17 166 92 167 147 168 14 169 4 170 51 171 40 172 117 173 83 174 164 175 118 176 72 177 86 178 120 179 81 180 2 181 116 182 73 183 20 184 143 185 183 186 154 187 126 188 124 189 100 190 8 191 52 192 38 193 32 194 12 195 17 196 171 197 113 198 112 199 142 200 92 201 59 202 119 203 153 204 29 205 33 206 28 207 96 208 97 209 201 210 121 211 12 212 156 213 62 214 204 215 181 216 150 217 104 218 111 219 180 220 69 221 145 222 70 223 214 224 79 225 142 226 14 227 97 228 56 229 60 230 103 231 82 232 181 233 59 234 82 235 59 236 13 237 43 238 31 239 167 240 195 241 28 242 142 243 12 244 27 245 143 246 241 247 3 248 188 249 113 250 128 251 224 252 163 253 206 254 224 255 158 256 156 257 168 258 192 259 218 260 229 261 17 262 233 263 251 264 242 265 174 266 20 267 56 268 194 269 52 270 162 271 269 272 104 273 228 274 79 275 222 276 57 277 131 278 218 279 245 280 167 281 173 282 107 283 239 284 172 285 284 286 233 287 252 288 238 289 95 290
对应输出应该为:
10

*/
#include<iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    if(n < 3)
        return n;
    int height[1000] = {0};
    int binary[1000] = {0};
    int result =0;
    height[0] = 1;
    for(int i=0;i<n-1;i++){
        int parent, child;
        cin >> parent >> child;
        binary[parent] += 1;
        if(binary[parent] < 3)
            height[child] = height[parent] + 1;
        if(result < height[child])
            result = height[child];
    }
    cout << result << endl;
    return 0;
}
