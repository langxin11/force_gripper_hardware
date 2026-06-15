# Force Control Gripper URDF

A two-finger parallel gripper in URDF, with two PyBullet keyboard demos.

This URDF was generated directly by Autodesk Fusion (URDF export); the collision
geometry is the raw exported mesh and has not been optimized. If you have
suggestions for improving it, feel free to reach out: **xuhui@virginia.edu**

## The two demos

- `keyboard_control.py` — both fingers move **together** symmetrically (a single open/close value), like a normal parallel gripper.
- `keyboard_control_independent.py` — each fingertip is controlled **independently** and can travel the full span (one can move all the way across to the other side); they collide with each other instead of passing through.

## Run

```bash
conda install -c conda-forge pybullet   # or: pip install pybullet
python keyboard_control.py
python keyboard_control_independent.py
```

Each script opens a PyBullet GUI; control the gripper with the keyboard (the on-screen prints list the keys, e.g. `O`/`C` to open/close, `Q` to quit).
