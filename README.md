# ctpbee_api

构建统一完善的量化交易API

> 此处描述`ctpbee`里面的 `API` 生成

## 支持操作系统

- [x] windows
- [x] macos
- [x] linux

windows采用预编译进行支持

`python`版本:

- python36+

#### 对接生成指定版本的对接文件，参见`ctp/generate`

---

**此底层API为[vnpy](https://github.com/vnpy/vnpy).的接口的集合封装, 提供一对多API对接**

---

### 对接标准

> setup.py 文件里面描述基本标注

- module需要标识单个名字 `rohon`
- module下面的子目录应该带 `vn` + `rohon`
- 接口文件目录和文件命名规则 应该为 `vnrohonmd` + `vnrohontd`, vn是固定前缀 md和td为固定后缀