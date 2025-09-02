# Cyberdeck

This project is to learn about electronics and 3D. It is also here to look cool.
The base `.stl` files were all downloaded from [here](https://www.printables.com/model/66293-msg-cyberdeck-v2).

## Current advancement

It is functional but not finished, still needs a lot of modding from the original project. 3D files need to be modified to suit my needs and some hardware has no use for me.

Currently remaking the backplate and front plate, originally I thought adding the Nuc inside the case but I will instead add a larger battery pack to make it truly portable.

![Cyberdeck advancements!](/images/cd_02_front.jpg "Cyberdeck")

Added the Micro Dot pHat on the front with a wave function to give temperature information. It is in no way precise but it looks cool.

![Cyberdeck Micro Dot pHat](/videos/cd_02_mdp.gif "Micro Dot pHat")

### Problems encountered by most common to rarest

```
Bed not level
Nozzle getting filled by plastic because of heath
Temperature too high (had to change when changing the brand of PLA filament)
Retraction causing the filament to get flat because of the wheels pressure
HDMI cables need to be very flexible, most of them suck and are too fat
```

#### Happened only once and fixed

```
Base layer print speed too high
Bowden tube was not supporting heath well and collapsing on itself
3D printer Fan stuck on 'off mode'
Low voltage when passing power like this (source -> ups -> hat -> pi), it needs to passe to the pi absolutely first
```

### Filament brand

Best to worst by order (I'm only starting to test more filament brands)

```
Ultrafuse > Real Filament
```

More to come like the dotfiles, window manager used, the eInk display config and the hardware list and the modded stl files
