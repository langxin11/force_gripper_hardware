# 3D 打印指南

3D 打印机没有品牌限制，只要能打印 TPU/PLA/PETG 即可。大多数主流打印机都可以使用。作者本人使用的是 BambuLab P1S 和 Creality Ender V2。

只有指尖部分需要使用 TPU 打印。其他所有零件都可以使用 PLA、PETG、ABS 等刚性材料。

需要打印的零件：

1. **框架** - [holder_base.stl](./print_parts/holder_base.stl)
   - 推荐填充率大于 45%，以保证强度。使用 100% 填充也可以。
   - ![框架](./imgs/printing/framework.png)

2. **指尖固定座** x 2 - [gripper_figure_tip_holder.stl](./print_parts/gripper_figure_tip_holder.stl)
   - 推荐填充率 100%。
   - ![指尖固定座](./imgs/printing/figure_tip_holder.png)

3. **从动同步轮** x 2 - [idler_pulley.stl](./print_parts/idler_pulley.stl)
   - 推荐填充率 100%。
   - ![从动同步轮](./imgs/printing/idler_pulley.png)

4. **主动同步轮** x 2 - [driving_pulley.stl](./print_parts/driving_pulley.stl)
   - 推荐填充率 100%。
   - ![主动同步轮](./imgs/printing/pulley.png)

5. **UMI 指尖** x 2 - [UMI_figure_tip.stl](./print_parts/UMI_figure_tip.stl)
   - 使用 TPU 打印，填充率 100%。建议一次只打印一个，不要两个一起打印，因为 TPU 容易拉丝。
   - ![UMI 指尖](./imgs/printing/umi_figuretip.png)
