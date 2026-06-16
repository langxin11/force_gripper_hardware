# force_gripper_hardware

## 物料清单（BOM）

| 名称 | 链接 | 单价 | 所需数量 | 总价 | 备注 |
|------|------|------|----------|------|------|
| XL430W250T | [Robotis](https://www.robotis.us/dynamixel-xl430-w250-t/) | $27.50 | 2 | $55.00 | Dynamixel 舵机电机，另需使用随附的 4 颗 M2.5 x 14 螺丝 |
| OpenRB-150 | [Robotis](https://www.robotis.us/openrb-150/) | $28.64 | 1 | $28.64 | 控制板。也可以使用 Dynamixel 官方 U2D2 控制套件，但价格更高 |
| MGN12H Linear Guide Rail 200MM with 2 Blocks | [Amazon](https://www.amazon.com/gp/product/B0C3VGRP6Q/ref=ox_sc_act_title_1?smid=A1YHW98JPGEZ14&th=1) | $24.98 | 1 | $24.98 | 线性导轨和滑块 |
| HTD3M Timing Belt | [Amazon](https://www.amazon.com/gp/product/B09KKXY8YS/ref=ox_sc_act_title_5?smid=A1W08XZBT3V7EI&psc=1) | $11.99 | 1 m | $5.99 | 同步带，需要 1 米 |
| Filament 1kg | [Amazon](https://www.amazon.com/Official-Creality-Precision-Toughness-Moistureproof/dp/B0C8NP63GD/ref=sr_1_3_sspa?dib=eyJ2IjoiMSJ9.Q-nkux93YS9bPhDt78N5LdHtcbFHZ8dVmXPUPNZvQM4mzLNDEpemh_fxxKVu0EX4sFCaUsIldtrfCsxvzsbAZkiMFO9uUzoWE0R8rCTwGCcLvdZJmxxYT1ioDZJJPoIZmAUtYsnw19017psVbq4Ez7eMpD-HBPjWmIFFQzvwBOMNtRvaCUyr9og5eQf5c23Vog5oKUKFXqzy1mgIXVHhbZUEHQIvgoRxsTMHJsllx_mJpSI01Hjez7Y565XixM5UxrkPbY8NoJiRZ9mowpgByg-adSyvzrx10K_s-YLnkWw.P2bDNB70_xFbfKDrS0Gt_Le3fQ5aEHpYjZ5GgYAnzqU&dib_tag=se&keywords=Creality+PETG+Filament&qid=1768817392&s=industrial&sr=1-3-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1) | $19.99 | 400 g | $7.99 | 每个夹爪约需 400 g，任意品牌均可，PLA、PETG、ABS 理论上都可以使用 |
| TPU 95 Filament 0.75kg | [Amazon](https://www.amazon.com/dp/B09KKZLZVR/ref=twister_B0F3Y1MWFK?_encoding=UTF8&th=1) | $23.99 | 150 g | $4.80 | 约需 150 g，任意品牌均可 |
| Flange Bearing F685-2RS 5x11x5mm | [Amazon](https://www.amazon.com/gp/product/B0D7BYFGVT/ref=ox_sc_act_title_3?smid=A1THAZDOWP300U&th=1) | $13.09 | 2 | $2.62 | 一包 10 个轴承，只需要 2 个 |
| Steel Dowel Pin | [Amazon](https://www.amazon.com/gp/product/B0F5W619BC/ref=ox_sc_act_title_4?smid=A3SSR6IRE5S2JM&psc=1) | $9.99 | 2 | $2.00 | 一包 10 个，只需要 2 个，长度 35 mm |
| AC Adapter 12V 4A | [Amazon](https://www.amazon.com/COOLM-100-240V-Adapter-5-5x2-5mm-5-5x2-1mm/dp/B07H493GHX/ref=sr_1_5?crid=31UGTQTIMTSA&dib=eyJ2IjoiMSJ9.U7uqcY55JN3h1vpuaGyJa9wqgNR4Qtn0I6jl3kd3BVWWJjcB4LLUDckJs93kdOVE3SOQPwhJkRBCHIv--aSJz5wei-iLwW1U_zzhIv2k9wZg_EklfBNpcd5XwUBTkdGhjUHcBtEZlfWcR6YbeMXtJUy6FdjEwaM_DJNWBDCiRVlV6d98oSZx1lBHrImv5Ix7kY5RCEfagMrOGEFeXVR8YQIaecCfR6_xMibHxjM5SHA.Iuf6N1JOFHBPJlywPhfZSHgD43ooqxobV8mA5lyuHD8&dib_tag=se&keywords=ac%2Badapter%2B12v%2B4a&qid=1768828409&sprefix=ac%2Badapter%2B12v%2B4a%2Caps%2C446&sr=8-5&th=1) | $11.90 | 1 | $11.90 | 需要 12 V 且大于 3 A，包含接头 |
| Dupont Wire Kit | [Amazon](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=sr_1_1?crid=2L9N2180ATRGB&dib=eyJ2IjoiMSJ9.QGbaFF62mgZ1Tf0J7CajkBnivKMOTOpZJUS1O07RvMTLS41NGdbYQRZJoCqqFZPkcd3YGCIhkFQdfo7PepDz3eLV_NOoru_mSlWn2Enp5UsArCqWpG7yzanovQZibrfLba8OojmtV9wqa9hDHYQ435ps99DJVjvLnn4N1GShZF1sE4AVZxOTtt3cN4QM7bs_wfztUnHDgv9UZlXJd8-XEwmtGtMa-V9Ii2tgUGETpmk.C3wjkF1MQ9MoRBFFDD9PfRpEvX2au6PVIamhVGBh7BM&dib_tag=se&keywords=dupont+wire&qid=1768828650&sprefix=dupon%2Caps%2C399&sr=8-1) | $6.98 | 约 1/3 包 | $2.33 | 用于连接 OpenRB-150 和电机。需要：5 根公对公、3 根母对母 |
| M3 Screw Set | [Amazon](https://www.amazon.com/Kadrick-Assortment-M3x4MM-35MM-Machine-Anti-Rust/dp/B0BRWCFD6Q/ref=sr_1_9?crid=1EJIVMM0QW76H&dib=eyJ2IjoiMSJ9.tCmxq8TlBFUZWb9Jmis-cm7KP9dInLT9DjZxkOUigL3U6SdUjnXJFr4Uz7TV1NjjVLpvc8qdLboOAyqA571qdqpDT5GIJZrbXR1dsFuUoOizKP6egZ6nDyO0SWELLTcZ4Ha4lPBRA85RX4BHZ3bOVP8f7926zdXXpsVwPIGDgKt4JX52sWxvZsa1psFm-9muYUQy53XZi1Mg_pvCMKrRhByRTBHEaMKuiKV4l8wjdxY.QxscECudV826QyWIjKTKBNkLbkMptEbO_vY1EP3c1P8&dib_tag=se&keywords=m3%2Bscrew%2Bset&qid=1705618891&sprefix=m3%2Bscrew%2Bs%2Caps%2C149&sr=8-9&th=1) | $19.99 | 约 1/5 包 | $4.00 | 需要：M3 10 mm x 2、M3 35 mm x 6、M3 20 mm x 2、M3 螺母 x 10、M3 8 mm x 8 |
| M6 Screws 12mm with Nuts | [Amazon](https://www.amazon.com/Screws-Assortment-Stainless-Socket-Washers/dp/B0DFWMGFDM/ref=sr_1_8?crid=3KYUGPRT8LSE5&dib=eyJ2IjoiMSJ9.po3yjSqoMpW-SzwVEF8MHg2zhZrOnddvnds3sqnKypneaRC60YrgEVKMS2As_4kN3YI2cgyar2b3h8NnP4ve743h1jWEE8f23JlywJxvgY23p6sfTHRCqVmNbh6KD4EUgvCk25CovmLwvq0yRAlMkfQ5odlCnUqBiWSroi-_EDZXOLFxc6u-Nh9m2trE6SiRimCjQTSJKky1yFQYCU4hdxlYA1hoV9dPlaJmgDkLo_Y.j_3ydymHyYPjNqOxMjoeu5Nk2ifdZQuyuXQo4JmMaOw&dib_tag=se&keywords=m6%2Bscrew&qid=1768883387&sprefix=m6%2B%2Caps%2C625&sr=8-8&th=1) | $8.99 | 2 | $2.25 | 用于将夹爪安装到 Franka 上（ISO 9409-1-A50）。包装内含 8 颗 M6 x 12 mm 螺丝，只需要 2 颗。也兼容 UR5、xArm 等 |
| M2 Screws 5mm | [Amazon](https://www.amazon.com/Socket-Stainless-Threaded-Furniture-Printing/dp/B0DKY77B3B/ref=sr_1_7_sspa?crid=3IB2ZKO4BM9AX&dib=eyJ2IjoiMSJ9.0LfgPa8EHK4zSkpz8uAdMWSs6isdePevysmlMpuqPER7rlj6GPwMKLD4BsYUfSZE0vfJxetyn9RifE5HbgRVTSlKLa8c6bC8u-1RC6gxz5o4_TGRCHeFVUOcXY5dGqTiBWeaNquQWs2boZQuad9zTYxdxK-2gb7L1SS-_Pfl7Ts9xPjEi7aXWrksujhQwXaADd_JlGnw5jHoge16AXG4sZTDPLlHwvFAUIurFbIwp5w.c5cVQIOQBBEwngSVWD7ujhbV5gfSKUXVbGrW0h6ti4A&dib_tag=se&keywords=5mm%2Bm2%2Bscrews&qid=1768850592&sprefix=5mm%2Bm2%2B%2Caps%2C345&sr=8-7-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&th=1) | $6.59 | 8 | $0.88 | 一包 60 颗，需要 8 颗 |
| USB2TTL Serial Module（可选） | [Amazon](https://www.amazon.com/HiLetgo-Module-Microcontroller-Download-Serial/dp/B00LZV1G6K/ref=sr_1_1?crid=18TR0UXD6R7UA&dib=eyJ2IjoiMSJ9.GOl5Gn9_1YdUHlj9RzaeIKAv-0oB_VxLgGu0Xx-pMEI7FCVLBe4gqc5OciCVtnw1BnojNTlz1PCk4pfeJeOltpkW4QGijTWqUOICwC4Qfmi8TCkKJsbVls-Vf9Ih370-eK9zZu-P4p6evNk1Wyp53Y8UCfRE8Agg0BfcyiVUQFcsId6A8MHVRvDgm3dl-XZjMzaZWYEcK0paHjH0iSfK6uB_PqDuvk1nayzn0vSOOH8.5kqmkOqbG7WFNmFiPQkWibaieZxb_2-SIzWfnlkLNx0&dib_tag=se&keywords=ch340&qid=1769104039&sprefix=usb2ttl%2Caps%2C790&sr=8-1&th=1) | $9.79 | 1 | $1.96 | 用于状态通道的 USB2TTL 适配器，例如 CH340 或 CP2102。对于电机控制和反馈使用独立发送/接收通道的学习场景，这是可选项。一包 5 个，只需要 1 个 |

**总成本：$152.34**

说明：

1. 除电机和 OpenRB-150 之外，其他零件都是标准件，可以购买任意品牌的等效型号。
2. 除 HTD3M 同步带外，我们也测试过 GT2 和 HTD5M。测试发现 GT2 太薄太软，在大力夹持时容易跳齿；HTD5M 则太硬，张紧需要较大力。
3. 使用电机随附的螺丝将电机安装到底座上。
4. 除了需要采购的物料外，还需要螺丝刀套装、剪刀、胶带和 3D 打印机等工具。由于 3D 打印孔位可能不是完全圆形，有时可以用锤子将钢制定位销轻轻敲入。
5. 状态反馈模块可以使用任意 USB2TTL 适配器，例如 CH340 或 CP2102。CH340 模块通常不会暴露序列号，因此多块 CH340 模块同时连接时可能难以区分。如果机器上连接了多个 USB2TTL 适配器，CP2102 或其他带可读序列号的芯片通常更容易管理。

## 遥操作器

如果需要制作一个不带 VR 的遥操作器，只需要：

- 2 x XL430W250T 电机
- 1 x OpenRB-150 控制器
- 1 x 12 V 4 A 交流电源适配器
- 杜邦线

**估算成本：$97.87**

实际使用中我们发现 VR 头显可能比较重。如果感觉太重，建议一只手握持遥操作器，另一只手握持 VR 头显。

## 触觉传感器

触觉传感器制作请参考 [FlexiTac](https://flexitac.github.io/)。

# 参考与致谢

1. [MAGPIE](https://github.com/correlllab/MAGPIE)
2. [UMI](https://umi-gripper.github.io)
3. [FlexiTac](https://flexitac.github.io/)
