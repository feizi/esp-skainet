# 示例 [[English]](./README.md)

这个文件夹包含了 ESP-Skainet 中的一些示例。这些示例的是为了演示 ESP-Skainet 的功能，并提供在项目开发过程中可以复制和适应的源代码。

# 示例设计

目前有以下两个示例可用：

- get_started

 此示例是一个内置有四个语音命令字的项目模板。用户可以参考本示例的 [readme](./get_started/README.md)，来了解语音命令词识别的特定用法和注意事项。

- garbage_classification

 在此示例中，我们使用唤醒词识别和语音命令词识别来构建离线垃圾分类示例，当识别出特定的垃圾名称时，该示例可以根据当前分类建议垃圾的类型。 例如，如果开发板听到并识别了“卫生纸”，则其播放 “干垃圾”，这表示“卫生纸”应分类为“干垃圾”。

# 使用示例

构建新示例的步骤：

* 按照入门说明创建一个 "get_started" 示例。
* 进入至您要构建的新示例的目录。
* 运行 `make menuconfig` 来配置示例。
* 运行 `make` 构建示例。
* 按照日志中打印的说明进行烧写，或运行 `make flash` 命令。

# 贡献示例

如果您有任何要与我们分享的示例，或者您认为我们可能感兴趣，请参考 [Contributions Guide](https://esp-idf.readthedocs.io/en/latest/contribute/index.html) 并且联系我们。


