[中文](README.md) ||  [English](README.en.md)  
# XEngine_Authorize
本仓库有开发和主分支,如果要使用,请使用master分支下的代码  
只要仓库不是在暂停状态,那么就会有人一直维护和开发,请放心使用  

## 介绍
c c++网络验证服务器 网络授权服务器  
c c++network Authorize service  
这是网络授权验证服务器的代码库,这个服务主要提供网络授权验证功能.支持本地和网络两种验证模式  
网络验证支持TCP和WEBSOCKET验证,也就是说,支持APP程序和WEB网页端  
全国首款开源C/C++ 网络验证服务器,支持各种语言各种平台进行网络验证和授时服务  
这是一个跨平台简单高性能网络授权服务器,提供了完整的演示代码  

#### 为什么选择我们
快速迭代:功能更新及时  
技术支持:完善的技术文档和技术支持,快速响应你的问题  
不限语言:不关心你的客户端使用的语言,你可以选择自己合适的通信方式  
稳定可靠:基于C/C++实现的,核心框架10年+验证.稳定与高性能兼容  
灵活验证:支持第三方验证授权,支持分布式验证授权,可以使用自己的用户密码系统  
功能丰富:支持各种类型授权,支持时间和次数等等模式  

#### 版本区别
V3版本后协议基本重新实现,不在兼容V2协议,V3基本改为HTTP接口进行管理.兼容性更好.请查看文档获取更多.  
V2可以直接升级到V3版本,因为数据库并没有修改,直接替换程序即可.数据库兼容V2版本  

## 软件特性
基于XEngine开发并实现的一套简洁高性能跨平台网络验证授权服务器  
软件特性:  
1. 支持TCP,WEBSOCKET协议
2. 支持加密通信
3. 支持用户管理
4. 支持序列卡管理
5. 支持日志管理
6. 支持配置管理
7. 序列卡多种类型支持(分钟卡,天数卡,次数卡,自定义卡)
8. 支持试用,支持快速验证
9. 支持通过邮件找回密码
10. 支持APP程序和HTML网页授权验证
11. 支持权限控制
12. 支持HTTP管理接口,可以自己写前端实现网络验证管理界面
13. 支持第三方用户验证接口
14. 分布式验证授权功能支持
15. 黑名单管理
16. 本地cdkey生成验证支持
17. 支持公告管理
18. 支持动态验证码登录
19. 支持多端登录和合并用时

## 安装教程

#### XEngine环境
必须安装XEngine,版本需要V8.15或者以上版本,安装XEngine可以参考其Readme文档  
GITEE:https://gitee.com/xyry/libxengine  
GITHUB:https://github.com/libxengine/xengine

###### 快速部署
git clone https://gitee.com/xyry/libxengine.git 或者 git clone https://github.com/libxengine/xengine.git  
window执行XEngine_WINEnv.bat 脚本.  
Linux执行:sudo ./XEngine_LINEnv.sh -i 3  
macos执行:./XEngine_LINEnv.sh -i 3  

#### sub module
由于依赖的子模块,在你checkout仓库后,在仓库目录下执行下面的命令拉取子模块  
git submodule init  
git submodule update  
如果github访问失败,也可以在XEngine_Source\XEngine_Depend 下直接clone项目:git clone https://gitee.com/xengine/XEngine_OPenSource.git

#### Windows
使用VS打开并且编译,支持WINDOWS 7SP1以上系统  
直接运行即可,使用XEngine_AuthorizeService  
XEngine_AuthorizeApp为PC端管理工具

#### Linux
Linux使用Makefile编译,UBUNTU22.04 x64或者RockyLinux 9 x64  
在控制台运行,使用XEngine_AuthorizeService

#### Macos
使用makefile编译,控制台运行,需要mac 13以及以上版本  
在控制台运行,使用XEngine_AuthorizeService

##### 编译命令
在XEngine_Source目录下执行命令  
make 编译  
make FLAGS=InstallAll 安装库程序  
make FLAGS=CleanAll 清理编译  

## 如何使用

#### 升级
如果是升级安装,下载新版本后修改配置文件就可以直接运行了  
数据库升级需要打开数据库匹配字段和表是否一致  
#### 服务端(管理端)
Windows:编译成功后,拷贝VSCopy_x86或者VSCopy_x64 到你的编译目录,执行自动拷贝依赖的模块,然后把XEngine_Release下的文件全部拷贝到编译目录即可  
Linux or macos:直接运行即可  

#### 客户端
客户端可以参考XEngine_Apps的例子,也可以参考文档的通信协议自己集成到你的客户端,流程应该是:注册->登录->充值->等待超时->结束.  

#### 管理员
现在发布的程序自带管理员用户,用户名:admin 密码:123123aa,你需要自己修改密码.  

## 测试服务器
地址:app.xyry.org  
端口:tcp端口 5300,websocket端口 5301,http管理端 5302,传输验证密码:无加密

## 程序截图
![输入图片说明](https://www.xyry.org/XEngine_StructPic/authorize/1.png "在这里输入图片标题")
![输入图片说明](https://www.xyry.org/XEngine_StructPic/authorize/2.png "在这里输入图片标题")
![输入图片说明](https://www.xyry.org/XEngine_StructPic/authorize/3.png "在这里输入图片标题")
![输入图片说明](https://www.xyry.org/XEngine_StructPic/authorize/4.png "在这里输入图片标题")
![输入图片说明](https://www.xyry.org/XEngine_StructPic/authorize/5.png "在这里输入图片标题")
![输入图片说明](https://www.xyry.org/XEngine_StructPic/authorize/6.png "在这里输入图片标题")

## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request 

## 发展历程
V1版本为XEngine组件.大部分代码集中在XEngine中  
V2版本单独出来了所有相关模块,单独开发  
V3版本为全新版本,为了适应过多环境要求开发  

## 更新指导
数据库更新使用Navicat等数据库软件打开判断表和字段不同的地方进行修改  
修改完毕后直接把数据库拷贝到新的版本进行覆盖,修改你的配置文件即可  
3.11->3.12用户表增加了新的时间字段,请参考SQL文件

## 视频教程
你也可以观看视频教程来了解我们的代码框架情况:https://www.bilibili.com/video/BV1iF4m177aG

## 授权说明
使用此软件必须开源并且注明出处,如果想闭源商用,那么需要经过作者授权.

## 关注我们
如果你觉得这个软件对你有帮助,请你给我们一个START吧  
也可以通过微信关注我们  
![qrcode](https://www.xyry.org/qrcode.jpg)

## 提交问题

如果你有问题,可以在issues中提交

## 开发计划 
mfc转qt界面库(我们需要会Qt的人员加入一起开发)  
多端登录注册类型开关  
短信登录,扫码登录  
生成会话TOKEN分布式鉴权  
token 自动续期  
密码加密  
关键日志(强日志)  
http basic和disgt支持  
支持OAuth验证  
mysql支持  
支持用户和硬件绑定同时验证  
统计用户所有在线时间  
持久层,redis,memcached等支持  
支持代理端(序列号分发,权限控制)  
支持设置用户可以使用IP地址段  
支持绑定自定义内容  
自动售卡(支付宝,微信)  
MQTT协议支持,让你的嵌入式设备也用上授时验证  
支持三方验证(其他服务也可以发送验证请求给验证服务来做验证)  
优化第三方验证(密码系统的适配问题修改)  