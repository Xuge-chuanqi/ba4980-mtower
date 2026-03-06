@set PATH=.\os\bin
@set LIB=.\os\lib
@set INCLUDE=.\os

x6502 rt.asm
x6502 x.asm
c6502 -C -d -aa_dwnhead dwnhead.c
c6502 -C -d -aa_psnake psnake.c
c6502 -C -d -aa_psdata psnakedata.c
c6502 -C -d -aa_psfar psnakefar.c
c6502 -C -d -aa_psfar2 psnakefar2.c
c6502 -C -d -aa_psfar3 psnakefar3.c
c6502 -C -d -aa_psfar4 psnakefar4.c
link main.cfg
rename a.gam mtower.gam
