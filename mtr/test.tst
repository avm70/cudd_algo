# TestMtr Version #0.6, Release date 2/6/12
# mtr/testmtr -p 2 ./mtr/test.groups
N=0x557234e932b0 C=0x557234e93370 Y=0x0        E=0x0        P=0x0        F=0 L=0 S=0
N=0x557234e93370 C=0x0        Y=0x557234e933b0 E=0x0        P=0x557234e932b0 F=3 L=0 S=0
N=0x557234e933b0 C=0x0        Y=0x557234e932f0 E=0x557234e93370 P=0x557234e932b0 F=4 L=0 S=0
N=0x557234e932f0 C=0x0        Y=0x557234e93330 E=0x557234e933b0 P=0x557234e932b0 F=1 L=0 S=0
N=0x557234e93330 C=0x0        Y=0x0        E=0x557234e932f0 P=0x557234e932b0 F=2 L=0 S=0
#------------------------
N=0x557234e932b0 C=0x0        Y=0x0        E=0x0        P=0x0        F=0 L=0 S=12
#  (0,11)

N=0x557234e932b0 C=0x557234e93370 Y=0x0        E=0x0        P=0x0        F=0 L=0 S=12
N=0x557234e93370 C=0x0        Y=0x557234e933b0 E=0x0        P=0x557234e932b0 F=0 L=0 S=6
N=0x557234e933b0 C=0x0        Y=0x0        E=0x557234e93370 P=0x557234e932b0 F=0 L=6 S=6
#  (0(0,5)(6,11)11)

N=0x557234e932b0 C=0x557234e93430 Y=0x0        E=0x0        P=0x0        F=0 L=0 S=12
N=0x557234e93430 C=0x557234e93370 Y=0x0        E=0x0        P=0x557234e932b0 F=4 L=0 S=12
N=0x557234e93370 C=0x557234e932f0 Y=0x557234e933b0 E=0x0        P=0x557234e93430 F=0 L=0 S=6
N=0x557234e932f0 C=0x0        Y=0x557234e93330 E=0x0        P=0x557234e93370 F=0 L=0 S=2
N=0x557234e93330 C=0x0        Y=0x557234e933f0 E=0x557234e932f0 P=0x557234e93370 F=0 L=2 S=2
N=0x557234e933f0 C=0x0        Y=0x0        E=0x557234e93330 P=0x557234e93370 F=0 L=4 S=2
N=0x557234e933b0 C=0x0        Y=0x0        E=0x557234e93370 P=0x557234e93430 F=0 L=6 S=6
#  (0(0(0(0,1)(2,3)(4,5)5)(6,11)11|F)11)

#  (0(0(0,1)(2,3)(4,5)5)(6,11)11|F)
N=0x557234e932b0 C=0x557234e93430 Y=0x0        E=0x0        P=0x0        F=0 L=0 S=12
N=0x557234e93430 C=0x557234e932f0 Y=0x0        E=0x0        P=0x557234e932b0 F=4 L=0 S=12
N=0x557234e932f0 C=0x0        Y=0x557234e93330 E=0x0        P=0x557234e93430 F=0 L=0 S=2
N=0x557234e93330 C=0x0        Y=0x557234e933f0 E=0x557234e932f0 P=0x557234e93430 F=0 L=2 S=2
N=0x557234e933f0 C=0x0        Y=0x557234e933b0 E=0x557234e93330 P=0x557234e93430 F=0 L=4 S=2
N=0x557234e933b0 C=0x0        Y=0x0        E=0x557234e933f0 P=0x557234e93430 F=0 L=6 S=6
#  (0(0(0,1)(2,3)(4,5)(6,11)11|F)11)

N=0x557234e932b0 C=0x557234e93430 Y=0x0        E=0x0        P=0x0        F=0 L=0 S=12
N=0x557234e93430 C=0x557234e932f0 Y=0x0        E=0x0        P=0x557234e932b0 F=4 L=0 S=12
N=0x557234e932f0 C=0x0        Y=0x557234e93330 E=0x0        P=0x557234e93430 F=0 L=0 S=2
N=0x557234e93330 C=0x0        Y=0x557234e933b0 E=0x557234e932f0 P=0x557234e93430 F=0 L=2 S=2
N=0x557234e933b0 C=0x0        Y=0x557234e933f0 E=0x557234e93330 P=0x557234e93430 F=0 L=4 S=6
N=0x557234e933f0 C=0x0        Y=0x0        E=0x557234e933b0 P=0x557234e93430 F=0 L=10 S=2
#  (0(0(0,1)(2,3)(4,9)(10,11)11|F)11)
#------------------------
N=0x557234e932b0 C=0x0        Y=0x0        E=0x0        P=0x0        F=0 L=0 S=4
#  (0,3)

N=0x557234e932b0 C=0x557234e93430 Y=0x0        E=0x0        P=0x0        F=0 L=0 S=4
N=0x557234e93430 C=0x0        Y=0x557234e932f0 E=0x0        P=0x557234e932b0 F=4 L=0 S=2
N=0x557234e932f0 C=0x0        Y=0x0        E=0x557234e93430 P=0x557234e932b0 F=4 L=2 S=2
#  (0(0,1|F)(2,3|F)3)

#------------------------
N=0x557234e932b0 C=0x557234e93430 Y=0x0        E=0x0        P=0x0        F=0 L=0 S=12
N=0x557234e93430 C=0x557234e93330 Y=0x557234e932f0 E=0x0        P=0x557234e932b0 F=0 L=0 S=6
N=0x557234e93330 C=0x0        Y=0x557234e933b0 E=0x0        P=0x557234e93430 F=0 L=0 S=2
N=0x557234e933b0 C=0x0        Y=0x557234e933f0 E=0x557234e93330 P=0x557234e93430 F=0 L=2 S=2
N=0x557234e933f0 C=0x0        Y=0x0        E=0x557234e933b0 P=0x557234e93430 F=0 L=4 S=2
N=0x557234e932f0 C=0x0        Y=0x0        E=0x557234e93430 P=0x557234e932b0 F=4 L=6 S=6
#  (0(0(0,1)(2,3)(4,5)5)(6,11|F)11)
