# ctpbee_api

构建统一完善的量化交易API

> 此处描述`ctpbee`里面的 `API` 生成

## 支持操作系统

- [x] windows `['ctp', 'rohon, 'ctp_mini']`
- [x] macos `['ctp']`
- [x] linux `['ctp', 'ctp_mini', rohon]`

windows采用预编译进行支持

`python`版本:

- `python38+`

#### 对接生成指定版本的对接文件，参见`ctp/generate`

---

**此底层API为[vnpy](https://github.com/vnpy/vnpy)的接口的集合封装, 提供一对多API对接**

---

### 对接标准

> setup.py 文件里面描述基本标注

- module需要标识单个名字 `rohon`
- module下面的子目录应该带 `vn` + `rohon`
- 接口文件目录和文件命名规则 应该为 `vnrohonmd` + `vnrohontd`, vn是固定前缀 md和td为固定后缀

### mac 如何工作
`pip3`第一次安装后会编译安装成功，然后第一次运行`ctpbee`的程序会在某个目录提示无法找到`thostmduserapi_se.framework`和`thosttraderapi_se.framework`

在作者的mac air上面是提示在`/opt/homebrew/lib`下无法找到找到`framework`此时下载此[文件夹](https://github.com/ctpbee/ctpbee_api/tree/master/library) 然后cp -r 过去即可 

> ps: 作者不擅长Mac开发 希望大佬给予pr