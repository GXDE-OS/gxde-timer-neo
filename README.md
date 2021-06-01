
<p align="center">
<img width="128" src="https://gitee.com/Limexb/one-tomato/raw/master/assets/icon/top.yzzi.tomato.svg" >
</p>


<h1 align="center">一只番茄</h1>


### 🍭 编译

#### 依赖安装
```
sudo apt install qt5-qmake qttools5-dev-tools libdtkwidget-dev debhelper libdtkwidget5 libdtkgui5 libdtkgui5 fakeroot qtmultimedia5-dev libqt5multimedia5 libqt5multimediawidgets5
```

#### 编译
```
dpkg-buildpackage -b -d
```

备注：构建命令在最后阶段会失败，因为你没有我的GPG私钥，无法以我的身份为包生成GPG签名，但是这不影响你使用构建出来的包。构建实际上已经成功，只是没有GPG签名而已。



### ✨特性

- 🍕 dtk 番茄钟
- 🍥 自定义时间
- 🍔 好看的ui界面
- 🌭  更多功能，敬请期待……


### 感谢deepin社区 @gbwater 提供的帮助
