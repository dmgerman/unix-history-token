begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * AUTOMATICALLY GENERATED FILE, DO NOT EDIT! * * $FreeBSD$ */
end_comment

begin_struct
struct|struct
name|pci_device_information
block|{
name|int
name|id
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_vendor_information
block|{
name|int
name|id
decl_stmt|;
name|char
modifier|*
name|desc
decl_stmt|;
name|struct
name|pci_device_information
modifier|*
name|devices
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_0675
index|[]
init|=
block|{
block|{
literal|0x1700
block|,
literal|"IS64PH ISDN Adapter"
block|}
block|,
block|{
literal|0x1702
block|,
literal|"IS64PH ISDN Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_0e11
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PCI to EISA Bridge"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"ISA Bridge"
block|}
block|,
block|{
literal|0x0508
block|,
literal|"Neteligent 4/16 TR PCI UTP/STP Controller"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"Model 1000 Triflex/PCI CPU Bridge"
block|}
block|,
block|{
literal|0x2000
block|,
literal|"Model 2000 Triflex/PCI CPU Bridge"
block|}
block|,
block|{
literal|0x3032
block|,
literal|"QVision 1280/p v0 GUI Accelerator"
block|}
block|,
block|{
literal|0x3033
block|,
literal|"QVision 1280/p v1 GUI Accelerator"
block|}
block|,
block|{
literal|0x3034
block|,
literal|"QVision 1280/p v2 GUI Accelerator"
block|}
block|,
block|{
literal|0x4000
block|,
literal|"4000 Triflex/PCI CPU Bridge"
block|}
block|,
block|{
literal|0x6010
block|,
literal|"Model 6010 HotPlug PCI Bridge"
block|}
block|,
block|{
literal|0x7020
block|,
literal|"USB Controller"
block|}
block|,
block|{
literal|0xa0ec
block|,
literal|"Fibre Channel Host Controller"
block|}
block|,
block|{
literal|0xa0f0
block|,
literal|"Advanced System Management Controller"
block|}
block|,
block|{
literal|0xa0f3
block|,
literal|"Triflex PCI to ISA PnP Bridge"
block|}
block|,
block|{
literal|0xa0f7
block|,
literal|"PCI Hotplug Controller"
block|}
block|,
block|{
literal|0xa0f8
block|,
literal|"USB Open Host Controller"
block|}
block|,
block|{
literal|0xae10
block|,
literal|"Smart-2 Array Controller"
block|}
block|,
block|{
literal|0xae29
block|,
literal|"MIS-L PCI to ISA Bridge"
block|}
block|,
block|{
literal|0xae2a
block|,
literal|"MPC CPU to PCI Bridge"
block|}
block|,
block|{
literal|0xae2b
block|,
literal|"MIS-E PCI to ISA PnP Bridge"
block|}
block|,
block|{
literal|0xae31
block|,
literal|"System Management Controller"
block|}
block|,
block|{
literal|0xae32
block|,
literal|"Netelligent 10/100 TX"
block|}
block|,
block|{
literal|0xae33
block|,
literal|"Triflex Dual EIDE Controller"
block|}
block|,
block|{
literal|0xae34
block|,
literal|"Netelligent 10 T"
block|}
block|,
block|{
literal|0xae35
block|,
literal|"Integrated NetFlex 3/P"
block|}
block|,
block|{
literal|0xae40
block|,
literal|"Dual Port Netelligent 10/100 TX"
block|}
block|,
block|{
literal|0xae43
block|,
literal|"ProLiant Integrated Netelligent 10/100 TX"
block|}
block|,
block|{
literal|0xae69
block|,
literal|"CETUS-L PCI to ISA Bridge"
block|}
block|,
block|{
literal|0xae6c
block|,
literal|"DRACO PCI Bridge"
block|}
block|,
block|{
literal|0xae6d
block|,
literal|"NorthStar CPU to PCI Bridge"
block|}
block|,
block|{
literal|0xb011
block|,
literal|"Dual Port Netelligent 10/100 TX"
block|}
block|,
block|{
literal|0xb012
block|,
literal|"Netelligent 10 T/2"
block|}
block|,
block|{
literal|0xb030
block|,
literal|"Netelligent 10/100TX"
block|}
block|,
block|{
literal|0xb04a
block|,
literal|"10/100TX WOL UTP Controller"
block|}
block|,
block|{
literal|0xb0c6
block|,
literal|"10/100TX Embedded WOL UTP Controller"
block|}
block|,
block|{
literal|0xb0d7
block|,
literal|"NC3121 rev. A& B"
block|}
block|,
block|{
literal|0xb196
block|,
literal|"Conexant SoftK56 Modem"
block|}
block|,
block|{
literal|0xf130
block|,
literal|"ThunderLAN / NetFlex-3/P"
block|}
block|,
block|{
literal|0xf150
block|,
literal|"NetFlex 3/P w/ BNC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1000
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"53C810 Fast/Narrow SCSI I/O Cntrlr"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"53C820 Fast-wide SCSI"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"53C825 Fast-wide SCSI"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"53C815 Fast SCSI"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"53C810AP Fast SCSI"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"53C860 Ultra SCSI/Narrow"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"53C1510"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"53C896 dual-channel Ultra-2 Wide SCSI"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"SYM53C895 Ultra-2 Wide SCSI"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"53C885 Ultra Wide SCSI, Ethernet"
block|}
block|,
block|{
literal|0x000f
block|,
literal|"53C875, 53C876 Ultra-Wide SCSI (53C876 is dual-channel)"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"53C895A Ultra-2 Wide SCSI"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"53C1010-33 PCI to Dual Channel Ultra3 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x008f
block|,
literal|"53C875J Ultra Wide SCSI"
block|}
block|,
block|{
literal|0x0701
block|,
literal|"53C885 10/100 MBit Ethernet"
block|}
block|,
block|{
literal|0x0702
block|,
literal|"Gigabit Ethernet Controller"
block|}
block|,
block|{
literal|0x0901
block|,
literal|"61C102 USB Controller"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"63C815 Fast SCSI Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1001
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"ispLSI1032E PCI 1616, 16 TTL-IN, 16 TTL-OUT"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"ispLSI1032E OPTO-PCI, 16 IN / 16 OUT 24 VDC"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"ispLSI1032E PCI-AD, PCI-ADDA analog I/O-card"
block|}
block|,
block|{
literal|0x0013
block|,
literal|"ispLSI1032E PCI-OptoRel, PCI-Relais 16 Relais& Opto"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"ispLSI1032E Timer, Pulse& Counter-card 16..32 bit"
block|}
block|,
block|{
literal|0x0015
block|,
literal|"ispLSI1032E PCI-DAC416, 4 channel D/A16bit precision"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"ispLSI1032E PCI-MFB high-speed analog I/O"
block|}
block|,
block|{
literal|0x0017
block|,
literal|"ispLSI1032E PROTO-3 PCI, digital I/O with chipselect"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1002
index|[]
init|=
block|{
block|{
literal|0x4158
block|,
literal|"68800AX Mach 32"
block|}
block|,
block|{
literal|0x4354
block|,
literal|"215CT222 Mach 64 CT"
block|}
block|,
block|{
literal|0x4358
block|,
literal|"210888CX Mach64 CX"
block|}
block|,
block|{
literal|0x4554
block|,
literal|"Mach64 ET"
block|}
block|,
block|{
literal|0x4654
block|,
literal|"Mach64 VT"
block|}
block|,
block|{
literal|0x4742
block|,
literal|"Rage 3D Pro AGP 2x"
block|}
block|,
block|{
literal|0x4744
block|,
literal|"Rage 3D Pro AGP 1x"
block|}
block|,
block|{
literal|0x4747
block|,
literal|"Rage 3D Pro"
block|}
block|,
block|{
literal|0x4749
block|,
literal|"3D RAGE PRO 2X AGP ATI ALL IN WONDER PRO (8MB)"
block|}
block|,
block|{
literal|0x474c
block|,
literal|"Rage XC PCI-66"
block|}
block|,
block|{
literal|0x474d
block|,
literal|"Rage XL AGP 2x"
block|}
block|,
block|{
literal|0x474e
block|,
literal|"Rage XC AGP 2x"
block|}
block|,
block|{
literal|0x474f
block|,
literal|"Rage XL PCI-66"
block|}
block|,
block|{
literal|0x4750
block|,
literal|"Rage 3D Pro PCI Graphics Accelerator"
block|}
block|,
block|{
literal|0x4751
block|,
literal|"Rage 3D Pro PCI"
block|}
block|,
block|{
literal|0x4753
block|,
literal|"Rage XC PCI"
block|}
block|,
block|{
literal|0x4754
block|,
literal|"Mach 64 GT Rage 3D II Graphics Accelerator"
block|}
block|,
block|{
literal|0x4755
block|,
literal|"Rage 3D II+"
block|}
block|,
block|{
literal|0x4756
block|,
literal|"Rage 3D IIC PCI Graphics Accelerator"
block|}
block|,
block|{
literal|0x4757
block|,
literal|"Rage 3D IIC AGP"
block|}
block|,
block|{
literal|0x4758
block|,
literal|"210888GX Mach 64 GX (WinTurbo)"
block|}
block|,
block|{
literal|0x4759
block|,
literal|"Rage 3D IIC"
block|}
block|,
block|{
literal|0x475a
block|,
literal|"Rage 3D IIC AGP"
block|}
block|,
block|{
literal|0x4c42
block|,
literal|"Rage 3D LT Pro AGP 133 MHz"
block|}
block|,
block|{
literal|0x4c44
block|,
literal|"Rage 3D LT Pro AGP 66 MHz"
block|}
block|,
block|{
literal|0x4c46
block|,
literal|"Mobility M3 AGP 2x"
block|}
block|,
block|{
literal|0x4c47
block|,
literal|"Rage 3D LT-G"
block|}
block|,
block|{
literal|0x4c49
block|,
literal|"Rage 3D LT Pro PCI"
block|}
block|,
block|{
literal|0x4c4d
block|,
literal|"Rage P/M Mobility AGP 2x"
block|}
block|,
block|{
literal|0x4c4e
block|,
literal|"Rage L Mobility AGP 2x"
block|}
block|,
block|{
literal|0x4c50
block|,
literal|"Rage 3D LT Pro PCI"
block|}
block|,
block|{
literal|0x4c51
block|,
literal|"Rage 3D LT Pro PCI"
block|}
block|,
block|{
literal|0x4c52
block|,
literal|"Rage P/M Mobility PCI"
block|}
block|,
block|{
literal|0x4c53
block|,
literal|"Rage L Mobility PCI"
block|}
block|,
block|{
literal|0x4c54
block|,
literal|"Mach 64 LT"
block|}
block|,
block|{
literal|0x5041
block|,
literal|"Rage 128 Pro PCI"
block|}
block|,
block|{
literal|0x5042
block|,
literal|"Rage 128 Pro AGP 2x"
block|}
block|,
block|{
literal|0x5043
block|,
literal|"Rage 128 Pro AGP 4x"
block|}
block|,
block|{
literal|0x5044
block|,
literal|"Rage 128 Pro PCI (TMDS)"
block|}
block|,
block|{
literal|0x5045
block|,
literal|"Rage 128 Pro AGP 2x (TMDS)"
block|}
block|,
block|{
literal|0x5046
block|,
literal|"Rage Fury MAXX AGP4x"
block|}
block|,
block|{
literal|0x5047
block|,
literal|"Rage 128 Pro PCI"
block|}
block|,
block|{
literal|0x5048
block|,
literal|"Rage 128 Pro AGP 2x"
block|}
block|,
block|{
literal|0x5049
block|,
literal|"Rage 128 Pro AGP 4x"
block|}
block|,
block|{
literal|0x504a
block|,
literal|"Rage 128 Pro PCI"
block|}
block|,
block|{
literal|0x5245
block|,
literal|"Rage 128 GL PCI"
block|}
block|,
block|{
literal|0x5246
block|,
literal|"Rage 128 GL AGP 2x"
block|}
block|,
block|{
literal|0x524b
block|,
literal|"Rage 128 VR PCI"
block|}
block|,
block|{
literal|0x524c
block|,
literal|"Rage 128 VR AGP 2x"
block|}
block|,
block|{
literal|0x5345
block|,
literal|"Rage 128 4x PCI"
block|}
block|,
block|{
literal|0x5346
block|,
literal|"Rage 128 4x AGP 2x"
block|}
block|,
block|{
literal|0x5347
block|,
literal|"Rage 128 4x AGP 4x"
block|}
block|,
block|{
literal|0x5348
block|,
literal|"Rage 128 4x"
block|}
block|,
block|{
literal|0x5354
block|,
literal|"Mach 64 ST"
block|}
block|,
block|{
literal|0x5654
block|,
literal|"215VT222 Mach 64 VT VIDEO XPRESSION"
block|}
block|,
block|{
literal|0x5655
block|,
literal|"Mach 64 VT3"
block|}
block|,
block|{
literal|0x5656
block|,
literal|"Mach 64 VT4 PCI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1003
index|[]
init|=
block|{
block|{
literal|0x0201
block|,
literal|"US201 Graphics Cntrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1004
index|[]
init|=
block|{
block|{
literal|0x0005
block|,
literal|"82C591/2-FC1 CPU Bridge"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"82C593 ISA Bridge"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"82C594 Wildcat System Controller"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"82C596/597 Wildcat ISA Bridge"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"82C541"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"82C543"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"CPU to PCI Bridge for notebook"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"82C532 Peripheral Controller"
block|}
block|,
block|{
literal|0x0102
block|,
literal|"82C534 PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"82C538 PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x0104
block|,
literal|"82C535 Host Bridge"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"82C147 IrDA Controller"
block|}
block|,
block|{
literal|0x0200
block|,
literal|"82C975 RISC GUI Accelerator"
block|}
block|,
block|{
literal|0x0280
block|,
literal|"82C925 RISC GUI Accelerator"
block|}
block|,
block|{
literal|0x0304
block|,
literal|"ThunderBird QSound PCI Audio"
block|}
block|,
block|{
literal|0x0305
block|,
literal|"ThunderBird Gameport device"
block|}
block|,
block|{
literal|0x0306
block|,
literal|"ThunderBird PCI Audio Support Registers"
block|}
block|,
block|{
literal|0x0702
block|,
literal|"VAS96011 Golden Gate II"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1005
index|[]
init|=
block|{
block|{
literal|0x2064
block|,
literal|"ALG2032/2064"
block|}
block|,
block|{
literal|0x2128
block|,
literal|"ALG2364A"
block|}
block|,
block|{
literal|0x2301
block|,
literal|"ALG2301 GUI Accelerator"
block|}
block|,
block|{
literal|0x2302
block|,
literal|"ALG2302 GUI Accelerator"
block|}
block|,
block|{
literal|0x2364
block|,
literal|"AL2364 GUI Accelerator"
block|}
block|,
block|{
literal|0x2464
block|,
literal|"ALG2364A"
block|}
block|,
block|{
literal|0x2501
block|,
literal|"ALG2564A/25128A"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_100b
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"DP83810 10/100 Ethernet MAC"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"PC87415 PCI-IDE DMA Master Mode Interface Ctrlr"
block|}
block|,
block|{
literal|0x000f
block|,
literal|"OHCI Compliant FireWire Controller"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"PCI System I/O"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"USB Controller"
block|}
block|,
block|{
literal|0xd001
block|,
literal|"PC87410 PCI-IDE Interface"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_100c
index|[]
init|=
block|{
block|{
literal|0x3202
block|,
literal|"ET4000W32P-A GUI Accelerator"
block|}
block|,
block|{
literal|0x3205
block|,
literal|"ET4000W32P-B GUI Accelerator"
block|}
block|,
block|{
literal|0x3206
block|,
literal|"ET4000W32P-C GUI Accelerator"
block|}
block|,
block|{
literal|0x3207
block|,
literal|"ET4000W32P-D GUI Accelerator"
block|}
block|,
block|{
literal|0x3208
block|,
literal|"ET6000 Graphics/Multimedia Engine"
block|}
block|,
block|{
literal|0x4702
block|,
literal|"ET6300"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_100e
index|[]
init|=
block|{
block|{
literal|0x9000
block|,
literal|"P9000 WeitekPower GUI Accelerator"
block|}
block|,
block|{
literal|0x9001
block|,
literal|"P9000 GUI Accelerator"
block|}
block|,
block|{
literal|0x9100
block|,
literal|"P9100 GUI Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1011
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"DC21050 PCI-PCI Bridge"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"DC21040 Tulip Ethernet Adapter"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"DC21030 PCI Graphics Accelerator"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"Zephyr NV-RAM"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"KZPSA SCSI to SCSI Adapter"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"DC21140 Fast Ethernet Ctrlr"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"DC21230 Video Codec"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"DC21130 PCI Integrated Graphics& Video Accel"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"TGA2"
block|}
block|,
block|{
literal|0x000f
block|,
literal|"DEFPA FDDI"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"DC21041 Tulip Plus Ethernet Adapter"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"DGLPB ATM"
block|}
block|,
block|{
literal|0x0019
block|,
literal|"DC21142/3 PCI/CardBus 10/100 Mbit Ethernet Ctlr"
block|}
block|,
block|{
literal|0x0021
block|,
literal|"21052 PCI-PCI Bridge"
block|}
block|,
block|{
literal|0x0022
block|,
literal|"DC21150-AA PCI-PCI Bridge"
block|}
block|,
block|{
literal|0x0023
block|,
literal|"DC21150 PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x0024
block|,
literal|"DC21151/2 PCI-PCI Bridge"
block|}
block|,
block|{
literal|0x0025
block|,
literal|"21153 PCI-PCI Bridge"
block|}
block|,
block|{
literal|0x0026
block|,
literal|"21154 PCI-PCI Bridge"
block|}
block|,
block|{
literal|0x0045
block|,
literal|"DC21553 PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x0046
block|,
literal|"21554 PCI-to-PCI Bridge"
block|}
block|,
block|{
literal|0x1065
block|,
literal|"RAID Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1013
index|[]
init|=
block|{
block|{
literal|0x0038
block|,
literal|"CL-GD7548 GUI-Accelerated XGA/SVGA LCD Controller"
block|}
block|,
block|{
literal|0x0040
block|,
literal|"CL-GD7555 Flat Panel GUI Accelerator"
block|}
block|,
block|{
literal|0x004c
block|,
literal|"CL-GD7556 64-bit Accelerated LCD/CRT Controller"
block|}
block|,
block|{
literal|0x00a0
block|,
literal|"CL-GD5340 GUI Accelerator"
block|}
block|,
block|{
literal|0x00a2
block|,
literal|"CL-GD5432 Alpine GUI Accelerator"
block|}
block|,
block|{
literal|0x00a4
block|,
literal|"CL-GD5434 Alpine GUI Accelerator"
block|}
block|,
block|{
literal|0x00a8
block|,
literal|"CL-GD5434 Alpine GUI Accelerator"
block|}
block|,
block|{
literal|0x00ac
block|,
literal|"CL-GD5436 Alpine GUI Accelerator"
block|}
block|,
block|{
literal|0x00b8
block|,
literal|"CL-GD5446 64-bit VisualMedia Accelerator"
block|}
block|,
block|{
literal|0x00bc
block|,
literal|"CL-GD5480 64-bit SGRAM GUI accelerator"
block|}
block|,
block|{
literal|0x00d0
block|,
literal|"CL-GD5462 Laguna VisualMedia graphics accelerator"
block|}
block|,
block|{
literal|0x00d4
block|,
literal|"CL-GD5464 Laguna 3D VisualMedia Graphics Accel"
block|}
block|,
block|{
literal|0x00d6
block|,
literal|"CL-GD5465 Laguna 3D VisualMedia Graphics Accel"
block|}
block|,
block|{
literal|0x1100
block|,
literal|"CL-PD6729 PCI-to-PC Card host adapter"
block|}
block|,
block|{
literal|0x1110
block|,
literal|"CL-PD6832 PCMCIA/CardBus Controller"
block|}
block|,
block|{
literal|0x1112
block|,
literal|"CL-PD6834 PCMCIA/CardBus Controller"
block|}
block|,
block|{
literal|0x1113
block|,
literal|"CL-PD6833 PCI-to-CardBus Host Adapter"
block|}
block|,
block|{
literal|0x1200
block|,
literal|"CL-GD7542 Nordic GUI Accelerator"
block|}
block|,
block|{
literal|0x1202
block|,
literal|"CL-GD7543 Viking GUI Accelerator"
block|}
block|,
block|{
literal|0x1204
block|,
literal|"CL-GD7541 Nordic-lite VGA Cntrlr"
block|}
block|,
block|{
literal|0x4400
block|,
literal|"CL-CD4400 Communications Controller"
block|}
block|,
block|{
literal|0x6001
block|,
literal|"CS4610 CrystalClear SoundFusion PCI Audio Accel"
block|}
block|,
block|{
literal|0x6003
block|,
literal|"CS4614/22/24 CrystalClear SoundFusion PCI Audio Accel"
block|}
block|,
block|{
literal|0x6005
block|,
literal|"CS4281 CrystalClear PCI Audio Interface"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1014
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"MCA Bridge MCA Bridge"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"Alta Lite CPU Bridge"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"Alta MP CPU Bridge"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"ISA Bridge w/PnP ISA Bridge w/PnP"
block|}
block|,
block|{
literal|0x0017
block|,
literal|"CPU Bridge CPU Bridge"
block|}
block|,
block|{
literal|0x0018
block|,
literal|"Auto LANStreamer"
block|}
block|,
block|{
literal|0x001b
block|,
literal|"GXT-150P Graphics Adapter"
block|}
block|,
block|{
literal|0x001d
block|,
literal|"82G2675"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"MCA Bridge"
block|}
block|,
block|{
literal|0x0022
block|,
literal|"82351/2 PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x002d
block|,
literal|"Python"
block|}
block|,
block|{
literal|0x002e
block|,
literal|"ServeRAID RAID SCSI Adapter"
block|}
block|,
block|{
literal|0x0036
block|,
literal|"Miami/PCI 32-bit LocalBus Bridge"
block|}
block|,
block|{
literal|0x003e
block|,
literal|"85H9533 16/4 Token Ring PCI IBM UTP/STP Ctrlr"
block|}
block|,
block|{
literal|0x0046
block|,
literal|"MPIC Interrupt Controller"
block|}
block|,
block|{
literal|0x0047
block|,
literal|"PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x0048
block|,
literal|"PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x0053
block|,
literal|"25 MBit ATM controller"
block|}
block|,
block|{
literal|0x0057
block|,
literal|"MPEG PCI Bridge"
block|}
block|,
block|{
literal|0x005c
block|,
literal|"i82557B 10/100 PCI Ethernet Adapter"
block|}
block|,
block|{
literal|0x005d
block|,
literal|"05J3506 TCP/IP networking device"
block|}
block|,
block|{
literal|0x007d
block|,
literal|"MPEG-2 Decoder"
block|}
block|,
block|{
literal|0x0095
block|,
literal|"20H2999 PCI Docking Bridge"
block|}
block|,
block|{
literal|0x00b7
block|,
literal|"256-bit Graphics Rasterizer"
block|}
block|,
block|{
literal|0x00ce
block|,
literal|"02li537 Adapter 2 Token Ring Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1017
index|[]
init|=
block|{
block|{
literal|0x5343
block|,
literal|"SPEA 3D Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_101a
index|[]
init|=
block|{
block|{
literal|0x0005
block|,
literal|"8156 100VG/AnyLAN Adapter"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"Altera FLEX ??? Raid Controller ???"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_101c
index|[]
init|=
block|{
block|{
literal|0x0193
block|,
literal|"WD33C193A 8-bit SCSI Cntrlr"
block|}
block|,
block|{
literal|0x0196
block|,
literal|"WD33C196A PCI-SCSI Bridge"
block|}
block|,
block|{
literal|0x0197
block|,
literal|"WD33C197A 16-bit SCSI Cntrlr"
block|}
block|,
block|{
literal|0x0296
block|,
literal|"WD33C296A high perf 16-bit SCSI Cntrlr"
block|}
block|,
block|{
literal|0x3193
block|,
literal|"WD7193 Fast SCSI-II"
block|}
block|,
block|{
literal|0x3197
block|,
literal|"WD7197 Fast-wide SCSI-II"
block|}
block|,
block|{
literal|0x3296
block|,
literal|"WD33C296A Fast Wide SCSI bridge"
block|}
block|,
block|{
literal|0x4296
block|,
literal|"WD34C296 Wide Fast-20 Bridge"
block|}
block|,
block|{
literal|0x9710
block|,
literal|"Pipeline 9710"
block|}
block|,
block|{
literal|0x9712
block|,
literal|"Pipeline 9712"
block|}
block|,
block|{
literal|0xc24a
block|,
literal|"90C"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_101e
index|[]
init|=
block|{
block|{
literal|0x9010
block|,
literal|"MegaRAID Fast-wide SCSI/RAID"
block|}
block|,
block|{
literal|0x9030
block|,
literal|"IDE Cntrlr"
block|}
block|,
block|{
literal|0x9031
block|,
literal|"IDE Cntrlr"
block|}
block|,
block|{
literal|0x9032
block|,
literal|"IDE and SCSI Cntrlr"
block|}
block|,
block|{
literal|0x9033
block|,
literal|"SCSI Cntrlr"
block|}
block|,
block|{
literal|0x9040
block|,
literal|"Multimedia card"
block|}
block|,
block|{
literal|0x9060
block|,
literal|"MegaRAID RAID Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1022
index|[]
init|=
block|{
block|{
literal|0x2000
block|,
literal|"79C970 Ethernet Ctrlr"
block|}
block|,
block|{
literal|0x2001
block|,
literal|"Am79C978 PCnet-Home Networking Ctrlr (1/10 Mbps)"
block|}
block|,
block|{
literal|0x2020
block|,
literal|"53C974 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x2040
block|,
literal|"79C974 Ethernet& SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7006
block|,
literal|"AMD-751 Processor-to-PCI Bridge / Memory Ctrlr"
block|}
block|,
block|{
literal|0x7007
block|,
literal|"AMD-751 AGP and PCI-to-PCI Bridge"
block|}
block|,
block|{
literal|0x7400
block|,
literal|"AMD-755 PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x7401
block|,
literal|"AMD-755 Bus Master IDE Controller"
block|}
block|,
block|{
literal|0x7403
block|,
literal|"AMD-755 Power Management Controller"
block|}
block|,
block|{
literal|0x7404
block|,
literal|"AMD-755 PCI to USB Open Host Controller"
block|}
block|,
block|{
literal|0x7408
block|,
literal|"AMD-756 PCI-ISA Bridge"
block|}
block|,
block|{
literal|0x7409
block|,
literal|"AMD-756 EIDE Controller"
block|}
block|,
block|{
literal|0x740b
block|,
literal|"AMD-756 Power Management"
block|}
block|,
block|{
literal|0x740c
block|,
literal|"AMD-756 USB Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1023
index|[]
init|=
block|{
block|{
literal|0x0194
block|,
literal|"82C194 CardBus Controller"
block|}
block|,
block|{
literal|0x2000
block|,
literal|"4DWAVE-DX advanced PCI DirectSound accelerator"
block|}
block|,
block|{
literal|0x2001
block|,
literal|"4DWAVE-NX PCI Audio"
block|}
block|,
block|{
literal|0x8400
block|,
literal|"CyberBlade i7"
block|}
block|,
block|{
literal|0x8420
block|,
literal|"CyberBlade i7 AGP"
block|}
block|,
block|{
literal|0x8500
block|,
literal|"CyberBlade i1"
block|}
block|,
block|{
literal|0x8520
block|,
literal|"CyberBlade i1 AGP"
block|}
block|,
block|{
literal|0x9320
block|,
literal|"TGUI9320 32-bit GUI Accelerator"
block|}
block|,
block|{
literal|0x9350
block|,
literal|"32-bit GUI Accelerator"
block|}
block|,
block|{
literal|0x9360
block|,
literal|"Flat panel Cntrlr"
block|}
block|,
block|{
literal|0x9382
block|,
literal|"Cyber9382"
block|}
block|,
block|{
literal|0x9383
block|,
literal|"Cyber9383"
block|}
block|,
block|{
literal|0x9385
block|,
literal|"Cyber9385"
block|}
block|,
block|{
literal|0x9386
block|,
literal|"Cyber9386 Video Accelerator"
block|}
block|,
block|{
literal|0x9388
block|,
literal|"Cyber9388 Video Accelerator"
block|}
block|,
block|{
literal|0x9397
block|,
literal|"Cyber9397 Video Accelerator"
block|}
block|,
block|{
literal|0x939a
block|,
literal|"Cyber9397DVD Video Accelerator"
block|}
block|,
block|{
literal|0x9420
block|,
literal|"TGUI9420 DGi GUI Accelerator"
block|}
block|,
block|{
literal|0x9430
block|,
literal|"TGUI9430 GUI Accelerator"
block|}
block|,
block|{
literal|0x9440
block|,
literal|"TGUI9440 DGi GUI Acclerator"
block|}
block|,
block|{
literal|0x9460
block|,
literal|"TGUI9460 32-bit GUI Accelerator"
block|}
block|,
block|{
literal|0x9470
block|,
literal|"TGUI9470"
block|}
block|,
block|{
literal|0x9520
block|,
literal|"Cyber9520 Video Accelerator"
block|}
block|,
block|{
literal|0x9525
block|,
literal|"Cyber9525 Video Accelerator"
block|}
block|,
block|{
literal|0x9660
block|,
literal|"TGUI9660XGi GUI Accelerator"
block|}
block|,
block|{
literal|0x9680
block|,
literal|"TGUI9680 GUI Accelerator"
block|}
block|,
block|{
literal|0x9682
block|,
literal|"TGUI9682 Multimedia Accelerator"
block|}
block|,
block|{
literal|0x9683
block|,
literal|"TGUI9683 GUI Accelerator"
block|}
block|,
block|{
literal|0x9685
block|,
literal|"ProVIDIA 9685"
block|}
block|,
block|{
literal|0x9750
block|,
literal|"3DImage 9750 PCI/AGP"
block|}
block|,
block|{
literal|0x9753
block|,
literal|"TGUI9753 Video Accelerator"
block|}
block|,
block|{
literal|0x9754
block|,
literal|"TGUI9753 Wave Video Accelerator"
block|}
block|,
block|{
literal|0x9759
block|,
literal|"TGUI975? Image GUI Accelerator"
block|}
block|,
block|{
literal|0x9783
block|,
literal|"TGUI9783"
block|}
block|,
block|{
literal|0x9785
block|,
literal|"TGUI9785"
block|}
block|,
block|{
literal|0x9850
block|,
literal|"3D Image 9850 AGP"
block|}
block|,
block|{
literal|0x9880
block|,
literal|"Blade 3D PCI/AGP"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1025
index|[]
init|=
block|{
block|{
literal|0x1435
block|,
literal|"M1435 VL Bridge"
block|}
block|,
block|{
literal|0x1445
block|,
literal|"M1445 VL Bridge& EIDE"
block|}
block|,
block|{
literal|0x1449
block|,
literal|"M1449 ISA Bridge"
block|}
block|,
block|{
literal|0x1451
block|,
literal|"M1451 Pentium Chipset"
block|}
block|,
block|{
literal|0x1461
block|,
literal|"M1461 P54C Chipset"
block|}
block|,
block|{
literal|0x1489
block|,
literal|"M1489"
block|}
block|,
block|{
literal|0x1511
block|,
literal|"M1511"
block|}
block|,
block|{
literal|0x1512
block|,
literal|"M1512"
block|}
block|,
block|{
literal|0x1513
block|,
literal|"M1513"
block|}
block|,
block|{
literal|0x1521
block|,
literal|"M1521 CPU Bridge"
block|}
block|,
block|{
literal|0x1523
block|,
literal|"M1523 ISA Bridge"
block|}
block|,
block|{
literal|0x1531
block|,
literal|"M1531 North Bridge"
block|}
block|,
block|{
literal|0x1533
block|,
literal|"M1533 ISA South Bridge"
block|}
block|,
block|{
literal|0x1535
block|,
literal|"M1535 PCI South Bridge"
block|}
block|,
block|{
literal|0x1541
block|,
literal|"M1541 AGP PCI North Bridge Aladdin V/V+"
block|}
block|,
block|{
literal|0x1542
block|,
literal|"M1542 AGP+PCI North Bridge"
block|}
block|,
block|{
literal|0x1543
block|,
literal|"M1543C PCi South Bridge Aladdin IV+/V"
block|}
block|,
block|{
literal|0x1561
block|,
literal|"M1561 Northbridge"
block|}
block|,
block|{
literal|0x1621
block|,
literal|"M1621 PCI North Bridge Aladdin Pro II"
block|}
block|,
block|{
literal|0x1631
block|,
literal|"M1631 PCI North Bridge Aladdin Pro III"
block|}
block|,
block|{
literal|0x1641
block|,
literal|"M1641 PCI North Bridge Aladdin Pro IV"
block|}
block|,
block|{
literal|0x3141
block|,
literal|"M3141 GUI Accelerator"
block|}
block|,
block|{
literal|0x3143
block|,
literal|"M3143 GUI Accelerator"
block|}
block|,
block|{
literal|0x3145
block|,
literal|"M3145 GUI Accelerator"
block|}
block|,
block|{
literal|0x3147
block|,
literal|"M3147 GUI Accelerator"
block|}
block|,
block|{
literal|0x3149
block|,
literal|"M3149 GUI Accelerator"
block|}
block|,
block|{
literal|0x3151
block|,
literal|"M3151 GUI Accelerator"
block|}
block|,
block|{
literal|0x3307
block|,
literal|"M3307 MPEG-1 Decoder"
block|}
block|,
block|{
literal|0x3309
block|,
literal|"M3309 MPEG Decoder"
block|}
block|,
block|{
literal|0x5212
block|,
literal|"M4803"
block|}
block|,
block|{
literal|0x5215
block|,
literal|"M5217 EIDE Controller"
block|}
block|,
block|{
literal|0x5217
block|,
literal|"M5217 I/O Controller"
block|}
block|,
block|{
literal|0x5219
block|,
literal|"M5219 I/O Controller"
block|}
block|,
block|{
literal|0x5225
block|,
literal|"M5225 EIDE Controller"
block|}
block|,
block|{
literal|0x5229
block|,
literal|"M5229 EIDE Controller"
block|}
block|,
block|{
literal|0x5235
block|,
literal|"M5235 I/O Controller"
block|}
block|,
block|{
literal|0x5237
block|,
literal|"M5237 PCI USB Host Controller"
block|}
block|,
block|{
literal|0x5240
block|,
literal|"EIDE Controller"
block|}
block|,
block|{
literal|0x5241
block|,
literal|"PCMCIA Bridge"
block|}
block|,
block|{
literal|0x5242
block|,
literal|"General Purpose Controller"
block|}
block|,
block|{
literal|0x5243
block|,
literal|"PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x5244
block|,
literal|"Floppy Disk Controller"
block|}
block|,
block|{
literal|0x5247
block|,
literal|"M1541 PCI-PCI Bridge"
block|}
block|,
block|{
literal|0x5427
block|,
literal|"PCI to AGP Bridge"
block|}
block|,
block|{
literal|0x5451
block|,
literal|"M5451 PCI AC-Link Controller Audio Device"
block|}
block|,
block|{
literal|0x5453
block|,
literal|"M5453 M5453 AC-Link Controller Modem Device"
block|}
block|,
block|{
literal|0x7101
block|,
literal|"M7101 PCI PMU Power Management Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1028
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PowerEdge 2 /Si Expandable RAID Controller"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"PowerEdge 3/Di Expandable RAID Controller"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"PowerEdge 3/Si Expandable RAID Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_102a
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"HYDRA P5 Chipset"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"ASPEN i486 Chipset"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_102b
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"MGA-I Impression?"
block|}
block|,
block|{
literal|0x0518
block|,
literal|"MGA-PX2085 Ultima/Atlas GUI Accelerator"
block|}
block|,
block|{
literal|0x0519
block|,
literal|"MGA-2064W Millenium GUI Accelerator"
block|}
block|,
block|{
literal|0x051a
block|,
literal|"MGA 1064SG 64-bit graphics chip"
block|}
block|,
block|{
literal|0x051b
block|,
literal|"MGA-21164W Millenium II"
block|}
block|,
block|{
literal|0x051e
block|,
literal|"MGA-1164SG Mystique 220 (AGP)"
block|}
block|,
block|{
literal|0x051f
block|,
literal|"MGA2164WA-B Matrox Millenium II AGP"
block|}
block|,
block|{
literal|0x0520
block|,
literal|"MGA-G200B Millennium/Mystique G200 AGP"
block|}
block|,
block|{
literal|0x0521
block|,
literal|"MGA-G200 Millennium/Mystique G200 AGP"
block|}
block|,
block|{
literal|0x0d10
block|,
literal|"MGA-I Ultima/Impression GUI accelerator"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"MGA-G100"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"MGA-G100"
block|}
block|,
block|{
literal|0x2007
block|,
literal|"Mistral GUI+3D Accelerator"
block|}
block|,
block|{
literal|0x4536
block|,
literal|"Meteor 2/MC Video Capture Card"
block|}
block|,
block|{
literal|0x6573
block|,
literal|"Shark 10/100 Multiport Switch NIC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_102c
index|[]
init|=
block|{
block|{
literal|0x00b8
block|,
literal|"64310 Wingine DGX - DRAM Graphics Accelerator"
block|}
block|,
block|{
literal|0x00c0
block|,
literal|"69000 Video Accelerator with Integrated Memory"
block|}
block|,
block|{
literal|0x00d0
block|,
literal|"65545 Flat panel/crt VGA Cntrlr"
block|}
block|,
block|{
literal|0x00d8
block|,
literal|"65540 Flat Panel/CRT VGA Controller"
block|}
block|,
block|{
literal|0x00dc
block|,
literal|"65548 GUI Accelerator"
block|}
block|,
block|{
literal|0x00e0
block|,
literal|"65550 LCD/CRT controller"
block|}
block|,
block|{
literal|0x00e4
block|,
literal|"65554 Flat Panel/LCD CRT GUI Accelerator"
block|}
block|,
block|{
literal|0x00e5
block|,
literal|"65555 VGA GUI Accelerator"
block|}
block|,
block|{
literal|0x00f0
block|,
literal|"68554 GUI Controller"
block|}
block|,
block|{
literal|0x00f4
block|,
literal|"68554 HiQVision Flat Panel/CRT GUI Controller"
block|}
block|,
block|{
literal|0x00f5
block|,
literal|"68555 GUI Controller"
block|}
block|,
block|{
literal|0x03c0
block|,
literal|"69030 AGP Video Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_102d
index|[]
init|=
block|{
block|{
literal|0x50dc
block|,
literal|"3328 Audio"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_102f
index|[]
init|=
block|{
block|{
literal|0x0009
block|,
literal|"r4x00 CPU Bridge"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"Meteor 155 ATM PCI Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1031
index|[]
init|=
block|{
block|{
literal|0x5601
block|,
literal|"MiroVIDEO DC20 I/O& JPEG"
block|}
block|,
block|{
literal|0x5607
block|,
literal|"video in and out with motion jpeg compression and deco"
block|}
block|,
block|{
literal|0x5631
block|,
literal|"Media 3D"
block|}
block|,
block|{
literal|0x6057
block|,
literal|"MiroVIDEO DC10/DC30"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1033
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PCI to 486 like bus Bridge"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"PCI to vl98 Bridge"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"atm lan Cntrlr"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"R4000 PCI bus Bridge"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"PCI to 486 like peripheral bus Bridge"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"PCI to ux-bus Bridge"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"GUI Accelerator (vga equivalent)"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"graphic Cntrlr for 98"
block|}
block|,
block|{
literal|0x001a
block|,
literal|"Nile II"
block|}
block|,
block|{
literal|0x0021
block|,
literal|"Vrc4373 Nile I"
block|}
block|,
block|{
literal|0x0029
block|,
literal|"PoverVR PCX1 3D Accelerator"
block|}
block|,
block|{
literal|0x002a
block|,
literal|"PoverVR 3D Accelerator"
block|}
block|,
block|{
literal|0x0035
block|,
literal|"uPD9210FGC-7EA USB Host Controller"
block|}
block|,
block|{
literal|0x003e
block|,
literal|"NAPCCARD CardBus Controller"
block|}
block|,
block|{
literal|0x0046
block|,
literal|"PoverVR PCX2 3D Accelerator"
block|}
block|,
block|{
literal|0x005a
block|,
literal|"Vrc5074 Nile 4"
block|}
block|,
block|{
literal|0x0063
block|,
literal|"uPD72862 Firewarden IEEE1394 OHCI Host Controller"
block|}
block|,
block|{
literal|0x0067
block|,
literal|"PoverVR Neon 250 3D Accelerator"
block|}
block|,
block|{
literal|0x0074
block|,
literal|"56k Voice Modem"
block|}
block|,
block|{
literal|0x009b
block|,
literal|"Vrc5476"
block|}
block|,
block|{
literal|0x00cd
block|,
literal|"uPD72870 IEEE1394 1-Chip OHCI Host Controller"
block|}
block|,
block|{
literal|0x00ce
block|,
literal|"uPD72871 IEEE1394 1-Chip OHCI Host Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1036
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"TMC-18C30 Fast SCSI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1039
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"SiS 530 Virtual PCI-to-PCI bridge (AGP)"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"SiS 6202 PCI True-Color Graphics Accelerator"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"Pentium chipset"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"SiS 85C501 PCI/ISA Cache Memory Controller (PCMC)"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"SiS 85C503 PCI System I/O (PSIO)"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"SiS 5595 Power Management Unit (PMU)"
block|}
block|,
block|{
literal|0x0018
block|,
literal|"SiS 85C503 PCI to ISA Bridge (LPC Bridge)"
block|}
block|,
block|{
literal|0x0200
block|,
literal|"SiS5597 5597 Onboard Graphics Controller"
block|}
block|,
block|{
literal|0x0204
block|,
literal|"SiS 6215 PCI Graphics& Video Accelerator"
block|}
block|,
block|{
literal|0x0205
block|,
literal|"SiS 6205 PCI Graphics& Video Accelerator"
block|}
block|,
block|{
literal|0x0300
block|,
literal|"SiS300/305 GUI Accelerator+3D"
block|}
block|,
block|{
literal|0x0305
block|,
literal|"SiS305 2D/3D/Video/DVD Accelerator"
block|}
block|,
block|{
literal|0x0406
block|,
literal|"85C501 PCI/ISA Cache Memory Controller (PCMC)"
block|}
block|,
block|{
literal|0x0496
block|,
literal|"85C496 VL Bridge"
block|}
block|,
block|{
literal|0x0530
block|,
literal|"SiS530 Host-to-PCI bridge"
block|}
block|,
block|{
literal|0x0540
block|,
literal|"SiS540 Host-to-PCI Bridge"
block|}
block|,
block|{
literal|0x0596
block|,
literal|"p5 chipset w/DE"
block|}
block|,
block|{
literal|0x0597
block|,
literal|"SiS5513 EIDE Controller (step C)"
block|}
block|,
block|{
literal|0x0601
block|,
literal|"SiS83C601 PCI EIDE Controller"
block|}
block|,
block|{
literal|0x0620
block|,
literal|"SiS620 Host-to-PCI Bridge"
block|}
block|,
block|{
literal|0x0630
block|,
literal|"SiS630 Host-to-PCI Bridge"
block|}
block|,
block|{
literal|0x0900
block|,
literal|"SiS630 Fast Ethernet/Home Networking Ctrlr"
block|}
block|,
block|{
literal|0x3602
block|,
literal|"SiS83C602 IDE Controller"
block|}
block|,
block|{
literal|0x5107
block|,
literal|"SiS5107 Hot Docking Controller"
block|}
block|,
block|{
literal|0x5300
block|,
literal|"SiS540 AGP"
block|}
block|,
block|{
literal|0x5401
block|,
literal|"486 chipset"
block|}
block|,
block|{
literal|0x5511
block|,
literal|"SiS5511/5512 PCI/ISA System Memory Controller"
block|}
block|,
block|{
literal|0x5513
block|,
literal|"SiS5513 PCI IDE Controller"
block|}
block|,
block|{
literal|0x5517
block|,
literal|"SiS5517 CPU to PCI Bridge"
block|}
block|,
block|{
literal|0x5571
block|,
literal|"SiS5571 Memory/PCI bridge"
block|}
block|,
block|{
literal|0x5581
block|,
literal|"p5 chipset"
block|}
block|,
block|{
literal|0x5582
block|,
literal|"ISA Bridge"
block|}
block|,
block|{
literal|0x5591
block|,
literal|"SiS 5591/5592 PCI AGP& CPU Memory Controller"
block|}
block|,
block|{
literal|0x5596
block|,
literal|"SiS5596 PCI, Memory& VGA Controller"
block|}
block|,
block|{
literal|0x5597
block|,
literal|"SiS5597 Host to PCI bridge"
block|}
block|,
block|{
literal|0x5600
block|,
literal|"SiS600 Host-to-PCI Bridge"
block|}
block|,
block|{
literal|0x6204
block|,
literal|"video decoder/mpeg interface"
block|}
block|,
block|{
literal|0x6205
block|,
literal|"PCI vga Cntrlr"
block|}
block|,
block|{
literal|0x6225
block|,
literal|"SiS 6225 PCI Graphics& Video Accelerator"
block|}
block|,
block|{
literal|0x6300
block|,
literal|"SiS630 AGP"
block|}
block|,
block|{
literal|0x6306
block|,
literal|"SiS530 Integrated 3D VGA Controller"
block|}
block|,
block|{
literal|0x6326
block|,
literal|"SiS 86C326 AGP/PCI Graphics& Video Accelerator"
block|}
block|,
block|{
literal|0x7001
block|,
literal|"SiS5571 USB Host Controller"
block|}
block|,
block|{
literal|0x7007
block|,
literal|"OHCI Compliant FireWire Controller"
block|}
block|,
block|{
literal|0x7016
block|,
literal|"SiS7016 10/100 Ethernet Adapter"
block|}
block|,
block|{
literal|0x7018
block|,
literal|"SiS630 Audio Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_103c
index|[]
init|=
block|{
block|{
literal|0x1030
block|,
literal|"J2585A DeskDirect 10/100VG LAN Adapter"
block|}
block|,
block|{
literal|0x1031
block|,
literal|"DeskDirect 10/100 NIC"
block|}
block|,
block|{
literal|0x1064
block|,
literal|"79C970 PCnet Ethernet Controller"
block|}
block|,
block|{
literal|0x10c1
block|,
literal|"NetServer Smart IRQ Router"
block|}
block|,
block|{
literal|0x10ed
block|,
literal|"TopTools Remote Control"
block|}
block|,
block|{
literal|0x1200
block|,
literal|"82557B 10/100 NIC"
block|}
block|,
block|{
literal|0x1219
block|,
literal|"NetServer PCI Hot-Plug Controller"
block|}
block|,
block|{
literal|0x121a
block|,
literal|"NetServer SMIC Controller"
block|}
block|,
block|{
literal|0x121b
block|,
literal|"NetServer Legacy COM Port Decoder"
block|}
block|,
block|{
literal|0x121c
block|,
literal|"NetServer PCI COM Port Decoder"
block|}
block|,
block|{
literal|0x2910
block|,
literal|"E2910A PCI Bus Exerciser"
block|}
block|,
block|{
literal|0x2920
block|,
literal|"Fast Host Interface"
block|}
block|,
block|{
literal|0x2924
block|,
literal|"E2924A PCI Host Interface Adapter"
block|}
block|,
block|{
literal|0x2925
block|,
literal|"E2925A 32 bit PCI Bus Exerciser and Analyzer"
block|}
block|,
block|{
literal|0x2926
block|,
literal|"E2926A 64 bit PCI Bus Exerciser and Analyzer"
block|}
block|,
block|{
literal|0x2927
block|,
literal|"E2927A 64 Bit, 66/50MHz PCI Analyzer& Exerciser"
block|}
block|,
block|{
literal|0x2940
block|,
literal|"E2940A 64 bit, 66/50MHz CompactPCI Analyzer&Exerciser"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1042
index|[]
init|=
block|{
block|{
literal|0x1000
block|,
literal|"RZ1000 IDE Ctrlr"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"FDC 37C665 EIDE"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"37C922"
block|}
block|,
block|{
literal|0x3000
block|,
literal|"Samurai 0 CPU to PCI Bridge"
block|}
block|,
block|{
literal|0x3010
block|,
literal|"Samurai 1 CPU to PCI Bridge"
block|}
block|,
block|{
literal|0x3020
block|,
literal|"Samurai IDE Controller"
block|}
block|,
block|{
literal|0x3030
block|,
literal|"MT82P664 Samurai 64M2"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1043
index|[]
init|=
block|{
block|{
literal|0x0200
block|,
literal|"AGP-V3400 Asus RivaTNT Video Board"
block|}
block|,
block|{
literal|0x401d
block|,
literal|"GeForce2 MX"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1044
index|[]
init|=
block|{
block|{
literal|0x1012
block|,
literal|"Domino RAID Engine"
block|}
block|,
block|{
literal|0xa400
block|,
literal|"2124A/9X SmartCache III/RAID SCSI Controller"
block|}
block|,
block|{
literal|0xa500
block|,
literal|"PCI Bridge"
block|}
block|,
block|{
literal|0xa501
block|,
literal|"SmartRAID V Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1045
index|[]
init|=
block|{
block|{
literal|0xa0f8
block|,
literal|"82C750 PCI USB Controller"
block|}
block|,
block|{
literal|0xc101
block|,
literal|"82C264 GUI Accelerator"
block|}
block|,
block|{
literal|0xc178
block|,
literal|"82C178 LCD GUI Accelerator"
block|}
block|,
block|{
literal|0xc556
block|,
literal|"82C556 Viper"
block|}
block|,
block|{
literal|0xc557
block|,
literal|"82C557 CPU Bridge (Viper)"
block|}
block|,
block|{
literal|0xc558
block|,
literal|"82C558 ISA Bridge w/PnP"
block|}
block|,
block|{
literal|0xc567
block|,
literal|"82C750 Vendetta chipset: host bridge"
block|}
block|,
block|{
literal|0xc568
block|,
literal|"82C750 Vendetta chipset: ISA bridge"
block|}
block|,
block|{
literal|0xc569
block|,
literal|"82C579 Pentium to PCI Bridge"
block|}
block|,
block|{
literal|0xc621
block|,
literal|"82C621 PCI IDE Controller (PIC)"
block|}
block|,
block|{
literal|0xc700
block|,
literal|"82C700 FireStar chipset, PCI-ISA bridge???"
block|}
block|,
block|{
literal|0xc701
block|,
literal|"82C700 FireStar mobile chipset: host bridge"
block|}
block|,
block|{
literal|0xc814
block|,
literal|"82C814 FireBridge II Docking Station Controller"
block|}
block|,
block|{
literal|0xc822
block|,
literal|"82C822 EIDE Ctrlr"
block|}
block|,
block|{
literal|0xc824
block|,
literal|"82C824 FireFox 32-Bit PC Card Controller"
block|}
block|,
block|{
literal|0xc825
block|,
literal|"82C825 function 0 PCI-to-ISA Bridge"
block|}
block|,
block|{
literal|0xc832
block|,
literal|"82C832 CPU-to-PCI and PCI-to-ISA Bridge"
block|}
block|,
block|{
literal|0xc861
block|,
literal|"82C861 FireLink PCI-to-USB Bridge"
block|}
block|,
block|{
literal|0xc895
block|,
literal|"82C895"
block|}
block|,
block|{
literal|0xc935
block|,
literal|"82C935 MachOne integrated PCI audio processor"
block|}
block|,
block|{
literal|0xd568
block|,
literal|"82C825 PCI bus master IDE controller"
block|}
block|,
block|{
literal|0xd768
block|,
literal|"82C750 Ultra DMA IDE controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1048
index|[]
init|=
block|{
block|{
literal|0x1000
block|,
literal|"PCI to SCSI Bridge"
block|}
block|,
block|{
literal|0x3000
block|,
literal|"QuickStep 3000"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_104a
index|[]
init|=
block|{
block|{
literal|0x0008
block|,
literal|"STG 2000X"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"STG 1764X"
block|}
block|,
block|{
literal|0x1746
block|,
literal|"STG 1746X"
block|}
block|,
block|{
literal|0x3520
block|,
literal|"MPEG-II Video Decoder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_104b
index|[]
init|=
block|{
block|{
literal|0x0140
block|,
literal|"BT-946C Multimaster NC (SCSI-2)"
block|}
block|,
block|{
literal|0x1040
block|,
literal|"BA80C30 Multimaster"
block|}
block|,
block|{
literal|0x8130
block|,
literal|"Flashpoint LT Ultra SCSI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_104c
index|[]
init|=
block|{
block|{
literal|0x0500
block|,
literal|"100 MBit LAN Cntrlr"
block|}
block|,
block|{
literal|0x0508
block|,
literal|"TMS380C2X Compressor interface"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"TI PCI Eagle i/f AS"
block|}
block|,
block|{
literal|0x3d04
block|,
literal|"TVP4010 Permedia"
block|}
block|,
block|{
literal|0x3d07
block|,
literal|"TVP4020 AGP Permedia 2"
block|}
block|,
block|{
literal|0x8000
block|,
literal|"LYNX FireWire Host Controller"
block|}
block|,
block|{
literal|0x8009
block|,
literal|"OHCI Compliant FireWire Controller"
block|}
block|,
block|{
literal|0x8019
block|,
literal|"TSB12LV23 OHCI Compliant IEEE-1394 Controller"
block|}
block|,
block|{
literal|0xa001
block|,
literal|"TDC1570 64-bit PCI ATM sar"
block|}
block|,
block|{
literal|0xa100
block|,
literal|"TDC1561 32-bit PCI ATM sar"
block|}
block|,
block|{
literal|0xac10
block|,
literal|"PCI1050 pc card Cntrlr"
block|}
block|,
block|{
literal|0xac11
block|,
literal|"PCI1030/1053 PC Card Controller"
block|}
block|,
block|{
literal|0xac12
block|,
literal|"PCI1130 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac13
block|,
literal|"PCI1031 PCI-TO-PC CARD16 CONTROLLER UNIT"
block|}
block|,
block|{
literal|0xac16
block|,
literal|"PCI1250 pc card Cardbus Cntrlr"
block|}
block|,
block|{
literal|0xac17
block|,
literal|"PCI1220 CardBus Controller"
block|}
block|,
block|{
literal|0xac18
block|,
literal|"PCI1260 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac1a
block|,
literal|"PCI1210 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac1b
block|,
literal|"PCI1450 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac1f
block|,
literal|"PCI1251B PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac20
block|,
literal|"PCI2030 PCI to PCI Bridge"
block|}
block|,
block|{
literal|0xac30
block|,
literal|"PCI1260 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac40
block|,
literal|"PCI4450 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac41
block|,
literal|"PCI4410 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac42
block|,
literal|"PCI4451 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac50
block|,
literal|"PCI1410 PC card cardBus Controller"
block|}
block|,
block|{
literal|0xac52
block|,
literal|"PCI1451 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xac53
block|,
literal|"PCI1421 PC card CardBus Controller"
block|}
block|,
block|{
literal|0xfe00
block|,
literal|"FireWire Host Controller"
block|}
block|,
block|{
literal|0xfe03
block|,
literal|"12C01A FireWire Host Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_104d
index|[]
init|=
block|{
block|{
literal|0x8009
block|,
literal|"CXD1947A IEEE1394 link layer / PCI bridge"
block|}
block|,
block|{
literal|0x8039
block|,
literal|"CXD3222 OHCI i.LINK (IEEE 1394) PCI Host Ctrlr"
block|}
block|,
block|{
literal|0x8056
block|,
literal|"Rockwell HCF 56K Modem"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_104e
index|[]
init|=
block|{
block|{
literal|0x0017
block|,
literal|"OTI-64017"
block|}
block|,
block|{
literal|0x0107
block|,
literal|"OTI107 Spitfire VGA Accelerator"
block|}
block|,
block|{
literal|0x0109
block|,
literal|"Video Adapter"
block|}
block|,
block|{
literal|0x0111
block|,
literal|"OTI-64111 Spitfire"
block|}
block|,
block|{
literal|0x0217
block|,
literal|"OTI-64217"
block|}
block|,
block|{
literal|0x0317
block|,
literal|"OTI-64317"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1050
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"Ethernet Cntrlr"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"W83769F Ethernet Adapter"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"W82C105 Ethernet Adapter"
block|}
block|,
block|{
literal|0x0840
block|,
literal|"W89C840F 100/10Mbps Ethernet Controller"
block|}
block|,
block|{
literal|0x0940
block|,
literal|"w89c940f winbond pci ethernet"
block|}
block|,
block|{
literal|0x5a5a
block|,
literal|"W89C940F NE2000-compatible Ethernet Adapter"
block|}
block|,
block|{
literal|0x6692
block|,
literal|"W6692CF ISDN"
block|}
block|,
block|{
literal|0x9970
block|,
literal|"W9970CF"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1054
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PCI Bridge"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"PCI bus Cntrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1055
index|[]
init|=
block|{
block|{
literal|0x0810
block|,
literal|"486 host Bridge"
block|}
block|,
block|{
literal|0x0922
block|,
literal|"Pentium/p54c host Bridge"
block|}
block|,
block|{
literal|0x0926
block|,
literal|"ISA Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1057
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"MPC105 Eagle PowerPC Chipset"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"MPC106 Grackle PowerPC Chipset"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"MC145575 HCF-PCI"
block|}
block|,
block|{
literal|0x0431
block|,
literal|"KTI829c 100VG Ethernet Controller"
block|}
block|,
block|{
literal|0x1801
block|,
literal|"56301 Audio I/O Controller (MIDI)"
block|}
block|,
block|{
literal|0x4801
block|,
literal|"Raven PowerPC Chipset"
block|}
block|,
block|{
literal|0x4802
block|,
literal|"Falcon"
block|}
block|,
block|{
literal|0x4803
block|,
literal|"Hawk"
block|}
block|,
block|{
literal|0x4806
block|,
literal|"CPX8216"
block|}
block|,
block|{
literal|0x5600
block|,
literal|"SM56 PCI Speakerphone Modem"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_105a
index|[]
init|=
block|{
block|{
literal|0x4d33
block|,
literal|"PDC20246 Ultra ATA controller"
block|}
block|,
block|{
literal|0x4d38
block|,
literal|"PDC20262 UltraDMA66 EIDE Controller"
block|}
block|,
block|{
literal|0x5300
block|,
literal|"DC5300 EIDE Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_105d
index|[]
init|=
block|{
block|{
literal|0x2309
block|,
literal|"Imagine 128 GUI Accelerator"
block|}
block|,
block|{
literal|0x2339
block|,
literal|"I128s2 Imagine 128 Series 2"
block|}
block|,
block|{
literal|0x493d
block|,
literal|"T2R Revolution 3D"
block|}
block|,
block|{
literal|0x5348
block|,
literal|"Revolution IV Revolution IV"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1060
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"UM82C881 486 Chipset"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"UM82C886 ISA Bridge"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"UM8673F EIDE Controller"
block|}
block|,
block|{
literal|0x0881
block|,
literal|"UM8881 HB4 486 PCI Chipset"
block|}
block|,
block|{
literal|0x0881
block|,
literal|"UM8881"
block|}
block|,
block|{
literal|0x0886
block|,
literal|"UM8886F ISA Bridge"
block|}
block|,
block|{
literal|0x0891
block|,
literal|"UM82C891 Pentium Chipset"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"UM886A IDE Cntrlr (dual function)"
block|}
block|,
block|{
literal|0x673a
block|,
literal|"UM8886 Funktion 1: EIDE Controller"
block|}
block|,
block|{
literal|0x673b
block|,
literal|"EIDE Master/DMA"
block|}
block|,
block|{
literal|0x8710
block|,
literal|"UM8710 VGA Cntrlr"
block|}
block|,
block|{
literal|0x8821
block|,
literal|"CPU/PCI Bridge"
block|}
block|,
block|{
literal|0x8822
block|,
literal|"PCI/ISA Bridge"
block|}
block|,
block|{
literal|0x8851
block|,
literal|"Pentium CPU/PCI Bridge"
block|}
block|,
block|{
literal|0x8852
block|,
literal|"Pentium CPU/ISA Bridge"
block|}
block|,
block|{
literal|0x886a
block|,
literal|"UM8886 ISA Bridge with EIDE"
block|}
block|,
block|{
literal|0x8881
block|,
literal|"UM8881F HB4 486 PCI Chipset"
block|}
block|,
block|{
literal|0x8886
block|,
literal|"UM8886 ISA Bridge"
block|}
block|,
block|{
literal|0x888a
block|,
literal|"UM8886A"
block|}
block|,
block|{
literal|0x8891
block|,
literal|"UM8891 586 Chipset"
block|}
block|,
block|{
literal|0x9017
block|,
literal|"UM9017F Ethernet"
block|}
block|,
block|{
literal|0x9018
block|,
literal|"UM9018 Ethernet"
block|}
block|,
block|{
literal|0x9026
block|,
literal|"UM9026 Fast Ethernet"
block|}
block|,
block|{
literal|0xe881
block|,
literal|"UM8881 486 Chipset"
block|}
block|,
block|{
literal|0xe886
block|,
literal|"UM8886 ISA Bridge w/EIDE"
block|}
block|,
block|{
literal|0xe88a
block|,
literal|"UM8886N"
block|}
block|,
block|{
literal|0xe891
block|,
literal|"UM8891 Pentium Chipset"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1061
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"AGX013/016 GUI Accelerator"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"IIT3204/3501 MPEG Decoder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1066
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"PT80C826 VL Bridge"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"PT86C521 Vesuvius V1-LS System Controller"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"PT86C523 Vesuvius V3-LS ISA Bridge"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"ISA Bridge"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"PC87550 System Controller"
block|}
block|,
block|{
literal|0x8002
block|,
literal|"PT86C523 ISA Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1067
index|[]
init|=
block|{
block|{
literal|0x1002
block|,
literal|"VG500 VolumePro Volume Rendering Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1069
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"DAC960P DAC960P 3 ch SCSI RAID Controller"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"DAC960PD DAC960PD 3 ch SCSI RAID Controller"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"DAC960PJ DAC960PJ 3 ch SCSI RAID Controller"
block|}
block|,
block|{
literal|0x0050
block|,
literal|"i960 AcceleRAID 170"
block|}
block|,
block|{
literal|0xba55
block|,
literal|"1100 eXtremeRAID Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_106b
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Bandit"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"Grand Central"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"Control Video"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"PlanB Video-in"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"OHare I/O"
block|}
block|,
block|{
literal|0x000e
block|,
literal|"Hydra"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"Heathrow Mac I/O"
block|}
block|,
block|{
literal|0x0017
block|,
literal|"Paddington Mac I/O"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_106c
index|[]
init|=
block|{
block|{
literal|0x8801
block|,
literal|"Dual Pentium ISA/PCI Motherboard"
block|}
block|,
block|{
literal|0x8802
block|,
literal|"PowerPC ISA/PCI Motherboard"
block|}
block|,
block|{
literal|0x8803
block|,
literal|"Dual Window Graphics Accelerator"
block|}
block|,
block|{
literal|0x8804
block|,
literal|"PCI LAN Controller"
block|}
block|,
block|{
literal|0x8805
block|,
literal|"100-BaseT LAN Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1073
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"3D graphics Cntrlr"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"YGV615 RPA3 3D-Graphics Controller"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"YMF740"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"YMF724"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"DS1 DS1 Audio"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"DS1 DS1 Audio"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"DS1 DS1 Audio"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"DS1L DS1L Audio"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"YMF740C DS-1L PCI audio controller"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"YMF724F DS-1 PCI audio controller"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"YMF744B DS-1S PCI audio controller"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"YMF754B DS-1S Audio"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"DS-1 Audio"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1074
index|[]
init|=
block|{
block|{
literal|0x4e78
block|,
literal|"82C500/1 Nx586 Chipset"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1077
index|[]
init|=
block|{
block|{
literal|0x1020
block|,
literal|"ISP1020A Fast-wide SCSI"
block|}
block|,
block|{
literal|0x1022
block|,
literal|"ISP1022A Fast-wide SCSI"
block|}
block|,
block|{
literal|0x1080
block|,
literal|"ISP1080 SCSI Host Adapter"
block|}
block|,
block|{
literal|0x1240
block|,
literal|"ISP1240 SCSI Host Adapter"
block|}
block|,
block|{
literal|0x1280
block|,
literal|"ISP1280"
block|}
block|,
block|{
literal|0x2020
block|,
literal|"ISP2020 Fast!SCSI Basic Adapter"
block|}
block|,
block|{
literal|0x2100
block|,
literal|"QLA2100 64-bit Fibre Channel Adapter"
block|}
block|,
block|{
literal|0x2200
block|,
literal|"ISP2200"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1078
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"Cx5520 ISA Bridge"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"MediaGXm MMX Cyrix Integrated CPU"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"Cx5520 ISA Bridge"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"Cx5530 Legacy device"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"Cx5530 SMI"
block|}
block|,
block|{
literal|0x0102
block|,
literal|"Cx5530 IDE"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"Cx5530 Audio"
block|}
block|,
block|{
literal|0x0104
block|,
literal|"Cx5530 Video"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_107d
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"P86C850 Graphic GLU-Logic"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_107e
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"ATM interface card"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"100 vg anylan Cntrlr"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"5526"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"55x6"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"155 MBit ATM controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_107f
index|[]
init|=
block|{
block|{
literal|0x0802
block|,
literal|"SL82C105 EIDE Ctrlr"
block|}
block|,
block|{
literal|0x0803
block|,
literal|"EIDE Bus Master Controller"
block|}
block|,
block|{
literal|0x0806
block|,
literal|"EIDE Controller"
block|}
block|,
block|{
literal|0x2015
block|,
literal|"EIDE Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1080
index|[]
init|=
block|{
block|{
literal|0x0600
block|,
literal|"82C596/9 PCI to VLB Bridge"
block|}
block|,
block|{
literal|0xc691
block|,
literal|"Cypress CY82C691"
block|}
block|,
block|{
literal|0xc693
block|,
literal|"82C693 PCI to ISA Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1081
index|[]
init|=
block|{
block|{
literal|0x0d47
block|,
literal|"PCi to NuBUS Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1083
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"FR710 EIDE Ctrlr"
block|}
block|,
block|{
literal|0x0613
block|,
literal|"Host Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_108a
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Model 617 PCI-VME Bus Adapter"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"Model 618 VME Bridge"
block|}
block|,
block|{
literal|0x3000
block|,
literal|"Model 2106 VME Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_108d
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"OC-3136/37 16/4 PCI Ethernet Adapter"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"OC-3139f Fastload 16/4 PCI/III Token Ring Adapter"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"OC-3139/40 RapidFire Token Ring 16/4 Adapter"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"OC-3250 GoCard Token Ring 16/4 Adapter"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"OC-3530 RapidFire Token Ring 100 Adapter"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"OC-3141 RapidFire Token Ring 16/4 Adapter"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"OC-3540 RapidFire HSTR 100/16/4 Adapter"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"OC-2805 Ethernet Controller"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"OC-2325 Ethernet PCI/II 10/100 Controller"
block|}
block|,
block|{
literal|0x0013
block|,
literal|"OC-2183/85 PCI/II Ethernet Controller"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"OC-2326 Ethernet PCI/II 10/100 Controller"
block|}
block|,
block|{
literal|0x0019
block|,
literal|"OC-2327/50 10/100 Ethernet Controller"
block|}
block|,
block|{
literal|0x0021
block|,
literal|"OC-6151/52 ATM Adapter"
block|}
block|,
block|{
literal|0x0022
block|,
literal|"ATM Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_108e
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"SPARC EBUS"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"EBUS? HME bridge device"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"HME Happy Meal Ethernet"
block|}
block|,
block|{
literal|0x5000
block|,
literal|"Simba PCI Bridge"
block|}
block|,
block|{
literal|0x5043
block|,
literal|"SunPCI Co-processor"
block|}
block|,
block|{
literal|0x8000
block|,
literal|"PCI Bus Module"
block|}
block|,
block|{
literal|0xa000
block|,
literal|"UltraSPARC III PCI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1091
index|[]
init|=
block|{
block|{
literal|0x0020
block|,
literal|"3D Graphics Processor"
block|}
block|,
block|{
literal|0x0021
block|,
literal|"3D graphics processor w/texturing"
block|}
block|,
block|{
literal|0x0040
block|,
literal|"3D graphics frame buffer"
block|}
block|,
block|{
literal|0x0041
block|,
literal|"3D graphics frame buffer"
block|}
block|,
block|{
literal|0x0060
block|,
literal|"Proprietary bus Bridge"
block|}
block|,
block|{
literal|0x00e4
block|,
literal|"Powerstorm 4D50T"
block|}
block|,
block|{
literal|0x0720
block|,
literal|"Motion JPEG Codec"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1092
index|[]
init|=
block|{
block|{
literal|0x00a0
block|,
literal|"SpeedStar Pro SE GUI Accelerator"
block|}
block|,
block|{
literal|0x00a8
block|,
literal|"SpeedStar 64 GUI Accelerator"
block|}
block|,
block|{
literal|0x08d4
block|,
literal|"Supra 2260 Modem"
block|}
block|,
block|{
literal|0x1092
block|,
literal|"Viper V330"
block|}
block|,
block|{
literal|0x6120
block|,
literal|"Maximum DVD"
block|}
block|,
block|{
literal|0x8810
block|,
literal|"Stealth SE GUI Accelerator"
block|}
block|,
block|{
literal|0x8811
block|,
literal|"Stealth 64/SE GUI Accelerator"
block|}
block|,
block|{
literal|0x8880
block|,
literal|"Stealth Video"
block|}
block|,
block|{
literal|0x8881
block|,
literal|"Stealth Video GUI Accelerator"
block|}
block|,
block|{
literal|0x88b0
block|,
literal|"Stealth 64 Video GUI Accelerator"
block|}
block|,
block|{
literal|0x88b1
block|,
literal|"Stealth 64 Video GUI Accelerator"
block|}
block|,
block|{
literal|0x88c0
block|,
literal|"Stealth 64 GUI Accelerator"
block|}
block|,
block|{
literal|0x88c1
block|,
literal|"Stealth 64 GUI Accelerator"
block|}
block|,
block|{
literal|0x88d0
block|,
literal|"Stealth 64 GUI Accelerator"
block|}
block|,
block|{
literal|0x88d1
block|,
literal|"Stealth 64 GUI Accelerator"
block|}
block|,
block|{
literal|0x88f0
block|,
literal|"Stealth 64 Video GUI Accelerator"
block|}
block|,
block|{
literal|0x88f1
block|,
literal|"Stealth 64 Video GUI Accelerator"
block|}
block|,
block|{
literal|0x9999
block|,
literal|"Monster Sound"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1093
index|[]
init|=
block|{
block|{
literal|0x0160
block|,
literal|"PCI-DIO-96"
block|}
block|,
block|{
literal|0x0162
block|,
literal|"PCI-MIO-16XE-50"
block|}
block|,
block|{
literal|0x1170
block|,
literal|"PCI-MIO-16XE-10"
block|}
block|,
block|{
literal|0x1180
block|,
literal|"PCI-MIO-16E-1"
block|}
block|,
block|{
literal|0x1190
block|,
literal|"PCI-MIO-16E-4"
block|}
block|,
block|{
literal|0x1330
block|,
literal|"PCI-6031E"
block|}
block|,
block|{
literal|0x1350
block|,
literal|"PCI-6071E"
block|}
block|,
block|{
literal|0x2a60
block|,
literal|"PCI-6923E"
block|}
block|,
block|{
literal|0xb001
block|,
literal|"IMAQ-PCI-1408"
block|}
block|,
block|{
literal|0xb011
block|,
literal|"IMAQ-PXI-1408"
block|}
block|,
block|{
literal|0xb021
block|,
literal|"IMAQ-PCI-1424"
block|}
block|,
block|{
literal|0xb031
block|,
literal|"IMAQ-PCI-1413"
block|}
block|,
block|{
literal|0xb041
block|,
literal|"IMAQ-PCI-1407"
block|}
block|,
block|{
literal|0xb051
block|,
literal|"IMAQ-PXI-1407"
block|}
block|,
block|{
literal|0xb061
block|,
literal|"IMAQ-PCI-1411"
block|}
block|,
block|{
literal|0xb071
block|,
literal|"IMAQ-PCI-1422"
block|}
block|,
block|{
literal|0xb081
block|,
literal|"IMAQ-PXI-1422"
block|}
block|,
block|{
literal|0xb091
block|,
literal|"IMAQ-PXI-1411"
block|}
block|,
block|{
literal|0xc801
block|,
literal|"PCI-GPIB GPIB Controller Interface Board"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1095
index|[]
init|=
block|{
block|{
literal|0x0640
block|,
literal|"PCI0640A EIDE Ctrlr"
block|}
block|,
block|{
literal|0x0641
block|,
literal|"PCI0640 PCI EIDE Adapter with RAID 1"
block|}
block|,
block|{
literal|0x0642
block|,
literal|"IDE Cntrlr w/RAID 1"
block|}
block|,
block|{
literal|0x0643
block|,
literal|"PCI0643 PCI EIDE controller"
block|}
block|,
block|{
literal|0x0646
block|,
literal|"PCI0646 bus master IDE"
block|}
block|,
block|{
literal|0x0647
block|,
literal|"PCI0647"
block|}
block|,
block|{
literal|0x0648
block|,
literal|"PCI-648 Bus Master Ultra DMA PCI-IDE/ATA Chip"
block|}
block|,
block|{
literal|0x0650
block|,
literal|"PBC0650A Fast SCSI-II Ctrlr"
block|}
block|,
block|{
literal|0x0670
block|,
literal|"USB0670 PCI-USB ASIC"
block|}
block|,
block|{
literal|0x0673
block|,
literal|"USB0673 PCI-USB ASIC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1097
index|[]
init|=
block|{
block|{
literal|0x0038
block|,
literal|"EIDE Controller (single FIFO)"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1098
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"QD8500 EIDE Controller"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"QD8580 EIDE Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_109e
index|[]
init|=
block|{
block|{
literal|0x0350
block|,
literal|"BT848 TV/PCI with DMA Push"
block|}
block|,
block|{
literal|0x0351
block|,
literal|"Bt849 Video Capture"
block|}
block|,
block|{
literal|0x036c
block|,
literal|"Bt879? Video Capture"
block|}
block|,
block|{
literal|0x036e
block|,
literal|"Bt878 MediaStream Controller"
block|}
block|,
block|{
literal|0x036f
block|,
literal|"Bt879 Video Capture"
block|}
block|,
block|{
literal|0x0370
block|,
literal|"Bt880 Video Capture"
block|}
block|,
block|{
literal|0x0878
block|,
literal|"Bt878 Video Capture (Audio Section)"
block|}
block|,
block|{
literal|0x0879
block|,
literal|"Bt879 Video Capture (Audio Section)"
block|}
block|,
block|{
literal|0x0880
block|,
literal|"Bt880 Video Capture (Audio Section)"
block|}
block|,
block|{
literal|0x2115
block|,
literal|"BtV 2115 BtV Mediastream Controller"
block|}
block|,
block|{
literal|0x2125
block|,
literal|"BtV 2125 BtV Mediastream Controller"
block|}
block|,
block|{
literal|0x2164
block|,
literal|"BtV 2164 Display Adapter"
block|}
block|,
block|{
literal|0x2165
block|,
literal|"BtV 2165 MediaStream Controller"
block|}
block|,
block|{
literal|0x8230
block|,
literal|"BtV 8230 ATM Segment/Reassembly Controller (SRC)"
block|}
block|,
block|{
literal|0x8472
block|,
literal|"Bt8472"
block|}
block|,
block|{
literal|0x8474
block|,
literal|"Bt8474"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10a8
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"? 64-bit GUI Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10a9
index|[]
init|=
block|{
block|{
literal|0x0004
block|,
literal|"O2 MACE"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"RAD Audio"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"HPCEX"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"RPCEX"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"DiVO VIP"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"Alteon Gigabit Ethernet"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"AMP Video I/O"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"GRIP"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"SGH PSHAC GSN"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"Magic Carpet"
block|}
block|,
block|{
literal|0x1002
block|,
literal|"Lithium"
block|}
block|,
block|{
literal|0x1003
block|,
literal|"Dual JPEG 1"
block|}
block|,
block|{
literal|0x1004
block|,
literal|"Dual JPEG 2"
block|}
block|,
block|{
literal|0x1005
block|,
literal|"Dual JPEG 3"
block|}
block|,
block|{
literal|0x1006
block|,
literal|"Dual JPEG 4"
block|}
block|,
block|{
literal|0x1007
block|,
literal|"Dual JPEG 5"
block|}
block|,
block|{
literal|0x1008
block|,
literal|"Cesium"
block|}
block|,
block|{
literal|0x2001
block|,
literal|"Fibre Channel"
block|}
block|,
block|{
literal|0x2002
block|,
literal|"ASDE"
block|}
block|,
block|{
literal|0x8001
block|,
literal|"O2 1394"
block|}
block|,
block|{
literal|0x8002
block|,
literal|"G-net NT"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10aa
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"ACC 2056/2188 CPU to PCI Bridge (Pentium)"
block|}
block|,
block|{
literal|0x2051
block|,
literal|"Laptop Chipset CPU Bridge"
block|}
block|,
block|{
literal|0x5842
block|,
literal|"Laptop Chipset ISA Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10ad
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"W83769F EIDE Ctrlr"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"sl82c103 PCI-ide mode 4.5 Cntrlr"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"sl82c105 - bus master PCI-ide mode 4.5 Cntrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10b5
index|[]
init|=
block|{
block|{
literal|0x0480
block|,
literal|"IOP 480 Integrated PowerPC I/O Processor"
block|}
block|,
block|{
literal|0x0960
block|,
literal|"PCI 9080RDK-960 PCI Reference Design Kit for PCI 9080"
block|}
block|,
block|{
literal|0x9030
block|,
literal|"PCI 9030 PCI SMARTarget I/O Accelerator"
block|}
block|,
block|{
literal|0x9036
block|,
literal|"PCI9036 Interface chip"
block|}
block|,
block|{
literal|0x9050
block|,
literal|"PCI 9050 Target PCI Interface Chip"
block|}
block|,
block|{
literal|0x9052
block|,
literal|"PCI 9052 PCI 9052 Target PCI Interface Chip"
block|}
block|,
block|{
literal|0x9054
block|,
literal|"PCI 9054 PCI I/O Accelerator"
block|}
block|,
block|{
literal|0x9060
block|,
literal|"PCI9060xx PCI Bus Master Interface Chip"
block|}
block|,
block|{
literal|0x906d
block|,
literal|"PCI 9060SD PCI Bus Master Interface Chip"
block|}
block|,
block|{
literal|0x906e
block|,
literal|"PCI 9060ES PCI Bus Master Interface Chip"
block|}
block|,
block|{
literal|0x9080
block|,
literal|"PCI 9080 High performance PCI to Local Bus chip"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10b6
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Smart 16/4 Ringnode (PCI1b)"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"Smart 16/4 Ringnode (PCIBM2/CardBus)"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"Smart 16/4 Ringnode"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"Smart 16/4 Ringnode Mk1 (PCIBM1)"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"16/4 CardBus Adapter (Eric 2)"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"Presto PCI"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"Smart 100/16/4 PCi-HS Ringnode"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"Smart 100/16/4 PCI Ringnode"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"16/4 CardBus  Adapter Mk2"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"Collage 25 ATM adapter"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"Collage 155 ATM adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10b7
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"3C985 1000BaseSX Gigabit Etherlink"
block|}
block|,
block|{
literal|0x3390
block|,
literal|"Velocity Token Link Velocity"
block|}
block|,
block|{
literal|0x3590
block|,
literal|"3C359 TokenLink Velocity XL Adapter"
block|}
block|,
block|{
literal|0x5057
block|,
literal|"3C575 Megahertz 10/100 LAN CardBus PC Card"
block|}
block|,
block|{
literal|0x5157
block|,
literal|"3C575 Megahertz 10/100 LAN CardBus PC Card"
block|}
block|,
block|{
literal|0x5900
block|,
literal|"3C590 Ethernet 10bT"
block|}
block|,
block|{
literal|0x5950
block|,
literal|"3C595 Ethernet 100bTX"
block|}
block|,
block|{
literal|0x5951
block|,
literal|"3C595 Ethernet 100bT4"
block|}
block|,
block|{
literal|0x5952
block|,
literal|"3C595 Ethernet 100b-MII"
block|}
block|,
block|{
literal|0x8811
block|,
literal|"Token Ring"
block|}
block|,
block|{
literal|0x9000
block|,
literal|"3C900-TPO Fast Etherlink XL PCI 10"
block|}
block|,
block|{
literal|0x9001
block|,
literal|"3C900-COMBO Fast Etherlink XL PCI 10"
block|}
block|,
block|{
literal|0x9004
block|,
literal|"3C900B-TPO EtherLink XL TPO 10Mb"
block|}
block|,
block|{
literal|0x9005
block|,
literal|"3C900B-COMBO Fast Etherlink XL 10Mb"
block|}
block|,
block|{
literal|0x9006
block|,
literal|"3C900B-TPC EtherLink XL TPC"
block|}
block|,
block|{
literal|0x900a
block|,
literal|"3C900B-FL EtherLink XL FL"
block|}
block|,
block|{
literal|0x9050
block|,
literal|"3C905-TX Fast Etherlink XL PCI 10/100"
block|}
block|,
block|{
literal|0x9051
block|,
literal|"3C905-T4 Fast Etherlink XL 10/100"
block|}
block|,
block|{
literal|0x9055
block|,
literal|"3C905B Fast Etherlink XL 10/100"
block|}
block|,
block|{
literal|0x9058
block|,
literal|"3C905B-COMBO Deluxe EtherLink XL 10/100"
block|}
block|,
block|{
literal|0x905a
block|,
literal|"3C905B-FX Fast EtherLink XL FX 10/100"
block|}
block|,
block|{
literal|0x9200
block|,
literal|"3C905C-TX Fast EtherLink for PC Management NIC"
block|}
block|,
block|{
literal|0x9800
block|,
literal|"3C980-TX Fast EtherLink XL Server Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10b8
index|[]
init|=
block|{
block|{
literal|0x0005
block|,
literal|"83C170QF Fast Ethernet Adapter 100bTX"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"37C665 FDC"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"37C922 FDC"
block|}
block|,
block|{
literal|0xa011
block|,
literal|"83C170QF Fast ethernet controller"
block|}
block|,
block|{
literal|0xb106
block|,
literal|"SMC34C90 CardBus Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10b9
index|[]
init|=
block|{
block|{
literal|0x0111
block|,
literal|"CMI8738/C3DX C-Media Audio Device (OEM)"
block|}
block|,
block|{
literal|0x1435
block|,
literal|"M1435 VL Bridge"
block|}
block|,
block|{
literal|0x1445
block|,
literal|"M1445 VL Bridge w/EIDE"
block|}
block|,
block|{
literal|0x1449
block|,
literal|"M1449 ISA Bridge"
block|}
block|,
block|{
literal|0x1451
block|,
literal|"M1451 Pentium Chipset"
block|}
block|,
block|{
literal|0x1461
block|,
literal|"M1461 P54C Chipset"
block|}
block|,
block|{
literal|0x1489
block|,
literal|"M1489 486 PCI Chipset"
block|}
block|,
block|{
literal|0x1511
block|,
literal|"M1511 Aladdin 2 Host Bridge"
block|}
block|,
block|{
literal|0x1513
block|,
literal|"M1513 Aladdin 2 South Bridge"
block|}
block|,
block|{
literal|0x1521
block|,
literal|"M1521 Alladin III CPU to PCI Bridge"
block|}
block|,
block|{
literal|0x1523
block|,
literal|"M1523 ISA Bridge"
block|}
block|,
block|{
literal|0x1533
block|,
literal|"M1533 PCI South Bridge"
block|}
block|,
block|{
literal|0x1541
block|,
literal|"M1541 Aladdin V AGPset Host Bridge"
block|}
block|,
block|{
literal|0x1543
block|,
literal|"M1543 Aladdin V AGPset South Bridge"
block|}
block|,
block|{
literal|0x3141
block|,
literal|"M3141 GUI Accelerator"
block|}
block|,
block|{
literal|0x3143
block|,
literal|"M3143 GUI Accelerator"
block|}
block|,
block|{
literal|0x3145
block|,
literal|"M3145 GUI Accelerator"
block|}
block|,
block|{
literal|0x3147
block|,
literal|"M3147 GUI Accelerator"
block|}
block|,
block|{
literal|0x3149
block|,
literal|"M3149 GUI Accelerator"
block|}
block|,
block|{
literal|0x3151
block|,
literal|"M3151 GUI Accelerator"
block|}
block|,
block|{
literal|0x3307
block|,
literal|"M3307 MPEG-1 Decoder"
block|}
block|,
block|{
literal|0x3309
block|,
literal|"M3309 MPEG Decoder"
block|}
block|,
block|{
literal|0x5212
block|,
literal|"M4803"
block|}
block|,
block|{
literal|0x5215
block|,
literal|"MS4803 EIDE Ctrlr"
block|}
block|,
block|{
literal|0x5217
block|,
literal|"m5217h I/O (?)"
block|}
block|,
block|{
literal|0x5219
block|,
literal|"m5219 I/O (?)"
block|}
block|,
block|{
literal|0x5225
block|,
literal|"M5225 IDE Controller"
block|}
block|,
block|{
literal|0x5229
block|,
literal|"M1543 Southbridge EIDE Controller"
block|}
block|,
block|{
literal|0x5235
block|,
literal|"M5235 I/O Controller"
block|}
block|,
block|{
literal|0x7101
block|,
literal|"M7101 Power Management Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10bd
index|[]
init|=
block|{
block|{
literal|0x0e34
block|,
literal|"NE34 NE2000 PCI clone"
block|}
block|,
block|{
literal|0x5240
block|,
literal|"IDE Cntrlr"
block|}
block|,
block|{
literal|0x5241
block|,
literal|"PCMCIA Bridge"
block|}
block|,
block|{
literal|0x5242
block|,
literal|"General Purpose Cntrlr"
block|}
block|,
block|{
literal|0x5243
block|,
literal|"Bus Cntrlr"
block|}
block|,
block|{
literal|0x5244
block|,
literal|"FCD Cntrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10c8
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"Graphics Cntrlr"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"NM2093 MagicGraph 128ZV Video Controller"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"NM2160 MagicGraph 128XD"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"NM2200 MagicMedia 256AV"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"NM2360 MagicMedia 256ZX/256M6D"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"NM2380 MagicMedia 256XL+"
block|}
block|,
block|{
literal|0x0025
block|,
literal|"NM2230 MagicMedia 256AV+"
block|}
block|,
block|{
literal|0x0083
block|,
literal|"NM2097 Graphic Controller NeoMagic MagicGraph128ZV+"
block|}
block|,
block|{
literal|0x8005
block|,
literal|"NM2200 MagicMedia 256AV Audio Device"
block|}
block|,
block|{
literal|0x8006
block|,
literal|"NM2360 MagicMedia 256ZX Audio Device"
block|}
block|,
block|{
literal|0x8016
block|,
literal|"NM2380 MagicMedia 256XL+ Audio Device"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10cd
index|[]
init|=
block|{
block|{
literal|0x1100
block|,
literal|"ASC1100 PCI SCSI Host Adapter"
block|}
block|,
block|{
literal|0x1200
block|,
literal|"ASC1200 Fast SCSI-II"
block|}
block|,
block|{
literal|0x1300
block|,
literal|"ASC-3050 ASC-3150"
block|}
block|,
block|{
literal|0x2300
block|,
literal|"ASC2300 PCI Ultra Wide SCSI-2 Host Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10cf
index|[]
init|=
block|{
block|{
literal|0x2001
block|,
literal|"mb86605 Wide SCSI-2"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10d9
index|[]
init|=
block|{
block|{
literal|0x0066
block|,
literal|"MX86101P"
block|}
block|,
block|{
literal|0x0512
block|,
literal|"MX98713 Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0x0531
block|,
literal|"MX98715/725 Single Chip Fast Ethernet NIC Controller"
block|}
block|,
block|{
literal|0x0532
block|,
literal|"MX98723/727 PCI/CardBus Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x8625
block|,
literal|"MX86250"
block|}
block|,
block|{
literal|0x8626
block|,
literal|"MX86251"
block|}
block|,
block|{
literal|0x8627
block|,
literal|"MX86251"
block|}
block|,
block|{
literal|0x8888
block|,
literal|"MX86200"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10da
index|[]
init|=
block|{
block|{
literal|0x0508
block|,
literal|"TC4048 Token Ring"
block|}
block|,
block|{
literal|0x3390
block|,
literal|"Tl3c3x9 Token Ring"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10dc
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"STAR/RD24 SCSI (PMC)"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"ATT 2C15-3 (FPGA) SCI bridge  on PCI 5 Volt card"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"680-1110-150/400 Simple PMC/PCI to S-LINK interface"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"680-1110-200/450 Simple S-LINK to PMC/PCI interface"
block|}
block|,
block|{
literal|0x0021
block|,
literal|"HIPPI destination"
block|}
block|,
block|{
literal|0x0022
block|,
literal|"HIPPI source"
block|}
block|,
block|{
literal|0x10dc
block|,
literal|"ATT 2C15-3 (FPGA)"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10dd
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"3D graphics processor"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10de
index|[]
init|=
block|{
block|{
literal|0x0008
block|,
literal|"NV1 EDGE 3D Accelerator"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"NV1 EDGE 3D Multimedia"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"Mutara V08 (NV2)"
block|}
block|,
block|{
literal|0x0018
block|,
literal|"Riva 128 Riva 128 accelerator"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"Riva TNT AGP"
block|}
block|,
block|{
literal|0x0028
block|,
literal|"Riva TNT2 Riva TNT2"
block|}
block|,
block|{
literal|0x0029
block|,
literal|"Riva TNT2 Ultra"
block|}
block|,
block|{
literal|0x002a
block|,
literal|"Riva TNT2 (NV5)"
block|}
block|,
block|{
literal|0x002b
block|,
literal|"Riva TNT2 (NV5)"
block|}
block|,
block|{
literal|0x002c
block|,
literal|"VANTA"
block|}
block|,
block|{
literal|0x002d
block|,
literal|"Riva TNT2 M64 Riva TNT2 Model 64"
block|}
block|,
block|{
literal|0x002e
block|,
literal|"VANTA (NV6)"
block|}
block|,
block|{
literal|0x002f
block|,
literal|"VANTA (NV6)"
block|}
block|,
block|{
literal|0x00a0
block|,
literal|"RIVA TNT2 Aladdin"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"GeForce 256"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"GeForce 256 DDR"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"GeForce 256 GL Quadro"
block|}
block|,
block|{
literal|0x0110
block|,
literal|"NV11 GeForce 2 MX"
block|}
block|,
block|{
literal|0x0111
block|,
literal|"NV11 DDR"
block|}
block|,
block|{
literal|0x0113
block|,
literal|"NV11 GL"
block|}
block|,
block|{
literal|0x0150
block|,
literal|"NV15 GeForce2 GTS"
block|}
block|,
block|{
literal|0x0151
block|,
literal|"NV15 DDR GeForce2 GTS"
block|}
block|,
block|{
literal|0x0152
block|,
literal|"NV15 Bladerunner GeForce2 GTS"
block|}
block|,
block|{
literal|0x0153
block|,
literal|"NV15 GL Quadro2"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10df
index|[]
init|=
block|{
block|{
literal|0x10df
block|,
literal|"Light Pulse Fibre Channel Adapter"
block|}
block|,
block|{
literal|0x1ae5
block|,
literal|"LP6000 Fibre Channel Host Adapter"
block|}
block|,
block|{
literal|0xf700
block|,
literal|"LP7000 Fibre Channel Host Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10e0
index|[]
init|=
block|{
block|{
literal|0x5026
block|,
literal|"IMS5026/27/28 VL Bridge"
block|}
block|,
block|{
literal|0x5027
block|,
literal|"IMS5027"
block|}
block|,
block|{
literal|0x5028
block|,
literal|"IMS5028 ISA Bridge"
block|}
block|,
block|{
literal|0x8849
block|,
literal|"IMS8849/48 VL Bridge"
block|}
block|,
block|{
literal|0x8853
block|,
literal|"IMS8853 ATM Network Adapter"
block|}
block|,
block|{
literal|0x9128
block|,
literal|"IMS9129 GUI Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10e1
index|[]
init|=
block|{
block|{
literal|0x0391
block|,
literal|"TRM-S1040"
block|}
block|,
block|{
literal|0x690c
block|,
literal|"DC-690c"
block|}
block|,
block|{
literal|0xdc20
block|,
literal|"DC-290 EIDE Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10e3
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"CA91C042 VMEbus Bridge"
block|}
block|,
block|{
literal|0x0860
block|,
literal|"CA91C860 Motorola Processor Bridge"
block|}
block|,
block|{
literal|0x0862
block|,
literal|"CA91L826A PCI to Motorola Processor Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10e8
index|[]
init|=
block|{
block|{
literal|0x2011
block|,
literal|"Q-Motion Video Capture/Edit board"
block|}
block|,
block|{
literal|0x4750
block|,
literal|"S5933 PCI Ctrlr"
block|}
block|,
block|{
literal|0x5920
block|,
literal|"S5920 32-Bit PCI Bus Target Interface"
block|}
block|,
block|{
literal|0x8033
block|,
literal|"BBK-PCI light Transputer Link Interface"
block|}
block|,
block|{
literal|0x8043
block|,
literal|"LANai4.x Myrinet LANai interface chip"
block|}
block|,
block|{
literal|0x8062
block|,
literal|"S5933 Parastation"
block|}
block|,
block|{
literal|0x807d
block|,
literal|"S5933 PCI44"
block|}
block|,
block|{
literal|0x8088
block|,
literal|"FS Kingsberg Spacetec Format Synchronizer"
block|}
block|,
block|{
literal|0x8089
block|,
literal|"SOB Kingsberg Spacetec Serial Output Board"
block|}
block|,
block|{
literal|0x809c
block|,
literal|"S5933 Traquair HEPC3"
block|}
block|,
block|{
literal|0x80d7
block|,
literal|"PCI-9112"
block|}
block|,
block|{
literal|0x80d9
block|,
literal|"PCI-9118"
block|}
block|,
block|{
literal|0x811a
block|,
literal|"PCI-DSlink PCI-IEEE1355-DS-DE interface"
block|}
block|,
block|{
literal|0x8170
block|,
literal|"S5933 Matchmaker PCI Chipset Development Tool"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10ea
index|[]
init|=
block|{
block|{
literal|0x1680
block|,
literal|"IGA-1680"
block|}
block|,
block|{
literal|0x1682
block|,
literal|"IGA-1682"
block|}
block|,
block|{
literal|0x1683
block|,
literal|"IGA-1683"
block|}
block|,
block|{
literal|0x2000
block|,
literal|"CyberPro 2000"
block|}
block|,
block|{
literal|0x2010
block|,
literal|"CyperPro 2000A"
block|}
block|,
block|{
literal|0x5000
block|,
literal|"CyberPro 5000"
block|}
block|,
block|{
literal|0x5050
block|,
literal|"CyberPro 5050"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10eb
index|[]
init|=
block|{
block|{
literal|0x0101
block|,
literal|"3GA 64 bit graphics processor"
block|}
block|,
block|{
literal|0x8111
block|,
literal|"Twist3 Frame Grabber"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10ec
index|[]
init|=
block|{
block|{
literal|0x8029
block|,
literal|"RTL8029 NE2000 compatible Ethernet"
block|}
block|,
block|{
literal|0x8129
block|,
literal|"RTL8129 10/100 Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x8138
block|,
literal|"RT8139B/C CardBus Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10ed
index|[]
init|=
block|{
block|{
literal|0x7310
block|,
literal|"V7310 VGA Video Overlay Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10ee
index|[]
init|=
block|{
block|{
literal|0x3fc0
block|,
literal|"RME Digi96"
block|}
block|,
block|{
literal|0x3fc1
block|,
literal|"RME Digi96/8"
block|}
block|,
block|{
literal|0x3fc2
block|,
literal|"RME Digi 96/8 Pro"
block|}
block|,
block|{
literal|0x3fc3
block|,
literal|"RME Digi96/8 Pad"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10ef
index|[]
init|=
block|{
block|{
literal|0x8154
block|,
literal|"M815x Token Ring Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10f0
index|[]
init|=
block|{
block|{
literal|0xa800
block|,
literal|"VCL-P Graphics board"
block|}
block|,
block|{
literal|0xb300
block|,
literal|"VCL-M graphics board"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10f1
index|[]
init|=
block|{
block|{
literal|0x1566
block|,
literal|"IDE/SCSI"
block|}
block|,
block|{
literal|0x1677
block|,
literal|"Multimedia"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10f5
index|[]
init|=
block|{
block|{
literal|0xa001
block|,
literal|"NDR4000 NR4600 Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_10fa
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"Targa 1000 Video Capture& Editing card"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x000e
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x000f
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0013
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x0015
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1101
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"Ultra SCSI Adapter"
block|}
block|,
block|{
literal|0x1060
block|,
literal|"INI-A100U2W Ultra-2 SCSI Controller"
block|}
block|,
block|{
literal|0x134a
block|,
literal|"Ultra SCSI Adapter"
block|}
block|,
block|{
literal|0x9100
block|,
literal|"INI-9010/9010W Fast Wide SCSI Controller"
block|}
block|,
block|{
literal|0x9400
block|,
literal|"INI-940 Fast Wide SCSI Controller"
block|}
block|,
block|{
literal|0x9401
block|,
literal|"INI-950 Fast Wide SCSI Controller"
block|}
block|,
block|{
literal|0x9500
block|,
literal|"INI-9100U/UW SCSI Controller"
block|}
block|,
block|{
literal|0x9700
block|,
literal|"Fast Wide SCSI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1102
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"EMU10000 Sound Blaster Live!"
block|}
block|,
block|{
literal|0x1017
block|,
literal|"Banshee 3D Blaster Banshee PCI CT6760"
block|}
block|,
block|{
literal|0x1047
block|,
literal|"3D Blaster Annihilator 2"
block|}
block|,
block|{
literal|0x7002
block|,
literal|"EMU10000 Game Port"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1103
index|[]
init|=
block|{
block|{
literal|0x0003
block|,
literal|"HPT343/345 UDMA EIDE Controller"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"HPT366 UDMA66 EIDE Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1105
index|[]
init|=
block|{
block|{
literal|0x5000
block|,
literal|"Multimedia"
block|}
block|,
block|{
literal|0x8300
block|,
literal|"VM491 DVD/MPEG-2 accelerator"
block|}
block|,
block|{
literal|0x8400
block|,
literal|"EM8400 MPEG-2 Decoder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1106
index|[]
init|=
block|{
block|{
literal|0x0305
block|,
literal|"VT8363 Host Bus-PCI Bridge"
block|}
block|,
block|{
literal|0x0391
block|,
literal|"VT8371 KX133 Athlon Chipset Host Bridge"
block|}
block|,
block|{
literal|0x0501
block|,
literal|"VT8501 MVP4 System Controller"
block|}
block|,
block|{
literal|0x0505
block|,
literal|"82C505 VL Bridge"
block|}
block|,
block|{
literal|0x0561
block|,
literal|"82C561 IDE"
block|}
block|,
block|{
literal|0x0571
block|,
literal|"VT82C586/686 PCI IDE Controller"
block|}
block|,
block|{
literal|0x0576
block|,
literal|"82C576 P54 Ctrlr"
block|}
block|,
block|{
literal|0x0585
block|,
literal|"VT82C585VP Host Bus-PCI Bridge"
block|}
block|,
block|{
literal|0x0586
block|,
literal|"VT82C586VP PCI-to-ISA Bridge"
block|}
block|,
block|{
literal|0x0595
block|,
literal|"VT82C595 Apollo VP2 PCI North Bridge"
block|}
block|,
block|{
literal|0x0596
block|,
literal|"VT82C596 PCI ISA Bridge"
block|}
block|,
block|{
literal|0x0597
block|,
literal|"VT82C597 Host Bridge (Apollo VP3)"
block|}
block|,
block|{
literal|0x0598
block|,
literal|"VT82C598 Apollo MVP3/Pro133A Host Bridge"
block|}
block|,
block|{
literal|0x0601
block|,
literal|"VT8601"
block|}
block|,
block|{
literal|0x0680
block|,
literal|"VT82C680 Apollo P6"
block|}
block|,
block|{
literal|0x0686
block|,
literal|"VT82C686 PCI-to-ISA bridge"
block|}
block|,
block|{
literal|0x0691
block|,
literal|"VT82C691/693A/694 Apollo Pro/133/133A System Controller"
block|}
block|,
block|{
literal|0x0693
block|,
literal|"VT82C693 Apollo Pro+ Host Bridge"
block|}
block|,
block|{
literal|0x0926
block|,
literal|"VT86C926 Amazon PCI Ethernet Controller"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"82C570MV P54 Ctrlr"
block|}
block|,
block|{
literal|0x1106
block|,
literal|"82C570MV ISA Bridge w/IDE"
block|}
block|,
block|{
literal|0x1571
block|,
literal|"VT82C416 IDE Controller"
block|}
block|,
block|{
literal|0x1595
block|,
literal|"VT82C595 VP2, VP2/97 System Controller"
block|}
block|,
block|{
literal|0x3038
block|,
literal|"VT83C572 PCI USB Controller"
block|}
block|,
block|{
literal|0x3040
block|,
literal|"VT83C572 Power Management Controller"
block|}
block|,
block|{
literal|0x3043
block|,
literal|"VT86C100A Rhine 10/100 Ethernet Adapter"
block|}
block|,
block|{
literal|0x3044
block|,
literal|"OHCI Compliant IEEE 1394 Host Ctrlr"
block|}
block|,
block|{
literal|0x3050
block|,
literal|"VT82C596 Power Management Controller"
block|}
block|,
block|{
literal|0x3051
block|,
literal|"Power Management Controller"
block|}
block|,
block|{
literal|0x3057
block|,
literal|"VT82C686A ACPI Power Management Controller"
block|}
block|,
block|{
literal|0x3058
block|,
literal|"VT82C686 Audio Codec 97"
block|}
block|,
block|{
literal|0x3068
block|,
literal|"VT82C686 Modem Codec 97"
block|}
block|,
block|{
literal|0x3086
block|,
literal|"VT82C686 Power management"
block|}
block|,
block|{
literal|0x5030
block|,
literal|"VT82C596 Apollo Pro ACPI Power Management Ctrlr"
block|}
block|,
block|{
literal|0x6100
block|,
literal|"VT86C100A PCI Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x8231
block|,
literal|"VT8231 PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x8305
block|,
literal|"VT8363 PCI to AGP Bridge"
block|}
block|,
block|{
literal|0x8391
block|,
literal|"VT8371 PCI to AGP Bridge"
block|}
block|,
block|{
literal|0x8501
block|,
literal|"CPU to AGP Controller?"
block|}
block|,
block|{
literal|0x8596
block|,
literal|"VT82C596 PCI to AGP Bridge"
block|}
block|,
block|{
literal|0x8597
block|,
literal|"VT82C597 PCI-to-PCI Bridge (AGP)"
block|}
block|,
block|{
literal|0x8598
block|,
literal|"VT82C598/686A Apollo MVP3 PCI-to-PCI Bridge"
block|}
block|,
block|{
literal|0x8601
block|,
literal|"PCI to AGP Controller?"
block|}
block|,
block|{
literal|0x8691
block|,
literal|"VT82C691 Apollo Pro PCI-to-PCI Bridge"
block|}
block|,
block|{
literal|0x8693
block|,
literal|"VT82C693 Apollo Pro+ PCI-to-PCI Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1107
index|[]
init|=
block|{
block|{
literal|0x8576
block|,
literal|"PCI Host Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1108
index|[]
init|=
block|{
block|{
literal|0x0100
block|,
literal|"p1690plus-AA Token Ring Adapter"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"p1690plus-AB 2-Port Token Ring Adapter"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"P1690Plus Token Ring Adapter"
block|}
block|,
block|{
literal|0x0108
block|,
literal|"P1690Plus Token Ring Adapter"
block|}
block|,
block|{
literal|0x0138
block|,
literal|"P1690Plus Token Ring Adapter"
block|}
block|,
block|{
literal|0x0139
block|,
literal|"P1690Plus Token Ring Adapter"
block|}
block|,
block|{
literal|0x013c
block|,
literal|"P1690Plus Token Ring Adapter"
block|}
block|,
block|{
literal|0x013d
block|,
literal|"P1690Plus Token Ring Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1109
index|[]
init|=
block|{
block|{
literal|0x1400
block|,
literal|"EM110TX EX110TX PCI Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_110a
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"Piranha PCI-EIDE Adapter (2-port)"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"Tulip-Ctrlr, Power-Mgmt, Switch Extender"
block|}
block|,
block|{
literal|0x113c
block|,
literal|"FPGA-CPTR Hardware Tracer for CP113C / CP113D"
block|}
block|,
block|{
literal|0x113e
block|,
literal|"FPGA-CPTRE Hardware Tracer for CP113E"
block|}
block|,
block|{
literal|0x2102
block|,
literal|"PEB/PEF 20534 DSCC4 Multiprotocol HDLC Controller"
block|}
block|,
block|{
literal|0x3160
block|,
literal|"MCCA Pentium-PCI Host Bridge Core ASIC"
block|}
block|,
block|{
literal|0x4942
block|,
literal|"FPGA-IBTR I-Bus Tracer for MBD"
block|}
block|,
block|{
literal|0x6120
block|,
literal|"SZB6120 Multimedia Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_110b
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Mpact Media Processor"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1110
index|[]
init|=
block|{
block|{
literal|0x6037
block|,
literal|"Firepower Powerized SMP I/O ASIC"
block|}
block|,
block|{
literal|0x6073
block|,
literal|"Firepower Powerized SMP I/O ASIC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1112
index|[]
init|=
block|{
block|{
literal|0x2200
block|,
literal|"FDDI adapter"
block|}
block|,
block|{
literal|0x2300
block|,
literal|"fast ethernet adapter"
block|}
block|,
block|{
literal|0x2340
block|,
literal|"4 Port FEN Adapter 4 10/100 UTP Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0x2400
block|,
literal|"ATM adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1113
index|[]
init|=
block|{
block|{
literal|0x1211
block|,
literal|"EN-1207D Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0x1217
block|,
literal|"EN-1217 Ethernet Adapter"
block|}
block|,
block|{
literal|0x9211
block|,
literal|"EN-1207D Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1116
index|[]
init|=
block|{
block|{
literal|0x0022
block|,
literal|"DT3001"
block|}
block|,
block|{
literal|0x0023
block|,
literal|"DT3002"
block|}
block|,
block|{
literal|0x0024
block|,
literal|"DT3003"
block|}
block|,
block|{
literal|0x0025
block|,
literal|"DT3004"
block|}
block|,
block|{
literal|0x0026
block|,
literal|"Dt3005"
block|}
block|,
block|{
literal|0x0027
block|,
literal|"DT3001-PGL"
block|}
block|,
block|{
literal|0x0028
block|,
literal|"DT3003-PGL"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1117
index|[]
init|=
block|{
block|{
literal|0x9500
block|,
literal|"max-lc SVGA card"
block|}
block|,
block|{
literal|0x9501
block|,
literal|"MaxPCI image processing board"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1119
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"GDT6000/6020/6050 SCSI RAID"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"GDT6000/6010 SCSI RAID"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"GDT6110/6510 SCSI RAID"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"GDT6120/6520 2-chan SCSI RAID"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"GDT6530 3-chan SCSI RAID"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"GDT6550 5-chan SCSI RAID"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"GDT6117/6517"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"GDT6127/6527"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"GDT6537"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"GDT6557"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"GDT6115/6515"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"GDT6125/6525"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"GDT6535"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"GDT6555"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"GDT6117RP/6517 2 Channel SCSI"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"GDT6127RP/6527RP"
block|}
block|,
block|{
literal|0x0102
block|,
literal|"GDT6537RP"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"GDT6557RP"
block|}
block|,
block|{
literal|0x0104
block|,
literal|"GDT6111RP/6511RP"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"GDT6127RP/6527RP"
block|}
block|,
block|{
literal|0x0110
block|,
literal|"GDT6117RP1/6517RP1"
block|}
block|,
block|{
literal|0x0111
block|,
literal|"GDT6127RP1/6527RP1"
block|}
block|,
block|{
literal|0x0112
block|,
literal|"GDT6537RP1"
block|}
block|,
block|{
literal|0x0113
block|,
literal|"GDT6557RP1"
block|}
block|,
block|{
literal|0x0114
block|,
literal|"GDT6111RP1/6511RP1"
block|}
block|,
block|{
literal|0x0115
block|,
literal|"GDT6127RP1/6527RP1"
block|}
block|,
block|{
literal|0x0118
block|,
literal|"GDT 6x18RD"
block|}
block|,
block|{
literal|0x0119
block|,
literal|"GDT 6x28RD"
block|}
block|,
block|{
literal|0x011a
block|,
literal|"GDT 6x38RD"
block|}
block|,
block|{
literal|0x011b
block|,
literal|"GDT 6x58RD"
block|}
block|,
block|{
literal|0x0120
block|,
literal|"GDT6117RP2/6517RP2"
block|}
block|,
block|{
literal|0x0121
block|,
literal|"GDT6127RP2/6527RP2"
block|}
block|,
block|{
literal|0x0122
block|,
literal|"GDT6537RP2"
block|}
block|,
block|{
literal|0x0123
block|,
literal|"GDT6557RP2"
block|}
block|,
block|{
literal|0x0124
block|,
literal|"GDT6111RP2/6511RP2"
block|}
block|,
block|{
literal|0x0125
block|,
literal|"GDT6127RP2/6527RP2"
block|}
block|,
block|{
literal|0x0168
block|,
literal|"GDT 7x18RN"
block|}
block|,
block|{
literal|0x0169
block|,
literal|"GDT 7x28RN"
block|}
block|,
block|{
literal|0x016a
block|,
literal|"GST 7x38RN"
block|}
block|,
block|{
literal|0x016b
block|,
literal|"GDT 7x58RN"
block|}
block|,
block|{
literal|0x0210
block|,
literal|"GDT 6x19RD"
block|}
block|,
block|{
literal|0x0211
block|,
literal|"GDT 6x29RD"
block|}
block|,
block|{
literal|0x0260
block|,
literal|"GDT 7x19RN"
block|}
block|,
block|{
literal|0x0261
block|,
literal|"GDT 7x29RN"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_111a
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"155P-MF1"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"166P-MF1"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"ENI-25P ATM Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_111c
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Powerbus Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_111d
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"IDT77211 ATM Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_111f
index|[]
init|=
block|{
block|{
literal|0x4a47
block|,
literal|"Precision MX Video engine interface"
block|}
block|,
block|{
literal|0x5243
block|,
literal|"Frame Capture Bus Interface"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1127
index|[]
init|=
block|{
block|{
literal|0x0200
block|,
literal|"FireRunner PCA-200 ATM"
block|}
block|,
block|{
literal|0x0210
block|,
literal|"PCA-200PC ATM"
block|}
block|,
block|{
literal|0x0250
block|,
literal|"ATM"
block|}
block|,
block|{
literal|0x0300
block|,
literal|"PCA-200EPC ATM"
block|}
block|,
block|{
literal|0x0310
block|,
literal|"ATM"
block|}
block|,
block|{
literal|0x0400
block|,
literal|"ForeRunner HE ATM Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_112e
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"EIDE/hdd and IDE/cd-rom Ctrlr"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"EIDE/hdd and IDE/cd-rom Ctrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_112f
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"ICPCI"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"video frame grabber/processor"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1131
index|[]
init|=
block|{
block|{
literal|0x2780
block|,
literal|"tda 2780 AQ Tv deflection"
block|}
block|,
block|{
literal|0x5400
block|,
literal|"TM100 TriMedia"
block|}
block|,
block|{
literal|0x7145
block|,
literal|"SAA7145"
block|}
block|,
block|{
literal|0x7146
block|,
literal|"SAA7146 Multi Media Bridge Scaler"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1133
index|[]
init|=
block|{
block|{
literal|0x7901
block|,
literal|"EiconCard S90"
block|}
block|,
block|{
literal|0xe001
block|,
literal|"DIVA Pro 2.0 S/T"
block|}
block|,
block|{
literal|0xe002
block|,
literal|"DIVA 2.0 S/T"
block|}
block|,
block|{
literal|0xe003
block|,
literal|"DIVA Pro 2.0 U"
block|}
block|,
block|{
literal|0xe004
block|,
literal|"DIVA 2.0 U"
block|}
block|,
block|{
literal|0xe005
block|,
literal|"DIVA 2.01 S/T Eicon ISDN card using Siemens IPAC chip"
block|}
block|,
block|{
literal|0xe010
block|,
literal|"DIVA Server BRI-2M"
block|}
block|,
block|{
literal|0xe014
block|,
literal|"DIVA Server PRI-30M"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1134
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Raceway Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1135
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Printer Cntrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1138
index|[]
init|=
block|{
block|{
literal|0x8905
block|,
literal|"8905 STD 32 Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_113c
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"PCI9060 i960 Bridge"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"PCI9060 i960 Bridge / Evaluation Platform"
block|}
block|,
block|{
literal|0x0911
block|,
literal|"PCI911 i960Jx I/O Controller"
block|}
block|,
block|{
literal|0x0912
block|,
literal|"PCI912 i960Cx I/O Controller"
block|}
block|,
block|{
literal|0x0913
block|,
literal|"PCI913 i960Hx I/O Controller"
block|}
block|,
block|{
literal|0x0914
block|,
literal|"PCI914 I/O Controller with secondary PCI bus"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_113f
index|[]
init|=
block|{
block|{
literal|0x0808
block|,
literal|"SST-64P Adapter"
block|}
block|,
block|{
literal|0x1010
block|,
literal|"SST-128P Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1141
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"EIDE/ATAPI super adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1142
index|[]
init|=
block|{
block|{
literal|0x3210
block|,
literal|"ProMotion 3210 VGA/AVI Playback Accelerator"
block|}
block|,
block|{
literal|0x6410
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x6412
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x6420
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x6422
block|,
literal|"Provideo 6422"
block|}
block|,
block|{
literal|0x6424
block|,
literal|"ProVideo 6424 GUI Accelerator"
block|}
block|,
block|{
literal|0x6425
block|,
literal|"ProMotion AT25"
block|}
block|,
block|{
literal|0x6426
block|,
literal|"GUI Accelerator"
block|}
block|,
block|{
literal|0x643d
block|,
literal|"AT25 ProMotion-AT3D"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1144
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Noservo Cntrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1148
index|[]
init|=
block|{
block|{
literal|0x4000
block|,
literal|"FDDI adapter"
block|}
block|,
block|{
literal|0x4200
block|,
literal|"Token Ring"
block|}
block|,
block|{
literal|0x4300
block|,
literal|"SK-984x SK-NET Gigabit Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_114a
index|[]
init|=
block|{
block|{
literal|0x7587
block|,
literal|"VMIVME-7587"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_114f
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"AccelePort EPC"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"RightSwitch SE-6"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"AccelePort Xem"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"AccelePort Xr"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"AccelePort C/X"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"AccelePort Xr/J"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"AccelePort EPC/J"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"DataFirePRIme T1"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"SyncPort X.25/FR 2-port"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"AccelePort8r EIA-232"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"AccelePort8r EIA-422"
block|}
block|,
block|{
literal|0x0013
block|,
literal|"AccelePort Xr"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"AccelePort8r EIA-422"
block|}
block|,
block|{
literal|0x0015
block|,
literal|"AccelePort Xem"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"AccelePort EPC/X"
block|}
block|,
block|{
literal|0x0017
block|,
literal|"AccelePort C/X"
block|}
block|,
block|{
literal|0x001a
block|,
literal|"DataFirePRIme E1"
block|}
block|,
block|{
literal|0x001b
block|,
literal|"AccelePort C/X (IBM)"
block|}
block|,
block|{
literal|0x001d
block|,
literal|"DataFire RAS T1/E1/PRI"
block|}
block|,
block|{
literal|0x0023
block|,
literal|"AccelePort RAS"
block|}
block|,
block|{
literal|0x0024
block|,
literal|"DataFire RAS B4 ST/U"
block|}
block|,
block|{
literal|0x0026
block|,
literal|"AccelePort 4r 920"
block|}
block|,
block|{
literal|0x0027
block|,
literal|"AccelePort 8r 920"
block|}
block|,
block|{
literal|0x0034
block|,
literal|"AccelePort 2r 920"
block|}
block|,
block|{
literal|0x0035
block|,
literal|"DataFire DSP T1/E1/PRI, Compact PCI"
block|}
block|,
block|{
literal|0x6001
block|,
literal|"Avanstar"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1155
index|[]
init|=
block|{
block|{
literal|0x0810
block|,
literal|"486 CPU/PCI Bridge"
block|}
block|,
block|{
literal|0x0922
block|,
literal|"Pentium CPU/PCI Bridge"
block|}
block|,
block|{
literal|0x0926
block|,
literal|"PCI/ISA Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1158
index|[]
init|=
block|{
block|{
literal|0x3011
block|,
literal|"Tokenet/vg 1001/10m anylan"
block|}
block|,
block|{
literal|0x9050
block|,
literal|"Lanfleet/Truevalue"
block|}
block|,
block|{
literal|0x9051
block|,
literal|"Lanfleet/Truevalue"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1159
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"MV1000"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"MV-1500 Frame Grabber"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_115d
index|[]
init|=
block|{
block|{
literal|0x0003
block|,
literal|"CardBus Ethernet 10/100"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"CardBus Ethernet 10/100"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"CardBus Ethernet 10/100"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"CardBus Ethernet 10/100"
block|}
block|,
block|{
literal|0x000f
block|,
literal|"CardBus Ethernet 10/100"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"CardBus 56k Modem"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"CardBus Ehternet + 56k Modem"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1161
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Host Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1163
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Verite 1000 3D Blaster"
block|}
block|,
block|{
literal|0x2000
block|,
literal|"Verite 2000"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1165
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Motion JPEG rec/play w/audio"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1166
index|[]
init|=
block|{
block|{
literal|0x0005
block|,
literal|"PCI Host Bridge (Southbridge copy)"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"CNB20-LE CPU to PCI Bridge"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"CNB20HE"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_116a
index|[]
init|=
block|{
block|{
literal|0x6100
block|,
literal|"Bus/Tag Channel"
block|}
block|,
block|{
literal|0x6800
block|,
literal|"Escon Channel"
block|}
block|,
block|{
literal|0x7100
block|,
literal|"Bus/Tag Channel"
block|}
block|,
block|{
literal|0x7800
block|,
literal|"Escon Channel"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1178
index|[]
init|=
block|{
block|{
literal|0xafa1
block|,
literal|"Fast Ethernet"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1179
index|[]
init|=
block|{
block|{
literal|0x0406
block|,
literal|"Tecra Video Capture device"
block|}
block|,
block|{
literal|0x0601
block|,
literal|"Toshiba CPU to PCI bridge"
block|}
block|,
block|{
literal|0x0602
block|,
literal|"PCI to ISA Bridge for Notebooks"
block|}
block|,
block|{
literal|0x0603
block|,
literal|"ToPIC95 PCI to CardBus Bridge for Notebooks"
block|}
block|,
block|{
literal|0x0604
block|,
literal|"PCI to PCI Bridge for Notebooks"
block|}
block|,
block|{
literal|0x0605
block|,
literal|"PCI to ISA Bridge for Notebooks"
block|}
block|,
block|{
literal|0x0606
block|,
literal|"PCI to ISA Bridge for Notebooks"
block|}
block|,
block|{
literal|0x0609
block|,
literal|"PCI to PCI Bridge for Notebooks"
block|}
block|,
block|{
literal|0x060a
block|,
literal|"Toshiba ToPIC95 CardBus Controller"
block|}
block|,
block|{
literal|0x060f
block|,
literal|"ToPIC97 CardBus Controller"
block|}
block|,
block|{
literal|0x0611
block|,
literal|"PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x0617
block|,
literal|"ToPIC95 PCI to CardBus Bridge with ZV support"
block|}
block|,
block|{
literal|0x0618
block|,
literal|"CPU to PCI and PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x0701
block|,
literal|"PCI Communication Device"
block|}
block|,
block|{
literal|0x0d01
block|,
literal|"FIR Port Type-DO"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_117e
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Printer Host"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1180
index|[]
init|=
block|{
block|{
literal|0x0465
block|,
literal|"RL5C465 CardBus controller"
block|}
block|,
block|{
literal|0x0466
block|,
literal|"RL5C466 CardBus controller"
block|}
block|,
block|{
literal|0x0475
block|,
literal|"RL5C475 CardBus controller"
block|}
block|,
block|{
literal|0x0476
block|,
literal|"RL5C476 CardBus controller"
block|}
block|,
block|{
literal|0x0477
block|,
literal|"RLc477 CardBus Controller"
block|}
block|,
block|{
literal|0x0478
block|,
literal|"RLc478 CardBus Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1185
index|[]
init|=
block|{
block|{
literal|0x8929
block|,
literal|"EIDE Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1186
index|[]
init|=
block|{
block|{
literal|0x0100
block|,
literal|"DC21041 Ethernet Adapter"
block|}
block|,
block|{
literal|0x1100
block|,
literal|"Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1189
index|[]
init|=
block|{
block|{
literal|0x1592
block|,
literal|"VL/PCI Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_118c
index|[]
init|=
block|{
block|{
literal|0x0014
block|,
literal|"PCIB C-bus II to PCI bus host bridge chip"
block|}
block|,
block|{
literal|0x1117
block|,
literal|"MAC-94C201B3 Corollary/Intel Memory Controller Chip"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_118d
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"n/a Raptor-PCI framegrabber"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"Model 12 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"Model 14 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0024
block|,
literal|"Model 24 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0044
block|,
literal|"Model 44 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0112
block|,
literal|"Model 12 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0114
block|,
literal|"Model 14 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0124
block|,
literal|"Model 24 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0144
block|,
literal|"Model 44 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0212
block|,
literal|"Model 12 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0214
block|,
literal|"Model 14 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0224
block|,
literal|"Model 24 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0244
block|,
literal|"Model 44 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0312
block|,
literal|"Model 12 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0314
block|,
literal|"Model 14 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0324
block|,
literal|"Model 24 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0x0344
block|,
literal|"Model 44 Road Runner Frame Grabber"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1190
index|[]
init|=
block|{
block|{
literal|0x2550
block|,
literal|"TC-2550 Single Chip Ultra (Wide) SCSI Processor"
block|}
block|,
block|{
literal|0xc721
block|,
literal|"EIDE"
block|}
block|,
block|{
literal|0xc731
block|,
literal|"TP-910/920/940 PCI Ultra (Wide) SCSI Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1191
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"IDE Ctrlr"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"ATP850UF UltraDMA33 EIDE Controller (AEC6210UF)"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"SCSI-2 cache Cntrlr"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"atp8400a ASIC cache controller"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"ATP850UF UltraDMA33 EIDE Controller (AEC6210UF)"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"ATP860A UltraDMA66 EDIE Controller (AEC6260)"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"ATP860A UltraDMA66 EIDE Controller (AEC6260)"
block|}
block|,
block|{
literal|0x8001
block|,
literal|"ATP8600 SCSI-2 RAID (cache?) Adapter (AEC6820U)"
block|}
block|,
block|{
literal|0x8002
block|,
literal|"ATP850S SCSI-2 Host Adapter (AEC6710L/F)"
block|}
block|,
block|{
literal|0x8010
block|,
literal|"ATP870 Ultra Wide SCSI Controller"
block|}
block|,
block|{
literal|0x8020
block|,
literal|"ATP870 Ultra SCSI Controller"
block|}
block|,
block|{
literal|0x8030
block|,
literal|"ATP870 Ultra SCSI Controller"
block|}
block|,
block|{
literal|0x8040
block|,
literal|"ATP870 SCSI Controller"
block|}
block|,
block|{
literal|0x8050
block|,
literal|"Ultra Wide SCSI Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1193
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"1221"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"1225"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1199
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"IRMA 3270 PCI Adapter"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"Advanced ISCA PCI Adapter"
block|}
block|,
block|{
literal|0x0201
block|,
literal|"SDLC PCI Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_119b
index|[]
init|=
block|{
block|{
literal|0x1221
block|,
literal|"82C092G"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11a9
index|[]
init|=
block|{
block|{
literal|0x4240
block|,
literal|"AMCC S5933Q Intelligent Serial Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11ab
index|[]
init|=
block|{
block|{
literal|0x0146
block|,
literal|"GT-64010 System ctrlr w/PCI for R46xx CPU"
block|}
block|,
block|{
literal|0x4801
block|,
literal|"GT-48001 8 port switched ethernet ctrlr"
block|}
block|,
block|{
literal|0x4809
block|,
literal|"EV-48300 Evaluation board for the GT-48300"
block|}
block|,
block|{
literal|0xf003
block|,
literal|"GT-64010 Primary Image Piranha Image Generator"
block|}
block|,
block|{
literal|0xf004
block|,
literal|"GT64120 Primary Image Barracuda Image Generator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11ad
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"NGMC169B 10/100 Ethernet (NetGear FA310TX)"
block|}
block|,
block|{
literal|0xc115
block|,
literal|"LC82C115 PNIC II 10/100 PCI MAC/PHY"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11ae
index|[]
init|=
block|{
block|{
literal|0x4153
block|,
literal|"Bridge Controller"
block|}
block|,
block|{
literal|0x5842
block|,
literal|"Bridge Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11b0
index|[]
init|=
block|{
block|{
literal|0x0292
block|,
literal|"V292PBC Am29030/40 Bridge"
block|}
block|,
block|{
literal|0x0960
block|,
literal|"V96xPBC i960 Bridges for i960 Processors"
block|}
block|,
block|{
literal|0xc960
block|,
literal|"V96DPC i960 Dual PCI Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11b8
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Quad PeerMaster"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11b9
index|[]
init|=
block|{
block|{
literal|0xc0ed
block|,
literal|"SSA Ctrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11bc
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"NPI NuCard PCI FDDI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11c1
index|[]
init|=
block|{
block|{
literal|0x0440
block|,
literal|"LT Winmodem 56k Data+Fax+Voice+DSVD"
block|}
block|,
block|{
literal|0x0441
block|,
literal|"LT Winmodem 56k Data+Fax"
block|}
block|,
block|{
literal|0x0442
block|,
literal|"1646T00 V.90 Lucent Modem"
block|}
block|,
block|{
literal|0x0443
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0444
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0445
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0446
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0447
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0448
block|,
literal|"LT Winmodem 56k"
block|}
block|,
block|{
literal|0x0449
block|,
literal|"LT Winmodem 56k"
block|}
block|,
block|{
literal|0x044a
block|,
literal|"LT Winmodem 56k"
block|}
block|,
block|{
literal|0x044b
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x044c
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x044d
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x044e
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0450
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0451
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0452
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0453
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0454
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0455
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0456
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0457
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0458
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0459
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x045a
block|,
literal|"LT Winmodem"
block|}
block|,
block|{
literal|0x0480
block|,
literal|"Venus Winmodem"
block|}
block|,
block|{
literal|0x5801
block|,
literal|"USB Open Host Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11c8
index|[]
init|=
block|{
block|{
literal|0x0658
block|,
literal|"PSB PCI-SCI Bridge"
block|}
block|,
block|{
literal|0xd665
block|,
literal|"PSB64"
block|}
block|,
block|{
literal|0xd667
block|,
literal|"PSB66"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11c9
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"16-line serial port w/DMA"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"4-line serial port w/DMA"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11cb
index|[]
init|=
block|{
block|{
literal|0x2000
block|,
literal|"PCI-9050 Target Interface"
block|}
block|,
block|{
literal|0x4000
block|,
literal|"SUPI-1 XIO/SIO Host"
block|}
block|,
block|{
literal|0x8000
block|,
literal|"T225 Bridge RIO Host"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11d1
index|[]
init|=
block|{
block|{
literal|0x01f7
block|,
literal|"VxP524 PCI Video Processor"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11d4
index|[]
init|=
block|{
block|{
literal|0x2f44
block|,
literal|"ADSP-2141 SafeNet Crypto Accelerator chip"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11d5
index|[]
init|=
block|{
block|{
literal|0x0115
block|,
literal|"10115 Greensheet"
block|}
block|,
block|{
literal|0x0117
block|,
literal|"10117 Greensheet"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11de
index|[]
init|=
block|{
block|{
literal|0x6057
block|,
literal|"ZR36057 MotionJPEG/TV Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11f0
index|[]
init|=
block|{
block|{
literal|0x4232
block|,
literal|"FASTline UTP Quattro"
block|}
block|,
block|{
literal|0x4233
block|,
literal|"FASTline FO"
block|}
block|,
block|{
literal|0x4234
block|,
literal|"FASTline UTP"
block|}
block|,
block|{
literal|0x4235
block|,
literal|"FASTline-II UTP"
block|}
block|,
block|{
literal|0x4236
block|,
literal|"FASTline-II FO"
block|}
block|,
block|{
literal|0x4731
block|,
literal|"GIGAline"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11f4
index|[]
init|=
block|{
block|{
literal|0x2915
block|,
literal|"2915"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11f6
index|[]
init|=
block|{
block|{
literal|0x0112
block|,
literal|"ReadyLink ENET100-VG4"
block|}
block|,
block|{
literal|0x1401
block|,
literal|"ReadyLink 2000 (Winbod W89C940)"
block|}
block|,
block|{
literal|0x2011
block|,
literal|"RL100-ATX 10/100Ethernet Adapter"
block|}
block|,
block|{
literal|0x2201
block|,
literal|"ReadyLink 100TX (Winbond W89C840)"
block|}
block|,
block|{
literal|0x9881
block|,
literal|"RL100TX Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11f8
index|[]
init|=
block|{
block|{
literal|0x7375
block|,
literal|"PM7375 LASAR-155 ATM SAR"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_11fe
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"RocketPort"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1208
index|[]
init|=
block|{
block|{
literal|0x4853
block|,
literal|"HS-Link Device"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_120e
index|[]
init|=
block|{
block|{
literal|0x0100
block|,
literal|"Cyclom-Y Multiport Serial Card"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"Cyclom-Y Multiport Serial Card"
block|}
block|,
block|{
literal|0x0102
block|,
literal|"Cyclom-4Y Multiport Serial Card"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"Cyclom-4Y Multiport Serial Card"
block|}
block|,
block|{
literal|0x0104
block|,
literal|"Cyclom-8Y Multiport Serial Card"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"Cyclom-8Y Multiport Serial Card"
block|}
block|,
block|{
literal|0x0200
block|,
literal|"Cyclom-Z Intelligent Multiport Serial"
block|}
block|,
block|{
literal|0x0201
block|,
literal|"Cyclom-Z Intelligent Serial Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_120f
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Roadrunner"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1217
index|[]
init|=
block|{
block|{
literal|0x673a
block|,
literal|"OZ6730 PCI to PCMCIA Bridge"
block|}
block|,
block|{
literal|0x6792
block|,
literal|"OZ6729 PCI to PCMCIA Bridge"
block|}
block|,
block|{
literal|0x6832
block|,
literal|"OZ6832/3 CardBus Controller"
block|}
block|,
block|{
literal|0x6836
block|,
literal|"OZ6836/6860 CardBus Controller"
block|}
block|,
block|{
literal|0x6872
block|,
literal|"OZ6812 CardBus Controller"
block|}
block|,
block|{
literal|0x6933
block|,
literal|"OZ6933 CardBus Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_121a
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Voodoo Voodoo 3D Acceleration Chip"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"Voodoo2 Voodoo 2 3D Accelerator"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"Voodoo Banshee Voodoo Banshee"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"Voodoo3 All Voodoo3 chips, 3000"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1220
index|[]
init|=
block|{
block|{
literal|0x1220
block|,
literal|"AMCC 5933 TMS320C80 DSP/Imaging Board"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_122d
index|[]
init|=
block|{
block|{
literal|0x1206
block|,
literal|"368DSP"
block|}
block|,
block|{
literal|0x50dc
block|,
literal|"3328 Audio"
block|}
block|,
block|{
literal|0x80da
block|,
literal|"3328 Audio"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1236
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"RealMagic64/GX"
block|}
block|,
block|{
literal|0x6401
block|,
literal|"REALmagic64/GX GUI Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_123d
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"EasyConnect 8/32"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"EasyConnect 8/64"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"EasyIO"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_123f
index|[]
init|=
block|{
block|{
literal|0x00e4
block|,
literal|"MPEG"
block|}
block|,
block|{
literal|0x8120
block|,
literal|"176 E4?"
block|}
block|,
block|{
literal|0x8888
block|,
literal|"Cinemaster C 3.0 DVD Decoder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1242
index|[]
init|=
block|{
block|{
literal|0x4643
block|,
literal|"FCI-1063 Fibre Channel Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1244
index|[]
init|=
block|{
block|{
literal|0x0700
block|,
literal|"B1 ISDN controller"
block|}
block|,
block|{
literal|0x0a00
block|,
literal|"A1 AVM Fritz!Card"
block|}
block|,
block|{
literal|0x0a00
block|,
literal|"A1 AVM Fritz!Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_124d
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"EasyConnect 8/32"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"EasyConnect 8/64"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"EasyIO PCI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_124f
index|[]
init|=
block|{
block|{
literal|0x0041
block|,
literal|"IFT-2000 PCI RAID Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1255
index|[]
init|=
block|{
block|{
literal|0x1110
block|,
literal|"MPEG Forge"
block|}
block|,
block|{
literal|0x1210
block|,
literal|"MPEG Fusion"
block|}
block|,
block|{
literal|0x2110
block|,
literal|"VideoPlex"
block|}
block|,
block|{
literal|0x2120
block|,
literal|"VideoPlex CC"
block|}
block|,
block|{
literal|0x2130
block|,
literal|"VideoQuest"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1256
index|[]
init|=
block|{
block|{
literal|0x4401
block|,
literal|"PCI-2220i Dale EIDE Adapter"
block|}
block|,
block|{
literal|0x5201
block|,
literal|"PCI-2000 IntelliCache SCSI Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1259
index|[]
init|=
block|{
block|{
literal|0x2560
block|,
literal|"AT-2560 Fast Ethernet Adapter (i82557B)"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_125d
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"ESS336H PCI Fax Modem (early model)"
block|}
block|,
block|{
literal|0x1968
block|,
literal|"ES1968 Maestro-2 PCI audio accelerator"
block|}
block|,
block|{
literal|0x1969
block|,
literal|"ES1938/41/46 Solo-1 PCI AudioDrive family"
block|}
block|,
block|{
literal|0x199b
block|,
literal|"ES1938 Maestro-3.COMM PCI Voice+Fax Modem"
block|}
block|,
block|{
literal|0x2808
block|,
literal|"ES336H PCI Fax Modem (later model)"
block|}
block|,
block|{
literal|0x2898
block|,
literal|"ES2898 ES56-PI Family V.90 PCI Modem"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1260
index|[]
init|=
block|{
block|{
literal|0x8130
block|,
literal|"HMP8130 NTSC/PAL Video Decoder"
block|}
block|,
block|{
literal|0x8131
block|,
literal|"HMP8131 NTSC/PAL Video Decoder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1266
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"NE10/100 Adapter (i82557B)"
block|}
block|,
block|{
literal|0x1910
block|,
literal|"NE2000Plus (RT8029) Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1267
index|[]
init|=
block|{
block|{
literal|0x5352
block|,
literal|"PCR2101"
block|}
block|,
block|{
literal|0x5a4b
block|,
literal|"telsatturbo"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_126f
index|[]
init|=
block|{
block|{
literal|0x0710
block|,
literal|"SM710 LynxEM"
block|}
block|,
block|{
literal|0x0712
block|,
literal|"SM712 LynxEM+"
block|}
block|,
block|{
literal|0x0720
block|,
literal|"SM720 Lynx3DM"
block|}
block|,
block|{
literal|0x0810
block|,
literal|"SM810 LynxE"
block|}
block|,
block|{
literal|0x0811
block|,
literal|"SM811 LynxE"
block|}
block|,
block|{
literal|0x0820
block|,
literal|"SM820 Lynx3D"
block|}
block|,
block|{
literal|0x0910
block|,
literal|"SM910 Lynx"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1273
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"DirecPC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1274
index|[]
init|=
block|{
block|{
literal|0x1371
block|,
literal|"ES1371 AudioPCI"
block|}
block|,
block|{
literal|0x5000
block|,
literal|"ES1370 AudioPCI"
block|}
block|,
block|{
literal|0x5880
block|,
literal|"5880 AudioPCI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1279
index|[]
init|=
block|{
block|{
literal|0x0295
block|,
literal|"Virtual Northbridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_127a
index|[]
init|=
block|{
block|{
literal|0x1002
block|,
literal|"RC56HCFPCI Modem enumerator"
block|}
block|,
block|{
literal|0x1003
block|,
literal|"HCF 56k V.90 Modem"
block|}
block|,
block|{
literal|0x1004
block|,
literal|"HCF 56k V.90 Modem"
block|}
block|,
block|{
literal|0x1005
block|,
literal|"HCF 56k V.90 Speakerphone Modem"
block|}
block|,
block|{
literal|0x1025
block|,
literal|"HCF 56k PCI Modem"
block|}
block|,
block|{
literal|0x1026
block|,
literal|"HCF 56k V.90 Speakerphone Modem"
block|}
block|,
block|{
literal|0x1035
block|,
literal|"HCF 56k Speakerphone Modem"
block|}
block|,
block|{
literal|0x1085
block|,
literal|"Volcano HCF 56k PCI Modem"
block|}
block|,
block|{
literal|0x2004
block|,
literal|"SoftK56VB2.1V2.08.02 K56 modem"
block|}
block|,
block|{
literal|0x2013
block|,
literal|"Soft 56K PCI modem"
block|}
block|,
block|{
literal|0x2014
block|,
literal|"PCI modem"
block|}
block|,
block|{
literal|0x2015
block|,
literal|"Conexant SoftK56 Speakerphone Modem"
block|}
block|,
block|{
literal|0x4320
block|,
literal|"Riptide PCI Audio Controller"
block|}
block|,
block|{
literal|0x4321
block|,
literal|"Riptide HCF 56k PCI Modem"
block|}
block|,
block|{
literal|0x4322
block|,
literal|"Riptide PCI Game Controller"
block|}
block|,
block|{
literal|0x8234
block|,
literal|"RapidFire 616X ATM155 Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1282
index|[]
init|=
block|{
block|{
literal|0x9102
block|,
literal|"DM9102/A GFast Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1283
index|[]
init|=
block|{
block|{
literal|0x673a
block|,
literal|"IT8330G IDE Controller"
block|}
block|,
block|{
literal|0x8330
block|,
literal|"IT8330G Host Bridge"
block|}
block|,
block|{
literal|0x8888
block|,
literal|"IT8888F PCI to ISA Bridge with SMB"
block|}
block|,
block|{
literal|0x8889
block|,
literal|"IT8889F PCI to ISA Bridge"
block|}
block|,
block|{
literal|0xe886
block|,
literal|"IT8330G PCI to ISA Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1285
index|[]
init|=
block|{
block|{
literal|0x0100
block|,
literal|"ES1849 Maestro-1 AudioDrive"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1287
index|[]
init|=
block|{
block|{
literal|0x001e
block|,
literal|"LS220D DVD Decoder"
block|}
block|,
block|{
literal|0x001f
block|,
literal|"LS220C DVD Decoder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_128d
index|[]
init|=
block|{
block|{
literal|0x0021
block|,
literal|"ATM Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_128e
index|[]
init|=
block|{
block|{
literal|0x0008
block|,
literal|"ST128 WSS/SB"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"ST128 SAM9407"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"ST128 Game Port"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"ST128 MPU Port"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"ST128 Control Port"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12ab
index|[]
init|=
block|{
block|{
literal|0x3000
block|,
literal|"TUN-200/MPG-200C PCI TV (and DVD Decoder?) Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12ae
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"ACENIC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12b9
index|[]
init|=
block|{
block|{
literal|0x1006
block|,
literal|"USR 56k Internal WinModem"
block|}
block|,
block|{
literal|0x1007
block|,
literal|"USR 56k Internal WinModem"
block|}
block|,
block|{
literal|0x1008
block|,
literal|"USR 56k Internal Modem"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12be
index|[]
init|=
block|{
block|{
literal|0x3041
block|,
literal|"AN3041Q CO-MEM PCI Bus Interface and Cache"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12c5
index|[]
init|=
block|{
block|{
literal|0x007f
block|,
literal|"ISE PEI Imaging Subsystem Engine"
block|}
block|,
block|{
literal|0x0081
block|,
literal|"PCIVST PCI Thresholding Engine"
block|}
block|,
block|{
literal|0x0085
block|,
literal|"Video Simulator/Sender"
block|}
block|,
block|{
literal|0x0086
block|,
literal|"THR2 Multi-scale Thresholder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12d2
index|[]
init|=
block|{
block|{
literal|0x0008
block|,
literal|"NV1"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"DAC64"
block|}
block|,
block|{
literal|0x0018
block|,
literal|"RIVA 128 Riva 128 2D/3D GUI Accelerator"
block|}
block|,
block|{
literal|0x0019
block|,
literal|"RIVA 128ZX 2D/3D GUI Accelerator"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"TNT"
block|}
block|,
block|{
literal|0x0028
block|,
literal|"TNT2"
block|}
block|,
block|{
literal|0x0029
block|,
literal|"UTNT2"
block|}
block|,
block|{
literal|0x002c
block|,
literal|"VTNT2"
block|}
block|,
block|{
literal|0x00a0
block|,
literal|"ITNT2"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12db
index|[]
init|=
block|{
block|{
literal|0x0003
block|,
literal|"FoxFire II"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12de
index|[]
init|=
block|{
block|{
literal|0x0200
block|,
literal|"Cryptoswift 200"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12e0
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"ST16C654 Quad UART"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"ST16C654 Quad UART"
block|}
block|,
block|{
literal|0x0030
block|,
literal|"ST16C654 Quad UART"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12e4
index|[]
init|=
block|{
block|{
literal|0x1140
block|,
literal|"ISDN Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12eb
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"AU8820 Vortex Digital Audio Processor"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_12f8
index|[]
init|=
block|{
block|{
literal|0x0002
block|,
literal|"VideoMaker"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1307
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PCI-DAS1602/16"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"PCI-GPIB"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"PCI-DIO48H"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"PCI-PDISO8"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"PCI-PDISO16"
block|}
block|,
block|{
literal|0x000f
block|,
literal|"PCI-DAS1200"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"PCI-DAS1602/12"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"PCI-DIO24H"
block|}
block|,
block|{
literal|0x0015
block|,
literal|"PCI-DIO24H/CTR3"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"PCI-DIO24H/CTR16"
block|}
block|,
block|{
literal|0x0017
block|,
literal|"PCI-DIO96H"
block|}
block|,
block|{
literal|0x0018
block|,
literal|"PCI-CTR05"
block|}
block|,
block|{
literal|0x0019
block|,
literal|"PCI-DAS1200/JR"
block|}
block|,
block|{
literal|0x001a
block|,
literal|"PCI-DAS1001"
block|}
block|,
block|{
literal|0x001b
block|,
literal|"PCI-DAS1002"
block|}
block|,
block|{
literal|0x001c
block|,
literal|"PCI-DAS1602JR/16"
block|}
block|,
block|{
literal|0x001d
block|,
literal|"PCI-DAS6402/16"
block|}
block|,
block|{
literal|0x001e
block|,
literal|"PCI-DAS6402/12"
block|}
block|,
block|{
literal|0x001f
block|,
literal|"PCI-DAS16/M1"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"PCI-DDA02/12"
block|}
block|,
block|{
literal|0x0021
block|,
literal|"PCI-DDA04/12"
block|}
block|,
block|{
literal|0x0022
block|,
literal|"PCI-DDA08/12"
block|}
block|,
block|{
literal|0x0023
block|,
literal|"PCI-DDA02/16"
block|}
block|,
block|{
literal|0x0024
block|,
literal|"PCI-DDA04/16"
block|}
block|,
block|{
literal|0x0025
block|,
literal|"PCI-DDA08/16"
block|}
block|,
block|{
literal|0x0026
block|,
literal|"PCI-DAC04/12-HS"
block|}
block|,
block|{
literal|0x0027
block|,
literal|"PCI-DAC04/16-HS"
block|}
block|,
block|{
literal|0x0028
block|,
literal|"CIO-DIO24 24 Bit Digital Input/Output Board"
block|}
block|,
block|{
literal|0x0029
block|,
literal|"PCI-DAS08"
block|}
block|,
block|{
literal|0x002c
block|,
literal|"PCI-INT32"
block|}
block|,
block|{
literal|0x0033
block|,
literal|"PCI-DUAL-AC5"
block|}
block|,
block|{
literal|0x0034
block|,
literal|"PCI-DAS-TC"
block|}
block|,
block|{
literal|0x0035
block|,
literal|"PCI-DAS64/M1/16"
block|}
block|,
block|{
literal|0x0036
block|,
literal|"PCI-DAS64/M2/16"
block|}
block|,
block|{
literal|0x0037
block|,
literal|"PCI-DAS64/M3/16"
block|}
block|,
block|{
literal|0x004c
block|,
literal|"PCI-DAS1000"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1308
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"NetCelerator Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1318
index|[]
init|=
block|{
block|{
literal|0x0911
block|,
literal|"G-NIC II 1000BT Network Interface Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1319
index|[]
init|=
block|{
block|{
literal|0x0801
block|,
literal|"FM801 PCI audio controller"
block|}
block|,
block|{
literal|0x0802
block|,
literal|"FM801 PCI Joystick"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"FM801 PCI Audio"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"FM801 PCI Joystick"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_134a
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Domex DMX 3191 PCI SCSI Controller"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"Domex DMX3194UP SCSI Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_134d
index|[]
init|=
block|{
block|{
literal|0x7890
block|,
literal|"HSP MicroModem 56"
block|}
block|,
block|{
literal|0x7891
block|,
literal|"HSP MicroModem 56"
block|}
block|,
block|{
literal|0x7892
block|,
literal|"HSP MicroModem 56"
block|}
block|,
block|{
literal|0x7893
block|,
literal|"HSP MicroModem 56"
block|}
block|,
block|{
literal|0x7894
block|,
literal|"HSP MicroModem 56"
block|}
block|,
block|{
literal|0x7895
block|,
literal|"HSP MicroModem 56"
block|}
block|,
block|{
literal|0x7896
block|,
literal|"HSP MicroModem 56"
block|}
block|,
block|{
literal|0x7897
block|,
literal|"97860963 HSP MicroModem 56"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_135e
index|[]
init|=
block|{
block|{
literal|0x7101
block|,
literal|"Single Port RS-232/422/485/520"
block|}
block|,
block|{
literal|0x7201
block|,
literal|"Dual Port RS-232/422/485 Interface"
block|}
block|,
block|{
literal|0x7202
block|,
literal|"Dual Port RS-232 Interface"
block|}
block|,
block|{
literal|0x7401
block|,
literal|"Four Port RS-232 Interface"
block|}
block|,
block|{
literal|0x7402
block|,
literal|"Four Port RS-422/485 Interface"
block|}
block|,
block|{
literal|0x7801
block|,
literal|"Eight Port RS-232 Interface"
block|}
block|,
block|{
literal|0x8001
block|,
literal|"8001 Digital I/O Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1385
index|[]
init|=
block|{
block|{
literal|0x620a
block|,
literal|"GA620"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1389
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PCI1500PFB Intelligent fieldbus Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1397
index|[]
init|=
block|{
block|{
literal|0x2bd0
block|,
literal|"BIPAC-PCI Billion ISDN Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_13c0
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"SyncLink PCI WAN Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_13c1
index|[]
init|=
block|{
block|{
literal|0x1000
block|,
literal|"ATA-RAID"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_13df
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PCI56RVP Modem"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_13f6
index|[]
init|=
block|{
block|{
literal|0x0100
block|,
literal|"CMI8338-031 PCI Audio Device"
block|}
block|,
block|{
literal|0x0101
block|,
literal|"CMI8338-031 PCI Audio Device"
block|}
block|,
block|{
literal|0x0111
block|,
literal|"CMI8738/C3DX PCI Audio Device"
block|}
block|,
block|{
literal|0x0211
block|,
literal|"HSP56 Audiomodem Riser"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1407
index|[]
init|=
block|{
block|{
literal|0x8000
block|,
literal|"Lava Parallel"
block|}
block|,
block|{
literal|0x8001
block|,
literal|"Lava Dual Parallel port A"
block|}
block|,
block|{
literal|0x8002
block|,
literal|"Lava Dual Parallel port A"
block|}
block|,
block|{
literal|0x8003
block|,
literal|"Lava Dual Parallel port B"
block|}
block|,
block|{
literal|0x8800
block|,
literal|"BOCA Research IOPPAR"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1412
index|[]
init|=
block|{
block|{
literal|0x1712
block|,
literal|"ICE1712 Envy24 PCI Multi-Channel I/O Ctrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1448
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"ADAT/EDIT Audio Editing"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_144a
index|[]
init|=
block|{
block|{
literal|0x7296
block|,
literal|"PCI-7296"
block|}
block|,
block|{
literal|0x7432
block|,
literal|"PCI-7432"
block|}
block|,
block|{
literal|0x7433
block|,
literal|"PCI-7433"
block|}
block|,
block|{
literal|0x7434
block|,
literal|"PCI-7434"
block|}
block|,
block|{
literal|0x7841
block|,
literal|"PCI-7841"
block|}
block|,
block|{
literal|0x8133
block|,
literal|"PCI-8133"
block|}
block|,
block|{
literal|0x8554
block|,
literal|"PCI-8554"
block|}
block|,
block|{
literal|0x9111
block|,
literal|"PCI-9111"
block|}
block|,
block|{
literal|0x9113
block|,
literal|"PCI-9113"
block|}
block|,
block|{
literal|0x9114
block|,
literal|"PCI-9114"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_145f
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"NextMove PCI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_148d
index|[]
init|=
block|{
block|{
literal|0x1003
block|,
literal|"Creative ModemBlaster V.90 PCI DI5635"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_14b3
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"DSL NIC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_14b7
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Symphony 4110"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_14b9
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PC4800"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_14d4
index|[]
init|=
block|{
block|{
literal|0x0400
block|,
literal|"Panacom 7 Interface chip"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_14db
index|[]
init|=
block|{
block|{
literal|0x2120
block|,
literal|"TK9902"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_14dc
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"PCI230"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"PCI242"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"PCI244"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"PCI247"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"PCI248"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"PCI249"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"PCI260"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"PCI224"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"PCI234"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"PCI236"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_14f2
index|[]
init|=
block|{
block|{
literal|0x0120
block|,
literal|"Mobility Split Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1500
index|[]
init|=
block|{
block|{
literal|0x1300
block|,
literal|"SIS900 10/100M PCI Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x1320
block|,
literal|"VT86C100A 10/100M PCI Fast Ethernet Controler"
block|}
block|,
block|{
literal|0x1360
block|,
literal|"RTL8139A 10/100 Mbps PCI Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x1380
block|,
literal|"DEC21143PD 10/100M PCI Fast Ethernet Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1507
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"MPC105 Eagle"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"MPC106 Grackle"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"MPC8240 Kahlua"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"MPC145575 HFC-PCI"
block|}
block|,
block|{
literal|0x0431
block|,
literal|"KTI829c 100VG"
block|}
block|,
block|{
literal|0x4801
block|,
literal|"Raven"
block|}
block|,
block|{
literal|0x4802
block|,
literal|"Falcon"
block|}
block|,
block|{
literal|0x4803
block|,
literal|"Hawk"
block|}
block|,
block|{
literal|0x4806
block|,
literal|"CPX8216"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_151a
index|[]
init|=
block|{
block|{
literal|0x1002
block|,
literal|"PCI-1002"
block|}
block|,
block|{
literal|0x1004
block|,
literal|"PCI-1004"
block|}
block|,
block|{
literal|0x1008
block|,
literal|"PCI-1008"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_157c
index|[]
init|=
block|{
block|{
literal|0x8001
block|,
literal|"Fix2000 PCI Y2K Compliance Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1592
index|[]
init|=
block|{
block|{
literal|0x0781
block|,
literal|"Multi-IO Card"
block|}
block|,
block|{
literal|0x0782
block|,
literal|"Dual Parallel Port Card (EPP)"
block|}
block|,
block|{
literal|0x0783
block|,
literal|"Multi-IO Card"
block|}
block|,
block|{
literal|0x0785
block|,
literal|"Multi-IO Card"
block|}
block|,
block|{
literal|0x0786
block|,
literal|"Multi-IO Card"
block|}
block|,
block|{
literal|0x0787
block|,
literal|"Multi-IO Card 2 series"
block|}
block|,
block|{
literal|0x0788
block|,
literal|"Multi-IO Card"
block|}
block|,
block|{
literal|0x078a
block|,
literal|"Multi-IO Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_15ad
index|[]
init|=
block|{
block|{
literal|0x0710
block|,
literal|"Virtual SVGA"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_15dc
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Argus 300 PCI Cryptography Module"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1619
index|[]
init|=
block|{
block|{
literal|0x0400
block|,
literal|"FarSync T2P Two Port Intelligent Sync Comms Card"
block|}
block|,
block|{
literal|0x0440
block|,
literal|"FarSync T4P Four Port Intelligent Sync Comms Card"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1a08
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"SC15064"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1c1c
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"FR710 EIDE Ctrlr"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"82C101 IDE Ctrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1d44
index|[]
init|=
block|{
block|{
literal|0xa400
block|,
literal|"PM2x24/3224 SCSI Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_1de1
index|[]
init|=
block|{
block|{
literal|0x0391
block|,
literal|"TRM-S1040 SCSI ASIC"
block|}
block|,
block|{
literal|0x2020
block|,
literal|"DC-390 SCSI Controller"
block|}
block|,
block|{
literal|0x690c
block|,
literal|"DC-690C IDE Cache Controller"
block|}
block|,
block|{
literal|0xdc29
block|,
literal|"DC290M Bus Master IDE PCI 2 controllers"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_2348
index|[]
init|=
block|{
block|{
literal|0x2010
block|,
literal|"8142 100VG/AnyLAN"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_3388
index|[]
init|=
block|{
block|{
literal|0x8011
block|,
literal|"CPU to PCI Bridge"
block|}
block|,
block|{
literal|0x8012
block|,
literal|"PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x8013
block|,
literal|"EIDE Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_3d3d
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"GLint 300SX 3D Accelerator"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"GLint 500TX Sapphire 3D Accelerator"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"GLint Delta Geometry processor"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"3C0SX 2D+3D Accelerator"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"Permedia 2D+3D Accelerator"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"GLint MX 3D Accelerator"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"3D Extreme Permedia II 2D+3D Accelerator"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"GLint Gamma G1"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"Permedia 3 2D+3D Accelerator"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"GLint R3"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"Permedia II 2D+3D Accelerator"
block|}
block|,
block|{
literal|0x1004
block|,
literal|"Permedia 3D+3D Accelerator"
block|}
block|,
block|{
literal|0x3d04
block|,
literal|"Permedia 2D+3D Accelerator"
block|}
block|,
block|{
literal|0xffff
block|,
literal|"GLint VGA"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_4005
index|[]
init|=
block|{
block|{
literal|0x0300
block|,
literal|"ALS300 PCI Audio Device"
block|}
block|,
block|{
literal|0x0308
block|,
literal|"ALS300+ PCI Audio Device"
block|}
block|,
block|{
literal|0x0309
block|,
literal|"ALS300+ PCI Input Controller"
block|}
block|,
block|{
literal|0x1064
block|,
literal|"ALG2064 GUI Accelerator"
block|}
block|,
block|{
literal|0x2064
block|,
literal|"ALG2032/2064i GUI Accelerator"
block|}
block|,
block|{
literal|0x2128
block|,
literal|"ALG2364A GUI Accelerator"
block|}
block|,
block|{
literal|0x2301
block|,
literal|"ALG2301 GUI Accelerator"
block|}
block|,
block|{
literal|0x2302
block|,
literal|"ALG2302 GUI Accelerator"
block|}
block|,
block|{
literal|0x2303
block|,
literal|"AVG2302 GUI Accelerator"
block|}
block|,
block|{
literal|0x2364
block|,
literal|"ALG2364 GUI Accelerator"
block|}
block|,
block|{
literal|0x2464
block|,
literal|"ALG2464 GUI Accelerator"
block|}
block|,
block|{
literal|0x2501
block|,
literal|"ALG2564A/25128A GUI Accelerator"
block|}
block|,
block|{
literal|0x4000
block|,
literal|"ALS4000 Audio Chipset"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_4033
index|[]
init|=
block|{
block|{
literal|0x1300
block|,
literal|"SIS900 10/100Mbps Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x1320
block|,
literal|"VT86C100A 10/100M PCI Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x1360
block|,
literal|"RTL8139A 10/100 Mbps PCI Fast Ethernet Controller"
block|}
block|,
block|{
literal|0x1380
block|,
literal|"DEC 21143PD 10/100M PCI Fast Ethernet Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_4a14
index|[]
init|=
block|{
block|{
literal|0x5000
block|,
literal|"NV5000 RT8029-based Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_4b10
index|[]
init|=
block|{
block|{
literal|0x3080
block|,
literal|"SCSI Host Adapter"
block|}
block|,
block|{
literal|0x4010
block|,
literal|"Fast/wide SCSI-2"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_4d51
index|[]
init|=
block|{
block|{
literal|0x0200
block|,
literal|"MQ-200"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_5053
index|[]
init|=
block|{
block|{
literal|0x2010
block|,
literal|"Daytona Audio Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_5145
index|[]
init|=
block|{
block|{
literal|0x3031
block|,
literal|"Concert AudioPCI"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_5301
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"ProMotion aT3D"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_5333
index|[]
init|=
block|{
block|{
literal|0x0551
block|,
literal|"86C551 Plato/PX"
block|}
block|,
block|{
literal|0x5631
block|,
literal|"86C325 Virge 3D GUI Accelerator"
block|}
block|,
block|{
literal|0x8800
block|,
literal|"Vision 866 GUI Accelerator"
block|}
block|,
block|{
literal|0x8801
block|,
literal|"Vision 964 GUI Accelerator"
block|}
block|,
block|{
literal|0x8810
block|,
literal|"86C732 Trio 32 GUI Accelerator rev. 0"
block|}
block|,
block|{
literal|0x8811
block|,
literal|"86C764/765 Trio 64/64V+ GUI Accelerator"
block|}
block|,
block|{
literal|0x8812
block|,
literal|"86CM65? Aurora 64V+"
block|}
block|,
block|{
literal|0x8813
block|,
literal|"86C764 Trio 32/64 GUI Accelerator v3"
block|}
block|,
block|{
literal|0x8814
block|,
literal|"86C767 Trio 64UV+ GUI Accelerator"
block|}
block|,
block|{
literal|0x8815
block|,
literal|"86CM66 Aurora128"
block|}
block|,
block|{
literal|0x883d
block|,
literal|"86C988 ViRGE/VX 3D GUI Accelerator"
block|}
block|,
block|{
literal|0x8870
block|,
literal|"Fire GL"
block|}
block|,
block|{
literal|0x8880
block|,
literal|"86C868 Vision 868 GUI Accelerator VRAM rev. 0"
block|}
block|,
block|{
literal|0x8881
block|,
literal|"86C868 Vision 868 GUI Accelerator VRAM rev. 1"
block|}
block|,
block|{
literal|0x8882
block|,
literal|"86C868 Vision 868 GUI Accelerator VRAM rev. 2"
block|}
block|,
block|{
literal|0x8883
block|,
literal|"86C868 Vision 868 GUI Accelerator VRAM rev. 3"
block|}
block|,
block|{
literal|0x88b0
block|,
literal|"86C928 Vision 928 GUI Accelerator VRAM rev. 0"
block|}
block|,
block|{
literal|0x88b1
block|,
literal|"86C928 Vision 928 GUI Accelerator VRAM rev. 1"
block|}
block|,
block|{
literal|0x88b2
block|,
literal|"86C928 Vision 928 GUI Accelerator VRAM rev. 2"
block|}
block|,
block|{
literal|0x88b3
block|,
literal|"86C928 Vision 928 GUI Accelerator VRAM rev. 3"
block|}
block|,
block|{
literal|0x88c0
block|,
literal|"86C864 Vision 864 GUI Accelerator DRAM rev. 0"
block|}
block|,
block|{
literal|0x88c1
block|,
literal|"86C864 Vision 864 GUI Accelerator DRAM rev. 1"
block|}
block|,
block|{
literal|0x88c2
block|,
literal|"86C864 Vision 864 GUI Accelerator DRAM rev. 2"
block|}
block|,
block|{
literal|0x88c3
block|,
literal|"86C864 Vision 864 GUI Accelerator DRAM rev. 3"
block|}
block|,
block|{
literal|0x88d0
block|,
literal|"86C964 Vision 964 GUI Accelerator VRAM rev. 0"
block|}
block|,
block|{
literal|0x88d1
block|,
literal|"86C964 Vision 964-P GUI Accelerator VRAM rev. 1"
block|}
block|,
block|{
literal|0x88d2
block|,
literal|"86C964 Vision 964-P GUI Accelerator DRAM rev 2"
block|}
block|,
block|{
literal|0x88d3
block|,
literal|"86C964 Vision 964-P GUI Accelerator VRAM rev. 3"
block|}
block|,
block|{
literal|0x88f0
block|,
literal|"86C968 Vision 968 GUI Accelerator VRAM rev. 0"
block|}
block|,
block|{
literal|0x88f1
block|,
literal|"86C968 Vision 968 GUI Accelerator VRAM rev. 1"
block|}
block|,
block|{
literal|0x88f2
block|,
literal|"86C968 Vision 968 GUI Accelerator VRAM rev. 2"
block|}
block|,
block|{
literal|0x88f3
block|,
literal|"86C968 Vision 968 GUI Accelerator VRAM rev. 3"
block|}
block|,
block|{
literal|0x8900
block|,
literal|"86C775 Trio64V2/DX"
block|}
block|,
block|{
literal|0x8901
block|,
literal|"86C775/86C785 Trio 64V2 DX/GX"
block|}
block|,
block|{
literal|0x8902
block|,
literal|"86C551 SMA Family"
block|}
block|,
block|{
literal|0x8903
block|,
literal|"TrioV Family"
block|}
block|,
block|{
literal|0x8904
block|,
literal|"86C365/366 Trio3D"
block|}
block|,
block|{
literal|0x8905
block|,
literal|"86C765 Trio64V+ comatible"
block|}
block|,
block|{
literal|0x8906
block|,
literal|"86C765 Trio64V+ comatible"
block|}
block|,
block|{
literal|0x8907
block|,
literal|"86C765 Trio64V+ comatible"
block|}
block|,
block|{
literal|0x8908
block|,
literal|"86C765 Trio64V+ comatible"
block|}
block|,
block|{
literal|0x8909
block|,
literal|"86C765 Trio64V+ comatible"
block|}
block|,
block|{
literal|0x890a
block|,
literal|"86C765 Trio64V+ comatible"
block|}
block|,
block|{
literal|0x890b
block|,
literal|"86C765 Trio64V+ compatible"
block|}
block|,
block|{
literal|0x890c
block|,
literal|"86C765 Trio64V+ compatible"
block|}
block|,
block|{
literal|0x890d
block|,
literal|"86C765 Trio64V+ compatible"
block|}
block|,
block|{
literal|0x890e
block|,
literal|"86C765 Trio64V+ compatible"
block|}
block|,
block|{
literal|0x890f
block|,
literal|"86C765 Trio64V+ compatible"
block|}
block|,
block|{
literal|0x8a01
block|,
literal|"82C375/86C385 ViRGE /DX& /GX"
block|}
block|,
block|{
literal|0x8a10
block|,
literal|"86C357 ViRGE /GX2"
block|}
block|,
block|{
literal|0x8a11
block|,
literal|"86C359 ViRGE /GX2+ Macrovision"
block|}
block|,
block|{
literal|0x8a12
block|,
literal|"86C359 ViRGE /GX2+"
block|}
block|,
block|{
literal|0x8a13
block|,
literal|"86C362 Trio3DX2 AGP"
block|}
block|,
block|{
literal|0x8a20
block|,
literal|"86C390/391 Savage3D"
block|}
block|,
block|{
literal|0x8a21
block|,
literal|"86C390 Savage3D/MV"
block|}
block|,
block|{
literal|0x8a22
block|,
literal|"86C394-397 Savage 4"
block|}
block|,
block|{
literal|0x8a23
block|,
literal|"86C394-397 Savage 4"
block|}
block|,
block|{
literal|0x8c00
block|,
literal|"85C260 ViRGE/M3 (ViRGE/MX)"
block|}
block|,
block|{
literal|0x8c01
block|,
literal|"86C260 ViRGE/M5 (ViRGE/MX)"
block|}
block|,
block|{
literal|0x8c02
block|,
literal|"86C240 ViRGE/MXC"
block|}
block|,
block|{
literal|0x8c03
block|,
literal|"86C280 ViRGE /MX+ Macrovision"
block|}
block|,
block|{
literal|0x8c10
block|,
literal|"86C270/274/290/294 Savage MX/IX/MX+MV/IX+MV"
block|}
block|,
block|{
literal|0x8c12
block|,
literal|"86C270/274/290/294 Savage MX/IX/MX+MV/IX+MV"
block|}
block|,
block|{
literal|0x9102
block|,
literal|"86C410 Savage 2000"
block|}
block|,
block|{
literal|0xca00
block|,
literal|"86C617 SonicVibes PCI Audio Accelerator"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_5455
index|[]
init|=
block|{
block|{
literal|0x4458
block|,
literal|"S5933 PCI-MyBus-Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_5555
index|[]
init|=
block|{
block|{
literal|0x0003
block|,
literal|"TURBOstor HFP-832 HiPPI NIC"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_6356
index|[]
init|=
block|{
block|{
literal|0x4002
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4102
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4202
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4302
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4402
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4502
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4602
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4702
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4802
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4902
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4a02
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4b02
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4c02
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4d02
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4e02
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0x4f02
block|,
literal|"ULTRA24 SCSI Host"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_6374
index|[]
init|=
block|{
block|{
literal|0x6773
block|,
literal|"GPPCI PCI Interface"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_6666
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"PCCOM4"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"PCCOM8"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_8001
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"ispLSI1032E PCI-decoder"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_8008
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"PWDOG1/2 PCI-Watchdog 1"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"PWDOG1/2 Watchdog2/PCI"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"PROTO2"
block|}
block|,
block|{
literal|0x0100
block|,
literal|"PREL8"
block|}
block|,
block|{
literal|0x0102
block|,
literal|"PREL16"
block|}
block|,
block|{
literal|0x0103
block|,
literal|"POPTOREL16"
block|}
block|,
block|{
literal|0x0105
block|,
literal|"POPTO16IN"
block|}
block|,
block|{
literal|0x0106
block|,
literal|"PTTL24IO"
block|}
block|,
block|{
literal|0x0107
block|,
literal|"PUNIREL"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"PDAC4"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"PAD12DAC4"
block|}
block|,
block|{
literal|0x1002
block|,
literal|"PAD16DAC4"
block|}
block|,
block|{
literal|0x1005
block|,
literal|"PAD12"
block|}
block|,
block|{
literal|0x1006
block|,
literal|"PAD16"
block|}
block|,
block|{
literal|0x3000
block|,
literal|"POPTOLCA"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_8086
index|[]
init|=
block|{
block|{
literal|0x0008
block|,
literal|"Extended Express System Support Ctrlr"
block|}
block|,
block|{
literal|0x0482
block|,
literal|"82375EB PCI-EISA Bridge (PCEB)"
block|}
block|,
block|{
literal|0x0483
block|,
literal|"82424TX/ZX CPU (i486) Bridge (Saturn)"
block|}
block|,
block|{
literal|0x0484
block|,
literal|"82378ZB/IB SIO ISA Bridge"
block|}
block|,
block|{
literal|0x0486
block|,
literal|"82425EX PCI System Controller (PSC) for i486 (Aries)"
block|}
block|,
block|{
literal|0x04a3
block|,
literal|"82434LX CPU (Pentium) Bridge (Mercury)"
block|}
block|,
block|{
literal|0x0960
block|,
literal|"80960RP i960 RP Microprocessor/Bridge"
block|}
block|,
block|{
literal|0x1000
block|,
literal|"82542 Gigabit Ethernet Controller"
block|}
block|,
block|{
literal|0x1001
block|,
literal|"82543GC 10/100/1000 Ethernet Controller"
block|}
block|,
block|{
literal|0x1029
block|,
literal|"PRO/100 PCI Ethernet Adapter"
block|}
block|,
block|{
literal|0x1030
block|,
literal|"82559 PCI Networking device"
block|}
block|,
block|{
literal|0x1100
block|,
literal|"82815 Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x1101
block|,
literal|"82815 AGP Bridge"
block|}
block|,
block|{
literal|0x1102
block|,
literal|"82815 Internal Graphics Device"
block|}
block|,
block|{
literal|0x1110
block|,
literal|"8x815 Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x1112
block|,
literal|"82815 Internal Graphics Device"
block|}
block|,
block|{
literal|0x1120
block|,
literal|"82815 Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x1121
block|,
literal|"82815 AGP Bridge"
block|}
block|,
block|{
literal|0x1130
block|,
literal|"82815/82815EM Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x1131
block|,
literal|"82815/82815EM AGP Bridge"
block|}
block|,
block|{
literal|0x1132
block|,
literal|"82815 Internal Graphics Device"
block|}
block|,
block|{
literal|0x1161
block|,
literal|"82806AA I/O APIC Device"
block|}
block|,
block|{
literal|0x1209
block|,
literal|"82559ER"
block|}
block|,
block|{
literal|0x1221
block|,
literal|"82092AA PCMCIA Bridge"
block|}
block|,
block|{
literal|0x1222
block|,
literal|"82092AA IDE Ctrlr"
block|}
block|,
block|{
literal|0x1223
block|,
literal|"SAA7116 Video Controller"
block|}
block|,
block|{
literal|0x1225
block|,
literal|"82452KX/GX Orion Extended Express CPU to PCI Bridge"
block|}
block|,
block|{
literal|0x1226
block|,
literal|"82596 EtherExpress PRO/10"
block|}
block|,
block|{
literal|0x1227
block|,
literal|"82865 EtherExpress PRO100"
block|}
block|,
block|{
literal|0x1228
block|,
literal|"EE PRO/100 Smart Intelligent 10/100 Fast Ethernet Adapter"
block|}
block|,
block|{
literal|0x1229
block|,
literal|"82557/8/9 Fast Ethernet LAN Controller"
block|}
block|,
block|{
literal|0x122d
block|,
literal|"82437FX System Controller (TSC)"
block|}
block|,
block|{
literal|0x122e
block|,
literal|"82371FB PCI to ISA Bridge (Triton)"
block|}
block|,
block|{
literal|0x1230
block|,
literal|"82371FB IDE Interface (Triton)"
block|}
block|,
block|{
literal|0x1231
block|,
literal|"DSVD Modem"
block|}
block|,
block|{
literal|0x1234
block|,
literal|"82371MX Mobile PCI I/O IDE Xcelerator (MPIIX)"
block|}
block|,
block|{
literal|0x1235
block|,
literal|"82437MX Mobile System Controller (MTSC)"
block|}
block|,
block|{
literal|0x1237
block|,
literal|"82441FX PCI& Memory Controller (PMC)"
block|}
block|,
block|{
literal|0x1239
block|,
literal|"82371FB IDE Interface (Triton)"
block|}
block|,
block|{
literal|0x123c
block|,
literal|"82380AB Mobile PCI-to-ISA Bridge (MISA)"
block|}
block|,
block|{
literal|0x123d
block|,
literal|"683053 Programmable Interrupt Device"
block|}
block|,
block|{
literal|0x1240
block|,
literal|"82752 AGP Graphics Accelerator"
block|}
block|,
block|{
literal|0x124b
block|,
literal|"82380FB 82380FB(MPCI2)"
block|}
block|,
block|{
literal|0x1250
block|,
literal|"82439HX System Controller (TXC)"
block|}
block|,
block|{
literal|0x1360
block|,
literal|"82806AA Hub Interface to PCI Bridge"
block|}
block|,
block|{
literal|0x1361
block|,
literal|"82806AA Advanced Interrupt Controller"
block|}
block|,
block|{
literal|0x1960
block|,
literal|"80960RP i960RP Microprocessor"
block|}
block|,
block|{
literal|0x1a21
block|,
literal|"82840 Host-Hub Interface A Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x1a23
block|,
literal|"82840 AGP Bridge"
block|}
block|,
block|{
literal|0x1a24
block|,
literal|"82840 Hub Interface B Bridge"
block|}
block|,
block|{
literal|0x2125
block|,
literal|"82801AB AC97 Audio Controller"
block|}
block|,
block|{
literal|0x2410
block|,
literal|"82801AA LPC Interface"
block|}
block|,
block|{
literal|0x2411
block|,
literal|"82801AA IDE Controller"
block|}
block|,
block|{
literal|0x2412
block|,
literal|"82801AA USB Controller"
block|}
block|,
block|{
literal|0x2413
block|,
literal|"82801AA SMBus Controller"
block|}
block|,
block|{
literal|0x2415
block|,
literal|"82801AA AC97 Audio Controller"
block|}
block|,
block|{
literal|0x2416
block|,
literal|"82801AA AC97 Modem Controller"
block|}
block|,
block|{
literal|0x2418
block|,
literal|"82801AA Hub Interface-to-PCI Bridge"
block|}
block|,
block|{
literal|0x2420
block|,
literal|"82801AB LPC Interface"
block|}
block|,
block|{
literal|0x2421
block|,
literal|"82801AB IDE Controller"
block|}
block|,
block|{
literal|0x2422
block|,
literal|"82801AB USB Controller"
block|}
block|,
block|{
literal|0x2423
block|,
literal|"82801AB SMBus Controller"
block|}
block|,
block|{
literal|0x2425
block|,
literal|"82801AB AC97 Audio Controller"
block|}
block|,
block|{
literal|0x2426
block|,
literal|"82801AB AC97 Modem Controller"
block|}
block|,
block|{
literal|0x2428
block|,
literal|"82801AB Hub Interface-to-PCI Bridge"
block|}
block|,
block|{
literal|0x2440
block|,
literal|"82801BA LPC Interface Bridge"
block|}
block|,
block|{
literal|0x2442
block|,
literal|"82801BA USB Controller"
block|}
block|,
block|{
literal|0x2443
block|,
literal|"82801BA SMBus Controller"
block|}
block|,
block|{
literal|0x2444
block|,
literal|"82801BA USB Controller"
block|}
block|,
block|{
literal|0x2445
block|,
literal|"82801BA AC97 Audio Controller"
block|}
block|,
block|{
literal|0x2446
block|,
literal|"82801BA AC97 Modem Controller"
block|}
block|,
block|{
literal|0x2449
block|,
literal|"82801BA LAN Controller"
block|}
block|,
block|{
literal|0x244b
block|,
literal|"82801BA IDE Controller"
block|}
block|,
block|{
literal|0x244e
block|,
literal|"82801BA Hub Interface to PCI Bridge"
block|}
block|,
block|{
literal|0x2500
block|,
literal|"82820 Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x2501
block|,
literal|"82820 Host Bridge (MCH)"
block|}
block|,
block|{
literal|0x250b
block|,
literal|"82820 Host Bridge (MCH)"
block|}
block|,
block|{
literal|0x250f
block|,
literal|"82820 AGP Bridge"
block|}
block|,
block|{
literal|0x2520
block|,
literal|"82805AA Memory Translator Hub (MTH)"
block|}
block|,
block|{
literal|0x2521
block|,
literal|"82804AA Memory Repeater Hub for SDRAM (MRH-S)"
block|}
block|,
block|{
literal|0x5200
block|,
literal|"PCI to PCI Bridge"
block|}
block|,
block|{
literal|0x5201
block|,
literal|"Network Controller"
block|}
block|,
block|{
literal|0x7000
block|,
literal|"82371SB PIIX3 PCI-to-ISA Bridge (Triton II)"
block|}
block|,
block|{
literal|0x7010
block|,
literal|"82371SB PIIX3 IDE Interface (Triton II)"
block|}
block|,
block|{
literal|0x7020
block|,
literal|"82371SB PIIX3 USB Host Controller (Triton II)"
block|}
block|,
block|{
literal|0x7030
block|,
literal|"82437VX System Controller"
block|}
block|,
block|{
literal|0x7051
block|,
literal|"PB 642365-003 Intel Business Video Conferencing Card"
block|}
block|,
block|{
literal|0x7100
block|,
literal|"82439TX System Controller (MTXC), part of 430TX chipset"
block|}
block|,
block|{
literal|0x7110
block|,
literal|"82371AB PIIX4 ISA Bridge"
block|}
block|,
block|{
literal|0x7111
block|,
literal|"82371AB PIIX4 IDE Controller"
block|}
block|,
block|{
literal|0x7112
block|,
literal|"82371AB PIIX4 USB Interface"
block|}
block|,
block|{
literal|0x7113
block|,
literal|"82371AB PIIX4 Power Management Controller"
block|}
block|,
block|{
literal|0x7120
block|,
literal|"82810 Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x7121
block|,
literal|"82810 Graphics Device"
block|}
block|,
block|{
literal|0x7122
block|,
literal|"82810-DC100 Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x7123
block|,
literal|"82810-DC100 Graphics Device"
block|}
block|,
block|{
literal|0x7124
block|,
literal|"82810E Host-Hub Interface Bridge / DRAM Ctrlr"
block|}
block|,
block|{
literal|0x7125
block|,
literal|"82810E Graphics Device"
block|}
block|,
block|{
literal|0x7180
block|,
literal|"82443LX/EX (PAC) Host/PCI bridge in 440LX/EX AGP chipset"
block|}
block|,
block|{
literal|0x7181
block|,
literal|"AGP device in 440LX/EX AGP chipset"
block|}
block|,
block|{
literal|0x7190
block|,
literal|"82443BX/ZX 440BX/ZX AGPset Host Bridge"
block|}
block|,
block|{
literal|0x7191
block|,
literal|"82443BX/ZX 440BX/ZX AGPset PCI-to-PCI bridge"
block|}
block|,
block|{
literal|0x7192
block|,
literal|"82443BX/ZX 440BX/ZX chipset Host-to-PCI Bridge"
block|}
block|,
block|{
literal|0x7194
block|,
literal|"82443MX I/O Controller?"
block|}
block|,
block|{
literal|0x7195
block|,
literal|"82443MX? AC97 Audio Controller"
block|}
block|,
block|{
literal|0x7198
block|,
literal|"82443MX PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x7199
block|,
literal|"82443MX EIDE Controller"
block|}
block|,
block|{
literal|0x719a
block|,
literal|"82443MX USB Universal Host Controller"
block|}
block|,
block|{
literal|0x719b
block|,
literal|"82443MX Power Management Controller"
block|}
block|,
block|{
literal|0x71a0
block|,
literal|"82443GX Host-to-PCI Bridge"
block|}
block|,
block|{
literal|0x71a1
block|,
literal|"82443GX PCI-to-PCI Bridge (AGP)"
block|}
block|,
block|{
literal|0x71a2
block|,
literal|"82443GX Host-to-PCI Bridge"
block|}
block|,
block|{
literal|0x7600
block|,
literal|"82372FB PCI to ISA Bridge"
block|}
block|,
block|{
literal|0x7601
block|,
literal|"82372FB EIDE Controller"
block|}
block|,
block|{
literal|0x7602
block|,
literal|"82372FB PCI to USB Universal Host Controller"
block|}
block|,
block|{
literal|0x7800
block|,
literal|"82740 AGP Graphics Accelerator"
block|}
block|,
block|{
literal|0x84c4
block|,
literal|"82450KX/GX 450KX/GX PCI Bridge (Orion)"
block|}
block|,
block|{
literal|0x84c5
block|,
literal|"82453KX/GX 450KX/GX Memory Controller (Orion)"
block|}
block|,
block|{
literal|0x84ca
block|,
literal|"82451NX 450NX PCIset Memory& I/O Controller"
block|}
block|,
block|{
literal|0x84cb
block|,
literal|"82454NX 450NX PCIset PCI Expander Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_8800
index|[]
init|=
block|{
block|{
literal|0x2008
block|,
literal|"video assistant component"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_8e2e
index|[]
init|=
block|{
block|{
literal|0x3000
block|,
literal|"Et32/Px Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_9004
index|[]
init|=
block|{
block|{
literal|0x1078
block|,
literal|"AIC-7810C RAID Coprocessor"
block|}
block|,
block|{
literal|0x1160
block|,
literal|"AIC-1160 Fibre Channel Adapter"
block|}
block|,
block|{
literal|0x2178
block|,
literal|"AIC-7821 SCSI Controller"
block|}
block|,
block|{
literal|0x3860
block|,
literal|"AIC-2930U Ultra SCSI Ctrlr"
block|}
block|,
block|{
literal|0x3b78
block|,
literal|"AHA-4944W/4944UW QuadChannel Fast-Wide/Ultra-Wide Diff. SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5075
block|,
literal|"AIC-755x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5078
block|,
literal|"AIC-7850P Fast/Wide SCSI Controller"
block|}
block|,
block|{
literal|0x5175
block|,
literal|"AIC-755x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5178
block|,
literal|"AIC-7850 FAST-SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5275
block|,
literal|"AIC-755x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5278
block|,
literal|"AIC-7850 Fast SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5375
block|,
literal|"AIC-755x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5378
block|,
literal|"AIC-7850 Fast SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5475
block|,
literal|"AIC-755x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5478
block|,
literal|"AIC-7850 Fast SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5575
block|,
literal|"AVA-2930 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5578
block|,
literal|"AIC-7855 Fast SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5675
block|,
literal|"AIC-755x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5678
block|,
literal|"AIC-7856 Fast SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5775
block|,
literal|"AIC-755x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5778
block|,
literal|"AIC-7850 Fast SCSI Ctrlr"
block|}
block|,
block|{
literal|0x5800
block|,
literal|"AIC-5800 PCI-to-1394 Ctrlr"
block|}
block|,
block|{
literal|0x5900
block|,
literal|"ANA-5910/30/40 ATM155& 25 LAN Controller"
block|}
block|,
block|{
literal|0x5905
block|,
literal|"ANA-5910A/30A/40A ATM Adpater"
block|}
block|,
block|{
literal|0x6038
block|,
literal|"AIC-3860 SCSI Host Adpater"
block|}
block|,
block|{
literal|0x6075
block|,
literal|"AIC-7560? CardBus Ultra SCSI Controller"
block|}
block|,
block|{
literal|0x6078
block|,
literal|"AIC-7860 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x6178
block|,
literal|"AIC-7861 SCSI Controller"
block|}
block|,
block|{
literal|0x6278
block|,
literal|"AIC-7860 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x6378
block|,
literal|"AIC-7860 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x6478
block|,
literal|"AIC-786x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x6578
block|,
literal|"AIC-786x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x6678
block|,
literal|"AIC-786x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x6778
block|,
literal|"AIC-786x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x6915
block|,
literal|"ANA620xx/69011A Fast Ethernet"
block|}
block|,
block|{
literal|0x7078
block|,
literal|"AIC-7870 Fast and Wide SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7178
block|,
literal|"AHA-2940/2940W Fast/Fast-Wide SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7278
block|,
literal|"AHA-3940/3940W Multichannel Fast/Fast-Wide SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7378
block|,
literal|"AHA-3985 4-chan RAID SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7478
block|,
literal|"AHA-2944 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7578
block|,
literal|"AHA-3944/3944W Multichannel Fast/Fast-Wide Diff. SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7678
block|,
literal|"AHA-4944W/4944UW QuadChannel Fast-Wide/Ultra-Wide Diff. SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7778
block|,
literal|"AIC-787x SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7810
block|,
literal|"aic 7810 Memory control IC"
block|}
block|,
block|{
literal|0x7815
block|,
literal|"AIC-7515 RAID + Memory Controller IC"
block|}
block|,
block|{
literal|0x7850
block|,
literal|"aic-7850 Fast/Wide SCSI-2 Controller"
block|}
block|,
block|{
literal|0x7855
block|,
literal|"aha 2930 Single SCSI channel"
block|}
block|,
block|{
literal|0x7860
block|,
literal|"AIC-7860 SCSI Ctrlr"
block|}
block|,
block|{
literal|0x7870
block|,
literal|"aic-7870 SCSI IC"
block|}
block|,
block|{
literal|0x7871
block|,
literal|"aha 2940 SCSI"
block|}
block|,
block|{
literal|0x7872
block|,
literal|"aha 3940 Multiple SCSI channels"
block|}
block|,
block|{
literal|0x7873
block|,
literal|"aha 3980 Multiple SCSI channels"
block|}
block|,
block|{
literal|0x7874
block|,
literal|"aha 2944 Differential SCSI"
block|}
block|,
block|{
literal|0x7880
block|,
literal|"aic7880 Fast 20 SCSI"
block|}
block|,
block|{
literal|0x7890
block|,
literal|"AIC-7890 SCSI controller"
block|}
block|,
block|{
literal|0x7891
block|,
literal|"AIC-789x SCSI controller"
block|}
block|,
block|{
literal|0x7892
block|,
literal|"AIC-789x SCSI controller"
block|}
block|,
block|{
literal|0x7893
block|,
literal|"AIC-789x SCSI controller"
block|}
block|,
block|{
literal|0x7894
block|,
literal|"AIC-789x SCSI controller"
block|}
block|,
block|{
literal|0x7895
block|,
literal|"AIC-7895 Ultra-Wide SCSI Ctrlr on AHA-2940 AHA-394x"
block|}
block|,
block|{
literal|0x7896
block|,
literal|"AIC-789x SCSI controller"
block|}
block|,
block|{
literal|0x7897
block|,
literal|"AIC-789x SCSI controller"
block|}
block|,
block|{
literal|0x8078
block|,
literal|"AIC-7880 Ultra Wide SCSI"
block|}
block|,
block|{
literal|0x8178
block|,
literal|"AHA-2940U/2940UW Ultra/Ultra-Wide SCSI Ctrlr"
block|}
block|,
block|{
literal|0x8278
block|,
literal|"AHA-3940Uxx AHA-3940U/3940UW/3940UWD SCSI Ctrlr"
block|}
block|,
block|{
literal|0x8378
block|,
literal|"AIC-7883U SCSI Controller"
block|}
block|,
block|{
literal|0x8478
block|,
literal|"AHA-2944UW Ultra-Wide Diff. SCSI Ctrlr"
block|}
block|,
block|{
literal|0x8578
block|,
literal|"AHA-3944U/3944UWD Fast-Wide/Ultra-Wide Diff. SCSI Ctrlr"
block|}
block|,
block|{
literal|0x8678
block|,
literal|"AHA-4944UW QuadChannel Ultra-Wide Diff. SCSI Ctrlr"
block|}
block|,
block|{
literal|0x8778
block|,
literal|"AIC-788x Ultra-Wide SCSI Ctrlr"
block|}
block|,
block|{
literal|0x8878
block|,
literal|"AIC-7888? Ultra Wide SCSI Controller"
block|}
block|,
block|{
literal|0x8b78
block|,
literal|"ABA-1030"
block|}
block|,
block|{
literal|0xec78
block|,
literal|"AHA-4944W/4944UW QuadChannel Fast-Wide/Ultra-Wide Diff. SCSI Ctrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_9005
index|[]
init|=
block|{
block|{
literal|0x0010
block|,
literal|"AHA-2940U2W/U2B,2950U2W Ultra2 SCSI"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"AHA-2930U2 Ultra2 SCSI Host Adapter"
block|}
block|,
block|{
literal|0x0013
block|,
literal|"AIC-7890/1 SCSI Controller"
block|}
block|,
block|{
literal|0x001f
block|,
literal|"AIC-7890/1 Ultra2-Wide SCSI controller"
block|}
block|,
block|{
literal|0x0020
block|,
literal|"AIC-789x SCSI Controller"
block|}
block|,
block|{
literal|0x002f
block|,
literal|"AIC-789x SCSI Controller"
block|}
block|,
block|{
literal|0x0030
block|,
literal|"AIC-789x SCSI Controller"
block|}
block|,
block|{
literal|0x003f
block|,
literal|"AIC-789x SCSI Controller"
block|}
block|,
block|{
literal|0x0050
block|,
literal|"AHA-3940U2x/3950U2x Ultra2 SCSI Adapter"
block|}
block|,
block|{
literal|0x0051
block|,
literal|"AHA-3950U2x Ultra2 SCSI Adapter"
block|}
block|,
block|{
literal|0x0053
block|,
literal|"AIC-7896 SCSI Controller"
block|}
block|,
block|{
literal|0x005f
block|,
literal|"AIC-7896/7 Ultra2 SCSI Controller"
block|}
block|,
block|{
literal|0x0080
block|,
literal|"AIC-7892A Ultra160/m PCI SCSI Controller"
block|}
block|,
block|{
literal|0x0081
block|,
literal|"AIC-7892B Ultra160 SCSI Controller"
block|}
block|,
block|{
literal|0x0083
block|,
literal|"AIC-7892D Ultra160 SCSI Controller"
block|}
block|,
block|{
literal|0x008f
block|,
literal|"AIC-7892 Ultra160 SCSI Controller"
block|}
block|,
block|{
literal|0x00c0
block|,
literal|"AIC-7899A Ultra160 SCSI Controller"
block|}
block|,
block|{
literal|0x00c1
block|,
literal|"AIC-7899B Ultra160 SCSI Controller"
block|}
block|,
block|{
literal|0x00c3
block|,
literal|"AIC-7899D Ultra160 SCSI Controller"
block|}
block|,
block|{
literal|0x00cf
block|,
literal|"AIC-7899 Ultra160 SCSI Controller"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_907f
index|[]
init|=
block|{
block|{
literal|0x2015
block|,
literal|"IDE-2015PL EIDE Ctrlr"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_9412
index|[]
init|=
block|{
block|{
literal|0x6565
block|,
literal|"HT6565 IDE Controller?"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_e000
index|[]
init|=
block|{
block|{
literal|0xe000
block|,
literal|"W89C940 Ethernet Adapter"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_e159
index|[]
init|=
block|{
block|{
literal|0x0001
block|,
literal|"Tiger 300/320 PCI interface"
block|}
block|,
block|{
literal|0x0600
block|,
literal|"Tiger 600 PCI-to-PCI Bridge"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_edd8
index|[]
init|=
block|{
block|{
literal|0xa091
block|,
literal|"ARK1000PV Stingray GUI Accelerator"
block|}
block|,
block|{
literal|0xa099
block|,
literal|"ARK2000PV Stingray GUI Accelerator"
block|}
block|,
block|{
literal|0xa0a1
block|,
literal|"ARK2000MT Stingray 64"
block|}
block|,
block|{
literal|0xa0a9
block|,
literal|"ARK2000MI Quadro645"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_fffe
index|[]
init|=
block|{
block|{
literal|0x0710
block|,
literal|"Virtual SVGA"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device_information
name|pci_device_ffff
index|[]
init|=
block|{
block|{
literal|0x0140
block|,
literal|"BAD ! BAD Buslogic BT-946C SCSI?"
block|}
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_vendor_information
name|pci_vendor_information
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"Gammagraphx, Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x001a
block|,
literal|"Ascend Communications, Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x0033
block|,
literal|"Paradyne Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x003d
block|,
literal|"Lockheed Martin Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x0070
block|,
literal|"Hauppauge Computer Works Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x0100
block|,
literal|"Ncipher Corp. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x0123
block|,
literal|"General Dynamics"
block|,
literal|0
block|}
block|,
block|{
literal|0x0675
block|,
literal|"Dynalink"
block|,
name|pci_device_0675
block|}
block|,
block|{
literal|0x0a89
block|,
literal|"BREA Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x0e11
block|,
literal|"Compaq Computer Corp."
block|,
name|pci_device_0e11
block|}
block|,
block|{
literal|0x1000
block|,
literal|"LSI Logic"
block|,
name|pci_device_1000
block|}
block|,
block|{
literal|0x1001
block|,
literal|"Kolter Electronic - Germany"
block|,
name|pci_device_1001
block|}
block|,
block|{
literal|0x1002
block|,
literal|"ATI Technologies"
block|,
name|pci_device_1002
block|}
block|,
block|{
literal|0x1003
block|,
literal|"ULSI"
block|,
name|pci_device_1003
block|}
block|,
block|{
literal|0x1004
block|,
literal|"VLSI Technology"
block|,
name|pci_device_1004
block|}
block|,
block|{
literal|0x1005
block|,
literal|"Avance Logic Inc."
block|,
name|pci_device_1005
block|}
block|,
block|{
literal|0x1006
block|,
literal|"Reply Group"
block|,
literal|0
block|}
block|,
block|{
literal|0x1007
block|,
literal|"Netframe Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1008
block|,
literal|"Epson"
block|,
literal|0
block|}
block|,
block|{
literal|0x100a
block|,
literal|"Phoenix Technologies Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x100b
block|,
literal|"National Semiconductor"
block|,
name|pci_device_100b
block|}
block|,
block|{
literal|0x100c
block|,
literal|"Tseng Labs"
block|,
name|pci_device_100c
block|}
block|,
block|{
literal|0x100d
block|,
literal|"AST Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x100e
block|,
literal|"Weitek"
block|,
name|pci_device_100e
block|}
block|,
block|{
literal|0x1010
block|,
literal|"Video Logic Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1011
block|,
literal|"Digital Equipment Corporation"
block|,
name|pci_device_1011
block|}
block|,
block|{
literal|0x1012
block|,
literal|"Micronics Computers Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1013
block|,
literal|"Cirrus Logic"
block|,
name|pci_device_1013
block|}
block|,
block|{
literal|0x1014
block|,
literal|"IBM"
block|,
name|pci_device_1014
block|}
block|,
block|{
literal|0x1015
block|,
literal|"LSI Logic Corp of Canada"
block|,
literal|0
block|}
block|,
block|{
literal|0x1016
block|,
literal|"Fujitsu ICL Computers"
block|,
literal|0
block|}
block|,
block|{
literal|0x1017
block|,
literal|"Spea Software AG"
block|,
name|pci_device_1017
block|}
block|,
block|{
literal|0x1018
block|,
literal|"Unisys Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1019
block|,
literal|"Elitegroup Computer Sys"
block|,
literal|0
block|}
block|,
block|{
literal|0x101a
block|,
literal|"NCR/AT&T GIS"
block|,
name|pci_device_101a
block|}
block|,
block|{
literal|0x101b
block|,
literal|"Vitesse Semiconductor"
block|,
literal|0
block|}
block|,
block|{
literal|0x101c
block|,
literal|"Western Digital"
block|,
name|pci_device_101c
block|}
block|,
block|{
literal|0x101e
block|,
literal|"American Megatrends Inc."
block|,
name|pci_device_101e
block|}
block|,
block|{
literal|0x101f
block|,
literal|"PictureTel Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1020
block|,
literal|"Hitachi Computer Electronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x1021
block|,
literal|"Oki Electric Industry"
block|,
literal|0
block|}
block|,
block|{
literal|0x1022
block|,
literal|"Advanced Micro Devices"
block|,
name|pci_device_1022
block|}
block|,
block|{
literal|0x1023
block|,
literal|"Trident Microsystems"
block|,
name|pci_device_1023
block|}
block|,
block|{
literal|0x1024
block|,
literal|"Zenith Data Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1025
block|,
literal|"Acer Incorporated"
block|,
name|pci_device_1025
block|}
block|,
block|{
literal|0x1028
block|,
literal|"Dell Computer Corporation"
block|,
name|pci_device_1028
block|}
block|,
block|{
literal|0x1029
block|,
literal|"Siemens Nixdorf AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x102a
block|,
literal|"LSI Logic Headland Div"
block|,
name|pci_device_102a
block|}
block|,
block|{
literal|0x102b
block|,
literal|"Matrox"
block|,
name|pci_device_102b
block|}
block|,
block|{
literal|0x102c
block|,
literal|"Chips And Technologies"
block|,
name|pci_device_102c
block|}
block|,
block|{
literal|0x102d
block|,
literal|"Wyse Technologies"
block|,
name|pci_device_102d
block|}
block|,
block|{
literal|0x102e
block|,
literal|"Olivetti Advanced Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x102f
block|,
literal|"Toshiba America"
block|,
name|pci_device_102f
block|}
block|,
block|{
literal|0x1030
block|,
literal|"TMC Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x1031
block|,
literal|"miro Computer Products AG"
block|,
name|pci_device_1031
block|}
block|,
block|{
literal|0x1032
block|,
literal|"Compaq"
block|,
literal|0
block|}
block|,
block|{
literal|0x1033
block|,
literal|"NEC Corporation"
block|,
name|pci_device_1033
block|}
block|,
block|{
literal|0x1034
block|,
literal|"Burndy Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1035
block|,
literal|"Computer&Communication Research Lab"
block|,
literal|0
block|}
block|,
block|{
literal|0x1036
block|,
literal|"Future Domain"
block|,
name|pci_device_1036
block|}
block|,
block|{
literal|0x1037
block|,
literal|"Hitachi Micro Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1038
block|,
literal|"AMP Incorporated"
block|,
literal|0
block|}
block|,
block|{
literal|0x1039
block|,
literal|"Silicon Integrated System"
block|,
name|pci_device_1039
block|}
block|,
block|{
literal|0x103a
block|,
literal|"Seiko Epson Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x103b
block|,
literal|"Tatung Corp. Of America"
block|,
literal|0
block|}
block|,
block|{
literal|0x103c
block|,
literal|"Hewlett-Packard Company"
block|,
name|pci_device_103c
block|}
block|,
block|{
literal|0x103e
block|,
literal|"Solliday Engineering"
block|,
literal|0
block|}
block|,
block|{
literal|0x103f
block|,
literal|"Logic Modeling"
block|,
literal|0
block|}
block|,
block|{
literal|0x1040
block|,
literal|"Kubota Pacific Computer Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1041
block|,
literal|"Computrend"
block|,
literal|0
block|}
block|,
block|{
literal|0x1042
block|,
literal|"PC Technology"
block|,
name|pci_device_1042
block|}
block|,
block|{
literal|0x1043
block|,
literal|"Asustek Computer Inc."
block|,
name|pci_device_1043
block|}
block|,
block|{
literal|0x1044
block|,
literal|"Distributed Processing Tech"
block|,
name|pci_device_1044
block|}
block|,
block|{
literal|0x1045
block|,
literal|"OPTi Inc."
block|,
name|pci_device_1045
block|}
block|,
block|{
literal|0x1046
block|,
literal|"IPC Corporation LTD"
block|,
literal|0
block|}
block|,
block|{
literal|0x1047
block|,
literal|"Genoa Systems Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1048
block|,
literal|"ELSA AG"
block|,
name|pci_device_1048
block|}
block|,
block|{
literal|0x1049
block|,
literal|"Fountain Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x104a
block|,
literal|"ST Microelectronics"
block|,
name|pci_device_104a
block|}
block|,
block|{
literal|0x104b
block|,
literal|"Mylex Corporation"
block|,
name|pci_device_104b
block|}
block|,
block|{
literal|0x104c
block|,
literal|"Texas Instruments"
block|,
name|pci_device_104c
block|}
block|,
block|{
literal|0x104d
block|,
literal|"Sony Corporation"
block|,
name|pci_device_104d
block|}
block|,
block|{
literal|0x104e
block|,
literal|"Oak Technology"
block|,
name|pci_device_104e
block|}
block|,
block|{
literal|0x104f
block|,
literal|"Co-Time Computer Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1050
block|,
literal|"Winbond Electronics Corp."
block|,
name|pci_device_1050
block|}
block|,
block|{
literal|0x1051
block|,
literal|"Anigma Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1052
block|,
literal|"Young Micro Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1054
block|,
literal|"Hitachi LTD"
block|,
name|pci_device_1054
block|}
block|,
block|{
literal|0x1055
block|,
literal|"EFAR Microsystems"
block|,
name|pci_device_1055
block|}
block|,
block|{
literal|0x1056
block|,
literal|"ICL"
block|,
literal|0
block|}
block|,
block|{
literal|0x1057
block|,
literal|"Motorola"
block|,
name|pci_device_1057
block|}
block|,
block|{
literal|0x1058
block|,
literal|"Electronics& Telecommunication Res"
block|,
literal|0
block|}
block|,
block|{
literal|0x1059
block|,
literal|"Teknor Microsystems"
block|,
literal|0
block|}
block|,
block|{
literal|0x105a
block|,
literal|"Promise Technology"
block|,
name|pci_device_105a
block|}
block|,
block|{
literal|0x105b
block|,
literal|"Foxconn International"
block|,
literal|0
block|}
block|,
block|{
literal|0x105c
block|,
literal|"Wipro Infotech Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x105d
block|,
literal|"Number Nine Visual Technology"
block|,
name|pci_device_105d
block|}
block|,
block|{
literal|0x105e
block|,
literal|"Vtech Engineering Canada Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x105f
block|,
literal|"Infotronic America Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1060
block|,
literal|"United Microelectronics"
block|,
name|pci_device_1060
block|}
block|,
block|{
literal|0x1061
block|,
literal|"8x8 Inc."
block|,
name|pci_device_1061
block|}
block|,
block|{
literal|0x1062
block|,
literal|"Maspar Computer Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1063
block|,
literal|"Ocean Office Automation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1064
block|,
literal|"Alcatel Cit"
block|,
literal|0
block|}
block|,
block|{
literal|0x1065
block|,
literal|"Texas Microsystems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1066
block|,
literal|"Picopower Technology"
block|,
name|pci_device_1066
block|}
block|,
block|{
literal|0x1067
block|,
literal|"Mitsubishi Electronics"
block|,
name|pci_device_1067
block|}
block|,
block|{
literal|0x1068
block|,
literal|"Diversified Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1069
block|,
literal|"Mylex Corporation"
block|,
name|pci_device_1069
block|}
block|,
block|{
literal|0x106a
block|,
literal|"Aten Research Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x106b
block|,
literal|"Apple Computer Inc."
block|,
name|pci_device_106b
block|}
block|,
block|{
literal|0x106c
block|,
literal|"Hyundai Electronics America"
block|,
name|pci_device_106c
block|}
block|,
block|{
literal|0x106d
block|,
literal|"Sequent"
block|,
literal|0
block|}
block|,
block|{
literal|0x106e
block|,
literal|"DFI Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x106f
block|,
literal|"City Gate Development LTD"
block|,
literal|0
block|}
block|,
block|{
literal|0x1070
block|,
literal|"Daewoo Telecom Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1071
block|,
literal|"Mitac"
block|,
literal|0
block|}
block|,
block|{
literal|0x1072
block|,
literal|"GIT Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1073
block|,
literal|"Yamaha Corporation"
block|,
name|pci_device_1073
block|}
block|,
block|{
literal|0x1074
block|,
literal|"Nexgen Microsysteme"
block|,
name|pci_device_1074
block|}
block|,
block|{
literal|0x1075
block|,
literal|"Advanced Integration Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x1076
block|,
literal|"Chaintech Computer Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1077
block|,
literal|"Q Logic"
block|,
name|pci_device_1077
block|}
block|,
block|{
literal|0x1078
block|,
literal|"Cyrix Corporation"
block|,
name|pci_device_1078
block|}
block|,
block|{
literal|0x1079
block|,
literal|"I-Bus"
block|,
literal|0
block|}
block|,
block|{
literal|0x107a
block|,
literal|"Networth"
block|,
literal|0
block|}
block|,
block|{
literal|0x107b
block|,
literal|"Gateway 2000"
block|,
literal|0
block|}
block|,
block|{
literal|0x107c
block|,
literal|"Goldstar Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x107d
block|,
literal|"Leadtek Research"
block|,
name|pci_device_107d
block|}
block|,
block|{
literal|0x107e
block|,
literal|"Interphase Corporation"
block|,
name|pci_device_107e
block|}
block|,
block|{
literal|0x107f
block|,
literal|"Data Technology Corporation"
block|,
name|pci_device_107f
block|}
block|,
block|{
literal|0x1080
block|,
literal|"Contaq Microsystems"
block|,
name|pci_device_1080
block|}
block|,
block|{
literal|0x1081
block|,
literal|"Supermac Technology Inc."
block|,
name|pci_device_1081
block|}
block|,
block|{
literal|0x1082
block|,
literal|"EFA Corporation Of America"
block|,
literal|0
block|}
block|,
block|{
literal|0x1083
block|,
literal|"Forex Computer Corporation"
block|,
name|pci_device_1083
block|}
block|,
block|{
literal|0x1084
block|,
literal|"Parador"
block|,
literal|0
block|}
block|,
block|{
literal|0x1085
block|,
literal|"Tulip Computers Int'l BV"
block|,
literal|0
block|}
block|,
block|{
literal|0x1086
block|,
literal|"J. Bond Computer Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1087
block|,
literal|"Cache Computer"
block|,
literal|0
block|}
block|,
block|{
literal|0x1088
block|,
literal|"Microcomputer Systems (M) Son"
block|,
literal|0
block|}
block|,
block|{
literal|0x1089
block|,
literal|"Data General Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x108a
block|,
literal|"Bit3 Computer"
block|,
name|pci_device_108a
block|}
block|,
block|{
literal|0x108c
block|,
literal|"Elonex PLC c/o Oakleigh Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x108d
block|,
literal|"Olicom"
block|,
name|pci_device_108d
block|}
block|,
block|{
literal|0x108e
block|,
literal|"Sun Microsystems"
block|,
name|pci_device_108e
block|}
block|,
block|{
literal|0x108f
block|,
literal|"Systemsoft Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1090
block|,
literal|"Encore Computer Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1091
block|,
literal|"Intergraph Corporation"
block|,
name|pci_device_1091
block|}
block|,
block|{
literal|0x1092
block|,
literal|"Diamond Computer Systems"
block|,
name|pci_device_1092
block|}
block|,
block|{
literal|0x1093
block|,
literal|"National Instruments"
block|,
name|pci_device_1093
block|}
block|,
block|{
literal|0x1094
block|,
literal|"First Int'l Computers"
block|,
literal|0
block|}
block|,
block|{
literal|0x1095
block|,
literal|"CMD Technology Inc."
block|,
name|pci_device_1095
block|}
block|,
block|{
literal|0x1096
block|,
literal|"Alacron"
block|,
literal|0
block|}
block|,
block|{
literal|0x1097
block|,
literal|"Appian Graphics"
block|,
name|pci_device_1097
block|}
block|,
block|{
literal|0x1098
block|,
literal|"Quantum Designs Ltd."
block|,
name|pci_device_1098
block|}
block|,
block|{
literal|0x1099
block|,
literal|"Samsung Electronics Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x109a
block|,
literal|"Packard Bell"
block|,
literal|0
block|}
block|,
block|{
literal|0x109b
block|,
literal|"Gemlight Computer Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x109c
block|,
literal|"Megachips Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x109d
block|,
literal|"Zida Technologies Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x109e
block|,
literal|"Brooktree Corporation"
block|,
name|pci_device_109e
block|}
block|,
block|{
literal|0x109f
block|,
literal|"Trigem Computer Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10a0
block|,
literal|"Meidensha Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10a1
block|,
literal|"Juko Electronics Inc. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x10a2
block|,
literal|"Quantum Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10a3
block|,
literal|"Everex Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10a4
block|,
literal|"Globe Manufacturing Sales"
block|,
literal|0
block|}
block|,
block|{
literal|0x10a5
block|,
literal|"Racal Interlan"
block|,
literal|0
block|}
block|,
block|{
literal|0x10a6
block|,
literal|"Informtech Industrial Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x10a7
block|,
literal|"Benchmarq Microelectronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x10a8
block|,
literal|"Sierra Semiconductor"
block|,
name|pci_device_10a8
block|}
block|,
block|{
literal|0x10a9
block|,
literal|"Silicon Graphics"
block|,
name|pci_device_10a9
block|}
block|,
block|{
literal|0x10aa
block|,
literal|"ACC Microelectronics"
block|,
name|pci_device_10aa
block|}
block|,
block|{
literal|0x10ab
block|,
literal|"Digicom"
block|,
literal|0
block|}
block|,
block|{
literal|0x10ac
block|,
literal|"Honeywell IASD"
block|,
literal|0
block|}
block|,
block|{
literal|0x10ad
block|,
literal|"Symphony Labs"
block|,
name|pci_device_10ad
block|}
block|,
block|{
literal|0x10ae
block|,
literal|"Cornerstone Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x10af
block|,
literal|"Micro Computer Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10b0
block|,
literal|"Cardexpert Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x10b1
block|,
literal|"Cabletron Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10b2
block|,
literal|"Raytheon Company"
block|,
literal|0
block|}
block|,
block|{
literal|0x10b3
block|,
literal|"Databook Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10b4
block|,
literal|"STB Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x10b5
block|,
literal|"PLX Technology"
block|,
name|pci_device_10b5
block|}
block|,
block|{
literal|0x10b6
block|,
literal|"Madge Networks"
block|,
name|pci_device_10b6
block|}
block|,
block|{
literal|0x10b7
block|,
literal|"3Com Corporation"
block|,
name|pci_device_10b7
block|}
block|,
block|{
literal|0x10b8
block|,
literal|"Standard Microsystems Corporation"
block|,
name|pci_device_10b8
block|}
block|,
block|{
literal|0x10b9
block|,
literal|"Acer Labs Inc."
block|,
name|pci_device_10b9
block|}
block|,
block|{
literal|0x10ba
block|,
literal|"Mitsubishi Electronics Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x10bb
block|,
literal|"Dapha Electronics Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10bc
block|,
literal|"Advanced Logic Research Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10bd
block|,
literal|"Surecom Technology"
block|,
name|pci_device_10bd
block|}
block|,
block|{
literal|0x10be
block|,
literal|"Tsenglabs International Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x10bf
block|,
literal|"MOST Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x10c0
block|,
literal|"Boca Research Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10c1
block|,
literal|"ICM Corp. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x10c2
block|,
literal|"Auspex Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10c3
block|,
literal|"Samsung Semiconductors"
block|,
literal|0
block|}
block|,
block|{
literal|0x10c4
block|,
literal|"Award Software Int'l Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10c5
block|,
literal|"Xerox Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10c6
block|,
literal|"Rambus Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10c7
block|,
literal|"Media Vision"
block|,
literal|0
block|}
block|,
block|{
literal|0x10c8
block|,
literal|"Neomagic Corporation"
block|,
name|pci_device_10c8
block|}
block|,
block|{
literal|0x10c9
block|,
literal|"Dataexpert Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10ca
block|,
literal|"Fujitsu"
block|,
literal|0
block|}
block|,
block|{
literal|0x10cb
block|,
literal|"Omron Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10cc
block|,
literal|"Mentor Arc Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10cd
block|,
literal|"Advanced System Products"
block|,
name|pci_device_10cd
block|}
block|,
block|{
literal|0x10ce
block|,
literal|"Radius Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10cf
block|,
literal|"Citicorp TTI"
block|,
name|pci_device_10cf
block|}
block|,
block|{
literal|0x10d0
block|,
literal|"Fujitsu Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x10d1
block|,
literal|"Future+ Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x10d2
block|,
literal|"Molex Incorporated"
block|,
literal|0
block|}
block|,
block|{
literal|0x10d3
block|,
literal|"Jabil Circuit Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10d4
block|,
literal|"Hualon Microelectronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x10d5
block|,
literal|"Autologic Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10d6
block|,
literal|"Cetia"
block|,
literal|0
block|}
block|,
block|{
literal|0x10d7
block|,
literal|"BCM Advanced Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x10d8
block|,
literal|"Advanced Peripherals Labs"
block|,
literal|0
block|}
block|,
block|{
literal|0x10d9
block|,
literal|"Macronix International Co. Ltd."
block|,
name|pci_device_10d9
block|}
block|,
block|{
literal|0x10da
block|,
literal|"Thomas-Conrad Corporation"
block|,
name|pci_device_10da
block|}
block|,
block|{
literal|0x10db
block|,
literal|"Rohm Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x10dc
block|,
literal|"CERN-European Lab. for Particle Physics"
block|,
name|pci_device_10dc
block|}
block|,
block|{
literal|0x10dd
block|,
literal|"Evans& Sutherland"
block|,
name|pci_device_10dd
block|}
block|,
block|{
literal|0x10de
block|,
literal|"Nvidia Corporation"
block|,
name|pci_device_10de
block|}
block|,
block|{
literal|0x10df
block|,
literal|"Emulex Corporation"
block|,
name|pci_device_10df
block|}
block|,
block|{
literal|0x10e0
block|,
literal|"Integrated Micro Solutions"
block|,
name|pci_device_10e0
block|}
block|,
block|{
literal|0x10e1
block|,
literal|"Tekram Technology Corp. Ltd."
block|,
name|pci_device_10e1
block|}
block|,
block|{
literal|0x10e2
block|,
literal|"Aptix Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10e3
block|,
literal|"Tundra Semiconductor Corp."
block|,
name|pci_device_10e3
block|}
block|,
block|{
literal|0x10e4
block|,
literal|"Tandem Computers"
block|,
literal|0
block|}
block|,
block|{
literal|0x10e5
block|,
literal|"Micro Industries Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x10e6
block|,
literal|"Gainbery Computer Products Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10e7
block|,
literal|"Vadem"
block|,
literal|0
block|}
block|,
block|{
literal|0x10e8
block|,
literal|"Applied Micro Circuits Corp."
block|,
name|pci_device_10e8
block|}
block|,
block|{
literal|0x10e9
block|,
literal|"Alps Electronic Corp. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x10ea
block|,
literal|"Integraphics Systems"
block|,
name|pci_device_10ea
block|}
block|,
block|{
literal|0x10eb
block|,
literal|"Artist Graphics"
block|,
name|pci_device_10eb
block|}
block|,
block|{
literal|0x10ec
block|,
literal|"Realtek Semiconductor"
block|,
name|pci_device_10ec
block|}
block|,
block|{
literal|0x10ed
block|,
literal|"Ascii Corporation"
block|,
name|pci_device_10ed
block|}
block|,
block|{
literal|0x10ee
block|,
literal|"Xilinx Corporation"
block|,
name|pci_device_10ee
block|}
block|,
block|{
literal|0x10ef
block|,
literal|"Racore Computer Products"
block|,
name|pci_device_10ef
block|}
block|,
block|{
literal|0x10f0
block|,
literal|"Peritek Corporation"
block|,
name|pci_device_10f0
block|}
block|,
block|{
literal|0x10f1
block|,
literal|"Tyan Computer"
block|,
name|pci_device_10f1
block|}
block|,
block|{
literal|0x10f2
block|,
literal|"Achme Computer Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10f3
block|,
literal|"Alaris Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10f4
block|,
literal|"S-Mos Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x10f5
block|,
literal|"NKK Corporation"
block|,
name|pci_device_10f5
block|}
block|,
block|{
literal|0x10f6
block|,
literal|"Creative Electronic Systems SA"
block|,
literal|0
block|}
block|,
block|{
literal|0x10f7
block|,
literal|"Matsushita Electric Industrial Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x10f8
block|,
literal|"Altos India Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x10f9
block|,
literal|"PC Direct"
block|,
literal|0
block|}
block|,
block|{
literal|0x10fa
block|,
literal|"Truevision"
block|,
name|pci_device_10fa
block|}
block|,
block|{
literal|0x10fb
block|,
literal|"Thesys Microelectronic's"
block|,
literal|0
block|}
block|,
block|{
literal|0x10fc
block|,
literal|"I-O Data Device Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x10fd
block|,
literal|"Soyo Technology Corp. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x10fe
block|,
literal|"Fast Electronic GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x10ff
block|,
literal|"Ncube"
block|,
literal|0
block|}
block|,
block|{
literal|0x1100
block|,
literal|"Jazz Multimedia"
block|,
literal|0
block|}
block|,
block|{
literal|0x1101
block|,
literal|"Initio Corporation"
block|,
name|pci_device_1101
block|}
block|,
block|{
literal|0x1102
block|,
literal|"Creative Labs"
block|,
name|pci_device_1102
block|}
block|,
block|{
literal|0x1103
block|,
literal|"HighPoint Technologies Inc."
block|,
name|pci_device_1103
block|}
block|,
block|{
literal|0x1104
block|,
literal|"Rasterops"
block|,
literal|0
block|}
block|,
block|{
literal|0x1105
block|,
literal|"Sigma Designs Inc."
block|,
name|pci_device_1105
block|}
block|,
block|{
literal|0x1106
block|,
literal|"VIA Technologies Inc"
block|,
name|pci_device_1106
block|}
block|,
block|{
literal|0x1107
block|,
literal|"Stratus Computer"
block|,
name|pci_device_1107
block|}
block|,
block|{
literal|0x1108
block|,
literal|"Proteon Inc."
block|,
name|pci_device_1108
block|}
block|,
block|{
literal|0x1109
block|,
literal|"Cogent Data Technologies"
block|,
name|pci_device_1109
block|}
block|,
block|{
literal|0x110a
block|,
literal|"Infineon Technologies"
block|,
name|pci_device_110a
block|}
block|,
block|{
literal|0x110b
block|,
literal|"Chromatic Research Inc"
block|,
name|pci_device_110b
block|}
block|,
block|{
literal|0x110c
block|,
literal|"Mini-Max Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x110d
block|,
literal|"ZNYX Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x110e
block|,
literal|"CPU Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x110f
block|,
literal|"Ross Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1110
block|,
literal|"Powerhouse Systems"
block|,
name|pci_device_1110
block|}
block|,
block|{
literal|0x1111
block|,
literal|"Santa Cruz Operation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1112
block|,
literal|"Osicom Technologies Inc."
block|,
name|pci_device_1112
block|}
block|,
block|{
literal|0x1113
block|,
literal|"Accton Technology Corporation"
block|,
name|pci_device_1113
block|}
block|,
block|{
literal|0x1114
block|,
literal|"Atmel Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1115
block|,
literal|"Dupont Pixel Systems Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1116
block|,
literal|"Data Translation"
block|,
name|pci_device_1116
block|}
block|,
block|{
literal|0x1117
block|,
literal|"Datacube Inc."
block|,
name|pci_device_1117
block|}
block|,
block|{
literal|0x1118
block|,
literal|"Berg Electronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x1119
block|,
literal|"Vortex Computersysteme GmbH"
block|,
name|pci_device_1119
block|}
block|,
block|{
literal|0x111a
block|,
literal|"Efficent Networks"
block|,
name|pci_device_111a
block|}
block|,
block|{
literal|0x111b
block|,
literal|"Teledyne Electronic Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x111c
block|,
literal|"Tricord Systems Inc."
block|,
name|pci_device_111c
block|}
block|,
block|{
literal|0x111d
block|,
literal|"Integrated Device Technology Inc."
block|,
name|pci_device_111d
block|}
block|,
block|{
literal|0x111e
block|,
literal|"Eldec Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x111f
block|,
literal|"Precision Digital Images"
block|,
name|pci_device_111f
block|}
block|,
block|{
literal|0x1120
block|,
literal|"EMC Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1121
block|,
literal|"Zilog"
block|,
literal|0
block|}
block|,
block|{
literal|0x1122
block|,
literal|"Multi-Tech Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1123
block|,
literal|"Excellent Design Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1124
block|,
literal|"Leutron Vision AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x1125
block|,
literal|"Eurocore/Vigra"
block|,
literal|0
block|}
block|,
block|{
literal|0x1126
block|,
literal|"Vigra"
block|,
literal|0
block|}
block|,
block|{
literal|0x1127
block|,
literal|"FORE Systems"
block|,
name|pci_device_1127
block|}
block|,
block|{
literal|0x1129
block|,
literal|"Firmworks"
block|,
literal|0
block|}
block|,
block|{
literal|0x112a
block|,
literal|"Hermes Electronics Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x112b
block|,
literal|"Linotype - Hell AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x112c
block|,
literal|"Zenith Data Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x112d
block|,
literal|"Ravicad"
block|,
literal|0
block|}
block|,
block|{
literal|0x112e
block|,
literal|"Infomedia"
block|,
name|pci_device_112e
block|}
block|,
block|{
literal|0x112f
block|,
literal|"Imaging Technology"
block|,
name|pci_device_112f
block|}
block|,
block|{
literal|0x1130
block|,
literal|"Computervision"
block|,
literal|0
block|}
block|,
block|{
literal|0x1131
block|,
literal|"Philips Semiconductors"
block|,
name|pci_device_1131
block|}
block|,
block|{
literal|0x1132
block|,
literal|"Mitel Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1133
block|,
literal|"Eicon Technology Corporation"
block|,
name|pci_device_1133
block|}
block|,
block|{
literal|0x1134
block|,
literal|"Mercury Computer Systems Inc."
block|,
name|pci_device_1134
block|}
block|,
block|{
literal|0x1135
block|,
literal|"Fuji Xerox Co Ltd"
block|,
name|pci_device_1135
block|}
block|,
block|{
literal|0x1136
block|,
literal|"Momentum Data Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1137
block|,
literal|"Cisco Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1138
block|,
literal|"Ziatech Corporation"
block|,
name|pci_device_1138
block|}
block|,
block|{
literal|0x1139
block|,
literal|"Dynamic Pictures Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x113a
block|,
literal|"FWB  Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x113b
block|,
literal|"Network Computing Devices"
block|,
literal|0
block|}
block|,
block|{
literal|0x113c
block|,
literal|"Cyclone Microsystems"
block|,
name|pci_device_113c
block|}
block|,
block|{
literal|0x113d
block|,
literal|"Leading Edge Products Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x113e
block|,
literal|"Sanyo Electric Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x113f
block|,
literal|"Equinox Systems"
block|,
name|pci_device_113f
block|}
block|,
block|{
literal|0x1140
block|,
literal|"Intervoice Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1141
block|,
literal|"Crest Microsystem Inc"
block|,
name|pci_device_1141
block|}
block|,
block|{
literal|0x1142
block|,
literal|"Alliance Semiconductor CA - USA"
block|,
name|pci_device_1142
block|}
block|,
block|{
literal|0x1143
block|,
literal|"Netpower Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1144
block|,
literal|"Cincinnati Milacron"
block|,
name|pci_device_1144
block|}
block|,
block|{
literal|0x1145
block|,
literal|"Workbit Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1146
block|,
literal|"Force Computers"
block|,
literal|0
block|}
block|,
block|{
literal|0x1147
block|,
literal|"Interface Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1148
block|,
literal|"Schneider& Koch"
block|,
name|pci_device_1148
block|}
block|,
block|{
literal|0x1149
block|,
literal|"Win System Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x114a
block|,
literal|"VMIC"
block|,
name|pci_device_114a
block|}
block|,
block|{
literal|0x114b
block|,
literal|"Canopus Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x114c
block|,
literal|"Annabooks"
block|,
literal|0
block|}
block|,
block|{
literal|0x114d
block|,
literal|"IC Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x114e
block|,
literal|"Nikon Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x114f
block|,
literal|"Digi International"
block|,
name|pci_device_114f
block|}
block|,
block|{
literal|0x1150
block|,
literal|"Thinking Machines Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1151
block|,
literal|"JAE Electronics Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1152
block|,
literal|"Megatek"
block|,
literal|0
block|}
block|,
block|{
literal|0x1153
block|,
literal|"Land Win Electronic Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1154
block|,
literal|"Melco Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1155
block|,
literal|"Pine Technology Ltd"
block|,
name|pci_device_1155
block|}
block|,
block|{
literal|0x1156
block|,
literal|"Periscope Engineering"
block|,
literal|0
block|}
block|,
block|{
literal|0x1157
block|,
literal|"Avsys Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1158
block|,
literal|"Voarx R&D Inc"
block|,
name|pci_device_1158
block|}
block|,
block|{
literal|0x1159
block|,
literal|"Mutech"
block|,
name|pci_device_1159
block|}
block|,
block|{
literal|0x115a
block|,
literal|"Harlequin Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x115b
block|,
literal|"Parallax Graphics"
block|,
literal|0
block|}
block|,
block|{
literal|0x115c
block|,
literal|"Photron Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x115d
block|,
literal|"Xircom"
block|,
name|pci_device_115d
block|}
block|,
block|{
literal|0x115e
block|,
literal|"Peer Protocols Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x115f
block|,
literal|"Maxtor Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1160
block|,
literal|"Megasoft Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1161
block|,
literal|"PFU Ltd"
block|,
name|pci_device_1161
block|}
block|,
block|{
literal|0x1162
block|,
literal|"OA Laboratory Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1163
block|,
literal|"Rendition Inc"
block|,
name|pci_device_1163
block|}
block|,
block|{
literal|0x1164
block|,
literal|"Advanced Peripherals Tech"
block|,
literal|0
block|}
block|,
block|{
literal|0x1165
block|,
literal|"Imagraph Corporation"
block|,
name|pci_device_1165
block|}
block|,
block|{
literal|0x1166
block|,
literal|"Pequr Technology / Ross Computer Corp"
block|,
name|pci_device_1166
block|}
block|,
block|{
literal|0x1167
block|,
literal|"Mutoh Industries Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1168
block|,
literal|"Thine Electronics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1169
block|,
literal|"Centre f/Dev. of Adv. Computing"
block|,
literal|0
block|}
block|,
block|{
literal|0x116a
block|,
literal|"Polaris Communications"
block|,
name|pci_device_116a
block|}
block|,
block|{
literal|0x116b
block|,
literal|"Connectware Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x116c
block|,
literal|"Intelligent Resources"
block|,
literal|0
block|}
block|,
block|{
literal|0x116e
block|,
literal|"Electronics for Imaging"
block|,
literal|0
block|}
block|,
block|{
literal|0x116f
block|,
literal|"Workstation Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1170
block|,
literal|"Inventec Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1171
block|,
literal|"Loughborough Sound Images"
block|,
literal|0
block|}
block|,
block|{
literal|0x1172
block|,
literal|"Altera Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1173
block|,
literal|"Adobe Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1174
block|,
literal|"Bridgeport Machines"
block|,
literal|0
block|}
block|,
block|{
literal|0x1175
block|,
literal|"Mitron Computer Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1176
block|,
literal|"SBE"
block|,
literal|0
block|}
block|,
block|{
literal|0x1177
block|,
literal|"Silicon Engineering"
block|,
literal|0
block|}
block|,
block|{
literal|0x1178
block|,
literal|"Alfa Inc"
block|,
name|pci_device_1178
block|}
block|,
block|{
literal|0x1179
block|,
literal|"Toshiba America Info Systems"
block|,
name|pci_device_1179
block|}
block|,
block|{
literal|0x117a
block|,
literal|"A-Trend Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x117b
block|,
literal|"LG Electronics Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x117c
block|,
literal|"Atto Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x117d
block|,
literal|"Becton& Dickinson"
block|,
literal|0
block|}
block|,
block|{
literal|0x117e
block|,
literal|"T/R Systems"
block|,
name|pci_device_117e
block|}
block|,
block|{
literal|0x117f
block|,
literal|"Integrated Circuit Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1180
block|,
literal|"Ricoh Co Ltd"
block|,
name|pci_device_1180
block|}
block|,
block|{
literal|0x1181
block|,
literal|"Telmatics International"
block|,
literal|0
block|}
block|,
block|{
literal|0x1183
block|,
literal|"Fujikura Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1184
block|,
literal|"Forks Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1185
block|,
literal|"Dataworld"
block|,
name|pci_device_1185
block|}
block|,
block|{
literal|0x1186
block|,
literal|"D-Link System Inc"
block|,
name|pci_device_1186
block|}
block|,
block|{
literal|0x1187
block|,
literal|"Advanced Technology Laboratories"
block|,
literal|0
block|}
block|,
block|{
literal|0x1188
block|,
literal|"Shima Seiki Manufacturing Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1189
block|,
literal|"Matsushita Electronics"
block|,
name|pci_device_1189
block|}
block|,
block|{
literal|0x118a
block|,
literal|"Hilevel Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x118b
block|,
literal|"Hypertec Pty Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x118c
block|,
literal|"Corollary Inc"
block|,
name|pci_device_118c
block|}
block|,
block|{
literal|0x118d
block|,
literal|"BitFlow Inc"
block|,
name|pci_device_118d
block|}
block|,
block|{
literal|0x118e
block|,
literal|"Hermstedt GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x118f
block|,
literal|"Green Logic"
block|,
literal|0
block|}
block|,
block|{
literal|0x1190
block|,
literal|"Tripace"
block|,
name|pci_device_1190
block|}
block|,
block|{
literal|0x1191
block|,
literal|"ACARD Technology"
block|,
name|pci_device_1191
block|}
block|,
block|{
literal|0x1192
block|,
literal|"Densan Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1193
block|,
literal|"Zeitnet Inc."
block|,
name|pci_device_1193
block|}
block|,
block|{
literal|0x1194
block|,
literal|"Toucan Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1195
block|,
literal|"Ratoc System Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1196
block|,
literal|"Hytec Electronics Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1197
block|,
literal|"Gage Applied Sciences Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1198
block|,
literal|"Lambda Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1199
block|,
literal|"Attachmate Corp."
block|,
name|pci_device_1199
block|}
block|,
block|{
literal|0x119a
block|,
literal|"Mind Share Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x119b
block|,
literal|"Omega Micro Inc."
block|,
name|pci_device_119b
block|}
block|,
block|{
literal|0x119c
block|,
literal|"Information Technology Inst."
block|,
literal|0
block|}
block|,
block|{
literal|0x119d
block|,
literal|"Bug Sapporo Japan"
block|,
literal|0
block|}
block|,
block|{
literal|0x119e
block|,
literal|"Fujitsu"
block|,
literal|0
block|}
block|,
block|{
literal|0x119f
block|,
literal|"Bull Hn Information Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x11a0
block|,
literal|"Convex Computer Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x11a1
block|,
literal|"Hamamatsu Photonics K.K."
block|,
literal|0
block|}
block|,
block|{
literal|0x11a2
block|,
literal|"Sierra Research and Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x11a3
block|,
literal|"Deuretzbacher GmbH& Co. Eng. KG"
block|,
literal|0
block|}
block|,
block|{
literal|0x11a4
block|,
literal|"Barco"
block|,
literal|0
block|}
block|,
block|{
literal|0x11a5
block|,
literal|"MicroUnity Systems Engineering Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x11a6
block|,
literal|"Pure Data"
block|,
literal|0
block|}
block|,
block|{
literal|0x11a7
block|,
literal|"Power Computing Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x11a8
block|,
literal|"Systech Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x11a9
block|,
literal|"InnoSys Inc."
block|,
name|pci_device_11a9
block|}
block|,
block|{
literal|0x11aa
block|,
literal|"Actel"
block|,
literal|0
block|}
block|,
block|{
literal|0x11ab
block|,
literal|"Galileo Technology Ltd."
block|,
name|pci_device_11ab
block|}
block|,
block|{
literal|0x11ac
block|,
literal|"Canon Information Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x11ad
block|,
literal|"Lite-On Communications Inc"
block|,
name|pci_device_11ad
block|}
block|,
block|{
literal|0x11ae
block|,
literal|"Scitex Corporation Ltd"
block|,
name|pci_device_11ae
block|}
block|,
block|{
literal|0x11af
block|,
literal|"Avid Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x11b0
block|,
literal|"V3 Semiconductor Inc."
block|,
name|pci_device_11b0
block|}
block|,
block|{
literal|0x11b1
block|,
literal|"Apricot Computers"
block|,
literal|0
block|}
block|,
block|{
literal|0x11b2
block|,
literal|"Eastman Kodak"
block|,
literal|0
block|}
block|,
block|{
literal|0x11b3
block|,
literal|"Barr Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x11b4
block|,
literal|"Leitch Technology International"
block|,
literal|0
block|}
block|,
block|{
literal|0x11b5
block|,
literal|"Radstone Technology Plc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11b6
block|,
literal|"United Video Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x11b7
block|,
literal|"Motorola"
block|,
literal|0
block|}
block|,
block|{
literal|0x11b8
block|,
literal|"Xpoint Technologies Inc"
block|,
name|pci_device_11b8
block|}
block|,
block|{
literal|0x11b9
block|,
literal|"Pathlight Technology Inc."
block|,
name|pci_device_11b9
block|}
block|,
block|{
literal|0x11ba
block|,
literal|"Videotron Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x11bb
block|,
literal|"Pyramid Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x11bc
block|,
literal|"Network Peripherals Inc"
block|,
name|pci_device_11bc
block|}
block|,
block|{
literal|0x11bd
block|,
literal|"Pinnacle Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x11be
block|,
literal|"International Microcircuits Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11bf
block|,
literal|"Astrodesign Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x11c0
block|,
literal|"Hewlett-Packard"
block|,
literal|0
block|}
block|,
block|{
literal|0x11c1
block|,
literal|"AT&T Microelectronics"
block|,
name|pci_device_11c1
block|}
block|,
block|{
literal|0x11c2
block|,
literal|"Sand Microelectronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x11c3
block|,
literal|"NEC Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x11c4
block|,
literal|"Document Technologies Ind."
block|,
literal|0
block|}
block|,
block|{
literal|0x11c5
block|,
literal|"Shiva Corporatin"
block|,
literal|0
block|}
block|,
block|{
literal|0x11c6
block|,
literal|"Dainippon Screen Mfg. Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x11c7
block|,
literal|"D.C.M. Data Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x11c8
block|,
literal|"Dolphin Interconnect Solutions"
block|,
name|pci_device_11c8
block|}
block|,
block|{
literal|0x11c9
block|,
literal|"MAGMA"
block|,
name|pci_device_11c9
block|}
block|,
block|{
literal|0x11ca
block|,
literal|"LSI Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11cb
block|,
literal|"Specialix International Ltd."
block|,
name|pci_device_11cb
block|}
block|,
block|{
literal|0x11cc
block|,
literal|"Michels& Kleberhoff Computer GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x11cd
block|,
literal|"HAL Computer Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x11ce
block|,
literal|"Primary Rate Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11cf
block|,
literal|"Pioneer Electronic Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x11d0
block|,
literal|"Loral Frederal Systems - Manassas"
block|,
literal|0
block|}
block|,
block|{
literal|0x11d1
block|,
literal|"AuraVision Corporation"
block|,
name|pci_device_11d1
block|}
block|,
block|{
literal|0x11d2
block|,
literal|"Intercom Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x11d3
block|,
literal|"Trancell Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11d4
block|,
literal|"Analog Devices"
block|,
name|pci_device_11d4
block|}
block|,
block|{
literal|0x11d5
block|,
literal|"Ikon Corp"
block|,
name|pci_device_11d5
block|}
block|,
block|{
literal|0x11d6
block|,
literal|"Tekelec Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x11d7
block|,
literal|"Trenton Terminals Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11d8
block|,
literal|"Image Technologies Development"
block|,
literal|0
block|}
block|,
block|{
literal|0x11d9
block|,
literal|"Tec Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x11da
block|,
literal|"Novell"
block|,
literal|0
block|}
block|,
block|{
literal|0x11db
block|,
literal|"Sega Enterprises Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x11dc
block|,
literal|"Questra Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x11dd
block|,
literal|"Crosfield Electronics Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x11de
block|,
literal|"Zoran Corporation"
block|,
name|pci_device_11de
block|}
block|,
block|{
literal|0x11df
block|,
literal|"New Wave Pdg"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e0
block|,
literal|"Cray Communications A/S"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e1
block|,
literal|"Gec Plessey Semi Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e2
block|,
literal|"Samsung Information Systems America"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e3
block|,
literal|"Quicklogic Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e4
block|,
literal|"Second Wave Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e5
block|,
literal|"IIX Consulting"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e6
block|,
literal|"Mitsui-Zosen System Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e7
block|,
literal|"Toshiba America Elec. Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e8
block|,
literal|"Digital Processing Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11e9
block|,
literal|"Highwater Designs Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x11ea
block|,
literal|"Elsag Bailey"
block|,
literal|0
block|}
block|,
block|{
literal|0x11eb
block|,
literal|"Formation Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11ec
block|,
literal|"Coreco Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11ed
block|,
literal|"Mediamatics"
block|,
literal|0
block|}
block|,
block|{
literal|0x11ee
block|,
literal|"Dome Imaging Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11ef
block|,
literal|"Nicolet Technologies BV"
block|,
literal|0
block|}
block|,
block|{
literal|0x11f0
block|,
literal|"Compu-Shack GmbH"
block|,
name|pci_device_11f0
block|}
block|,
block|{
literal|0x11f1
block|,
literal|"Symbios Logic Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11f2
block|,
literal|"Picture Tel Japan KK"
block|,
literal|0
block|}
block|,
block|{
literal|0x11f3
block|,
literal|"Keithley Metrabyte"
block|,
literal|0
block|}
block|,
block|{
literal|0x11f4
block|,
literal|"Kinetic Systems Corporation"
block|,
name|pci_device_11f4
block|}
block|,
block|{
literal|0x11f5
block|,
literal|"Computing Devices Intl"
block|,
literal|0
block|}
block|,
block|{
literal|0x11f6
block|,
literal|"Powermatic Data Systems Ltd"
block|,
name|pci_device_11f6
block|}
block|,
block|{
literal|0x11f7
block|,
literal|"Scientific Atlanta"
block|,
literal|0
block|}
block|,
block|{
literal|0x11f8
block|,
literal|"PMC-Sierra Inc."
block|,
name|pci_device_11f8
block|}
block|,
block|{
literal|0x11f9
block|,
literal|"I-Cube Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11fa
block|,
literal|"Kasan Electronics Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x11fb
block|,
literal|"Datel Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x11fc
block|,
literal|"Silicon Magic"
block|,
literal|0
block|}
block|,
block|{
literal|0x11fd
block|,
literal|"High Street Consultants"
block|,
literal|0
block|}
block|,
block|{
literal|0x11fe
block|,
literal|"Comtrol Corp"
block|,
name|pci_device_11fe
block|}
block|,
block|{
literal|0x11ff
block|,
literal|"Scion Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1200
block|,
literal|"CSS Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1201
block|,
literal|"Vista Controls Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1202
block|,
literal|"Network General Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1203
block|,
literal|"Bayer Corporation Agfa Div"
block|,
literal|0
block|}
block|,
block|{
literal|0x1204
block|,
literal|"Lattice Semiconductor Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1205
block|,
literal|"Array Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1206
block|,
literal|"Amdahl Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1208
block|,
literal|"Parsytec GmbH"
block|,
name|pci_device_1208
block|}
block|,
block|{
literal|0x1209
block|,
literal|"Sci Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x120a
block|,
literal|"Synaptel"
block|,
literal|0
block|}
block|,
block|{
literal|0x120b
block|,
literal|"Adaptive Solutions"
block|,
literal|0
block|}
block|,
block|{
literal|0x120d
block|,
literal|"Compression Labs Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x120e
block|,
literal|"Cyclades Corporation"
block|,
name|pci_device_120e
block|}
block|,
block|{
literal|0x120f
block|,
literal|"Essential Communications"
block|,
name|pci_device_120f
block|}
block|,
block|{
literal|0x1210
block|,
literal|"Hyperparallel Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x1211
block|,
literal|"Braintech Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1212
block|,
literal|"Kingston Technology Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1213
block|,
literal|"Applied Intelligent Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1214
block|,
literal|"Performance Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1215
block|,
literal|"Interware Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1216
block|,
literal|"Purup-Eskofot A/S"
block|,
literal|0
block|}
block|,
block|{
literal|0x1217
block|,
literal|"O2Micro Inc"
block|,
name|pci_device_1217
block|}
block|,
block|{
literal|0x1218
block|,
literal|"Hybricon Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1219
block|,
literal|"First Virtual Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x121a
block|,
literal|"3dfx Interactive Inc"
block|,
name|pci_device_121a
block|}
block|,
block|{
literal|0x121b
block|,
literal|"Advanced Telecommunications Modules"
block|,
literal|0
block|}
block|,
block|{
literal|0x121c
block|,
literal|"Nippon Texa Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x121d
block|,
literal|"Lippert Automationstechnik GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x121e
block|,
literal|"CSPI"
block|,
literal|0
block|}
block|,
block|{
literal|0x121f
block|,
literal|"Arcus Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1220
block|,
literal|"Ariel Corporation"
block|,
name|pci_device_1220
block|}
block|,
block|{
literal|0x1221
block|,
literal|"Contec Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1222
block|,
literal|"Ancor Communications Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1223
block|,
literal|"Heurikon/Computer Products"
block|,
literal|0
block|}
block|,
block|{
literal|0x1224
block|,
literal|"Interactive Images"
block|,
literal|0
block|}
block|,
block|{
literal|0x1225
block|,
literal|"Power I/O Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1227
block|,
literal|"Tech-Source"
block|,
literal|0
block|}
block|,
block|{
literal|0x1228
block|,
literal|"Norsk Elektro Optikk A/S"
block|,
literal|0
block|}
block|,
block|{
literal|0x1229
block|,
literal|"Data Kinesis Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x122a
block|,
literal|"Integrated Telecom"
block|,
literal|0
block|}
block|,
block|{
literal|0x122b
block|,
literal|"LG Industrial Systems Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x122c
block|,
literal|"Sican GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x122d
block|,
literal|"Aztech System Ltd"
block|,
name|pci_device_122d
block|}
block|,
block|{
literal|0x122e
block|,
literal|"Xyratex"
block|,
literal|0
block|}
block|,
block|{
literal|0x122f
block|,
literal|"Andrew Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1230
block|,
literal|"Fishcamp Engineering"
block|,
literal|0
block|}
block|,
block|{
literal|0x1231
block|,
literal|"Woodward McCoach Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1232
block|,
literal|"GPT Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1233
block|,
literal|"Bus-Tech Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1234
block|,
literal|"Technical Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1235
block|,
literal|"Risq Modular Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1236
block|,
literal|"Sigma Designs Corp."
block|,
name|pci_device_1236
block|}
block|,
block|{
literal|0x1237
block|,
literal|"Alta Technology Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1238
block|,
literal|"Adtran"
block|,
literal|0
block|}
block|,
block|{
literal|0x1239
block|,
literal|"The 3DO Company"
block|,
literal|0
block|}
block|,
block|{
literal|0x123a
block|,
literal|"Visicom Laboratories Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x123b
block|,
literal|"Seeq Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x123c
block|,
literal|"Century Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x123d
block|,
literal|"Engineering Design Team Inc."
block|,
name|pci_device_123d
block|}
block|,
block|{
literal|0x123f
block|,
literal|"C-Cube Microsystems"
block|,
name|pci_device_123f
block|}
block|,
block|{
literal|0x1240
block|,
literal|"Marathon Technologies Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1241
block|,
literal|"DSC Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0x1242
block|,
literal|"Jaycor Network Inc."
block|,
name|pci_device_1242
block|}
block|,
block|{
literal|0x1243
block|,
literal|"Delphax"
block|,
literal|0
block|}
block|,
block|{
literal|0x1244
block|,
literal|"AVM AUDIOVISUELLES MKTG& Computer GmbH"
block|,
name|pci_device_1244
block|}
block|,
block|{
literal|0x1245
block|,
literal|"APD S.A."
block|,
literal|0
block|}
block|,
block|{
literal|0x1246
block|,
literal|"Dipix Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1247
block|,
literal|"Xylon Research Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1248
block|,
literal|"Central Data Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1249
block|,
literal|"Samsung Electronics Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x124a
block|,
literal|"AEG Electrocom GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x124b
block|,
literal|"GreenSpring Computers"
block|,
literal|0
block|}
block|,
block|{
literal|0x124c
block|,
literal|"Solitron Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x124d
block|,
literal|"Stallion Technologies"
block|,
name|pci_device_124d
block|}
block|,
block|{
literal|0x124e
block|,
literal|"Cylink"
block|,
literal|0
block|}
block|,
block|{
literal|0x124f
block|,
literal|"Infortrend Technology Inc"
block|,
name|pci_device_124f
block|}
block|,
block|{
literal|0x1250
block|,
literal|"Hitachi Microcomputer System Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1251
block|,
literal|"VLSI Solution OY"
block|,
literal|0
block|}
block|,
block|{
literal|0x1253
block|,
literal|"Guzik Technical Enterprises"
block|,
literal|0
block|}
block|,
block|{
literal|0x1254
block|,
literal|"Linear Systems Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1255
block|,
literal|"Optibase Ltd."
block|,
name|pci_device_1255
block|}
block|,
block|{
literal|0x1256
block|,
literal|"Perceptive Solutions Inc."
block|,
name|pci_device_1256
block|}
block|,
block|{
literal|0x1257
block|,
literal|"Vertex Networks Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1258
block|,
literal|"Gilbarco Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1259
block|,
literal|"Allied Telesyn International"
block|,
name|pci_device_1259
block|}
block|,
block|{
literal|0x125a
block|,
literal|"ABB Power Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x125b
block|,
literal|"Asix Electronics Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x125c
block|,
literal|"Aurora Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x125d
block|,
literal|"ESS Technology"
block|,
name|pci_device_125d
block|}
block|,
block|{
literal|0x125e
block|,
literal|"Specialvideo Engineering SRL"
block|,
literal|0
block|}
block|,
block|{
literal|0x125f
block|,
literal|"Concurrent Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1260
block|,
literal|"Harris Semiconductor"
block|,
name|pci_device_1260
block|}
block|,
block|{
literal|0x1261
block|,
literal|"Matsushita-Kotobuki Electronics Indu"
block|,
literal|0
block|}
block|,
block|{
literal|0x1262
block|,
literal|"ES Computer Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1263
block|,
literal|"Sonic Solutions"
block|,
literal|0
block|}
block|,
block|{
literal|0x1264
block|,
literal|"Aval Nagasaki Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1265
block|,
literal|"Casio Computer Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1266
block|,
literal|"Microdyne Corp."
block|,
name|pci_device_1266
block|}
block|,
block|{
literal|0x1267
block|,
literal|"S.A. Telecommunications"
block|,
name|pci_device_1267
block|}
block|,
block|{
literal|0x1268
block|,
literal|"Tektronix"
block|,
literal|0
block|}
block|,
block|{
literal|0x1269
block|,
literal|"Thomson-CSF/TTM"
block|,
literal|0
block|}
block|,
block|{
literal|0x126a
block|,
literal|"Lexmark International Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x126b
block|,
literal|"Adax Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x126c
block|,
literal|"Northern Telecom"
block|,
literal|0
block|}
block|,
block|{
literal|0x126d
block|,
literal|"Splash Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x126e
block|,
literal|"Sumitomo Metal Industries Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x126f
block|,
literal|"Silicon Motion"
block|,
name|pci_device_126f
block|}
block|,
block|{
literal|0x1270
block|,
literal|"Olympus Optical Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1271
block|,
literal|"GW Instruments"
block|,
literal|0
block|}
block|,
block|{
literal|0x1272
block|,
literal|"Telematics International"
block|,
literal|0
block|}
block|,
block|{
literal|0x1273
block|,
literal|"Hughes Network Systems"
block|,
name|pci_device_1273
block|}
block|,
block|{
literal|0x1274
block|,
literal|"Ensoniq"
block|,
name|pci_device_1274
block|}
block|,
block|{
literal|0x1275
block|,
literal|"Network Appliance"
block|,
literal|0
block|}
block|,
block|{
literal|0x1276
block|,
literal|"Switched Network Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1277
block|,
literal|"Comstream"
block|,
literal|0
block|}
block|,
block|{
literal|0x1278
block|,
literal|"Transtech Parallel Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1279
block|,
literal|"Transmeta Corp."
block|,
name|pci_device_1279
block|}
block|,
block|{
literal|0x127a
block|,
literal|"Conexant Systems"
block|,
name|pci_device_127a
block|}
block|,
block|{
literal|0x127b
block|,
literal|"Pixera Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x127c
block|,
literal|"Crosspoint Solutions Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x127d
block|,
literal|"Vela Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x127e
block|,
literal|"Winnov L.P."
block|,
literal|0
block|}
block|,
block|{
literal|0x127f
block|,
literal|"Fujifilm"
block|,
literal|0
block|}
block|,
block|{
literal|0x1280
block|,
literal|"Photoscript Group Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1281
block|,
literal|"Yokogawa Electronic Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1282
block|,
literal|"Davicom Semiconductor Inc."
block|,
name|pci_device_1282
block|}
block|,
block|{
literal|0x1283
block|,
literal|"Integrated Technology Express Inc."
block|,
name|pci_device_1283
block|}
block|,
block|{
literal|0x1284
block|,
literal|"Sahara Networks Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1285
block|,
literal|"Platform Technologies Inc."
block|,
name|pci_device_1285
block|}
block|,
block|{
literal|0x1286
block|,
literal|"Mazet GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1287
block|,
literal|"LuxSonor Inc."
block|,
name|pci_device_1287
block|}
block|,
block|{
literal|0x1288
block|,
literal|"Timestep Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1289
block|,
literal|"AVC Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x128a
block|,
literal|"Asante Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x128b
block|,
literal|"Transwitch Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x128c
block|,
literal|"Retix Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x128d
block|,
literal|"G2 Networks Inc."
block|,
name|pci_device_128d
block|}
block|,
block|{
literal|0x128e
block|,
literal|"Samho Multi Tech Ltd."
block|,
name|pci_device_128e
block|}
block|,
block|{
literal|0x128f
block|,
literal|"Tateno Dennou Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1290
block|,
literal|"Sord Computer Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1291
block|,
literal|"NCS Computer Italia"
block|,
literal|0
block|}
block|,
block|{
literal|0x1292
block|,
literal|"Tritech Microelectronics Intl PTE"
block|,
literal|0
block|}
block|,
block|{
literal|0x1293
block|,
literal|"Media Reality Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1294
block|,
literal|"Rhetorex Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1295
block|,
literal|"Imagenation Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1296
block|,
literal|"Kofax Image Products"
block|,
literal|0
block|}
block|,
block|{
literal|0x1297
block|,
literal|"Holco Enterprise"
block|,
literal|0
block|}
block|,
block|{
literal|0x1298
block|,
literal|"Spellcaster Telecommunications Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1299
block|,
literal|"Knowledge Technology Laboratories"
block|,
literal|0
block|}
block|,
block|{
literal|0x129a
block|,
literal|"VMETRO"
block|,
literal|0
block|}
block|,
block|{
literal|0x129b
block|,
literal|"Image Access"
block|,
literal|0
block|}
block|,
block|{
literal|0x129d
block|,
literal|"CompCore Multimedia Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x129e
block|,
literal|"Victor Co. of Japan Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x129f
block|,
literal|"OEC Medical Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12a0
block|,
literal|"Allen Bradley Co."
block|,
literal|0
block|}
block|,
block|{
literal|0x12a1
block|,
literal|"Simpact Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x12a2
block|,
literal|"NewGen Systems Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12a3
block|,
literal|"Lucent Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x12a4
block|,
literal|"NTT Electronics Technology Co."
block|,
literal|0
block|}
block|,
block|{
literal|0x12a5
block|,
literal|"Vision Dynamics Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x12a6
block|,
literal|"Scalable Networks Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12a7
block|,
literal|"AMO GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x12a8
block|,
literal|"News Datacom"
block|,
literal|0
block|}
block|,
block|{
literal|0x12a9
block|,
literal|"Xiotech Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12aa
block|,
literal|"SDL Communications Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12ab
block|,
literal|"Yuan Yuan Enterprise Co. Ltd."
block|,
name|pci_device_12ab
block|}
block|,
block|{
literal|0x12ac
block|,
literal|"MeasureX Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12ad
block|,
literal|"Multidata GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x12ae
block|,
literal|"Alteon Networks Inc."
block|,
name|pci_device_12ae
block|}
block|,
block|{
literal|0x12af
block|,
literal|"TDK USA Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12b0
block|,
literal|"Jorge Scientific Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12b1
block|,
literal|"GammaLink"
block|,
literal|0
block|}
block|,
block|{
literal|0x12b2
block|,
literal|"General Signal Networks"
block|,
literal|0
block|}
block|,
block|{
literal|0x12b3
block|,
literal|"Inter-Face Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x12b4
block|,
literal|"Future Tel Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12b5
block|,
literal|"Granite Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12b6
block|,
literal|"Natural Microsystems"
block|,
literal|0
block|}
block|,
block|{
literal|0x12b7
block|,
literal|"Acumen"
block|,
literal|0
block|}
block|,
block|{
literal|0x12b8
block|,
literal|"Korg"
block|,
literal|0
block|}
block|,
block|{
literal|0x12b9
block|,
literal|"US Robotics"
block|,
name|pci_device_12b9
block|}
block|,
block|{
literal|0x12ba
block|,
literal|"Bittware Research Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x12bb
block|,
literal|"Nippon Unisoft Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12bc
block|,
literal|"Array Microsystems"
block|,
literal|0
block|}
block|,
block|{
literal|0x12bd
block|,
literal|"Computerm Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12be
block|,
literal|"Anchor Chips Inc."
block|,
name|pci_device_12be
block|}
block|,
block|{
literal|0x12bf
block|,
literal|"Fujifilm Microdevices"
block|,
literal|0
block|}
block|,
block|{
literal|0x12c0
block|,
literal|"Infimed"
block|,
literal|0
block|}
block|,
block|{
literal|0x12c1
block|,
literal|"GMM Research Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12c2
block|,
literal|"Mentec Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x12c3
block|,
literal|"Holtek Microelectronics Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12c4
block|,
literal|"Connect Tech Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12c5
block|,
literal|"Picture Elements Inc."
block|,
name|pci_device_12c5
block|}
block|,
block|{
literal|0x12c6
block|,
literal|"Mitani Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12c7
block|,
literal|"Dialogic Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12c8
block|,
literal|"G Force Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x12c9
block|,
literal|"Gigi Operations"
block|,
literal|0
block|}
block|,
block|{
literal|0x12ca
block|,
literal|"Integrated Computing Engines, Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12cb
block|,
literal|"Antex Electronics Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12cc
block|,
literal|"Pluto Technologies International"
block|,
literal|0
block|}
block|,
block|{
literal|0x12cd
block|,
literal|"Aims Lab"
block|,
literal|0
block|}
block|,
block|{
literal|0x12ce
block|,
literal|"Netspeed Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12cf
block|,
literal|"Prophet Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12d0
block|,
literal|"GDE Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12d1
block|,
literal|"PsiTech"
block|,
literal|0
block|}
block|,
block|{
literal|0x12d2
block|,
literal|"NVidia / SGS Thomson"
block|,
name|pci_device_12d2
block|}
block|,
block|{
literal|0x12d3
block|,
literal|"Vingmed Sound A/S"
block|,
literal|0
block|}
block|,
block|{
literal|0x12d4
block|,
literal|"DGM& S"
block|,
literal|0
block|}
block|,
block|{
literal|0x12d5
block|,
literal|"Equator Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x12d6
block|,
literal|"Analogic Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12d7
block|,
literal|"Biotronic SRL"
block|,
literal|0
block|}
block|,
block|{
literal|0x12d8
block|,
literal|"Pericom Semiconductor"
block|,
literal|0
block|}
block|,
block|{
literal|0x12d9
block|,
literal|"Aculab Plc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12da
block|,
literal|"TrueTime"
block|,
literal|0
block|}
block|,
block|{
literal|0x12db
block|,
literal|"Annapolis Micro Systems Inc."
block|,
name|pci_device_12db
block|}
block|,
block|{
literal|0x12dc
block|,
literal|"Symicron Computer Communication Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x12dd
block|,
literal|"Management Graphics Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12de
block|,
literal|"Rainbow Technologies"
block|,
name|pci_device_12de
block|}
block|,
block|{
literal|0x12df
block|,
literal|"SBS Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12e0
block|,
literal|"Chase Research PLC"
block|,
name|pci_device_12e0
block|}
block|,
block|{
literal|0x12e1
block|,
literal|"Nintendo Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x12e2
block|,
literal|"Datum Inc. Bancomm-Timing Division"
block|,
literal|0
block|}
block|,
block|{
literal|0x12e3
block|,
literal|"Imation Corp. - Medical Imaging Syst"
block|,
literal|0
block|}
block|,
block|{
literal|0x12e4
block|,
literal|"Brooktrout Technology Inc."
block|,
name|pci_device_12e4
block|}
block|,
block|{
literal|0x12e6
block|,
literal|"Cirel Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x12e7
block|,
literal|"Sebring Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x12e8
block|,
literal|"CRISC Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x12e9
block|,
literal|"GE Spacenet"
block|,
literal|0
block|}
block|,
block|{
literal|0x12ea
block|,
literal|"Zuken"
block|,
literal|0
block|}
block|,
block|{
literal|0x12eb
block|,
literal|"Aureal Semiconductor"
block|,
name|pci_device_12eb
block|}
block|,
block|{
literal|0x12ec
block|,
literal|"3A International Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12ed
block|,
literal|"Optivision Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12ee
block|,
literal|"Orange Micro, Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12ef
block|,
literal|"Vienna Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x12f0
block|,
literal|"Pentek"
block|,
literal|0
block|}
block|,
block|{
literal|0x12f1
block|,
literal|"Sorenson Vision Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12f2
block|,
literal|"Gammagraphx Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x12f4
block|,
literal|"Megatel"
block|,
literal|0
block|}
block|,
block|{
literal|0x12f5
block|,
literal|"Forks"
block|,
literal|0
block|}
block|,
block|{
literal|0x12f6
block|,
literal|"Dawson France"
block|,
literal|0
block|}
block|,
block|{
literal|0x12f7
block|,
literal|"Cognex"
block|,
literal|0
block|}
block|,
block|{
literal|0x12f8
block|,
literal|"Electronic-Design GmbH"
block|,
name|pci_device_12f8
block|}
block|,
block|{
literal|0x12f9
block|,
literal|"FourFold Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x12fb
block|,
literal|"Spectrum Signal Processing"
block|,
literal|0
block|}
block|,
block|{
literal|0x12fc
block|,
literal|"Capital Equipment Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x12fe
block|,
literal|"ESD Electronic System Design GmbH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1304
block|,
literal|"Juniper Networks Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1307
block|,
literal|"ComputerBoards"
block|,
name|pci_device_1307
block|}
block|,
block|{
literal|0x1308
block|,
literal|"Jato Technologies Inc."
block|,
name|pci_device_1308
block|}
block|,
block|{
literal|0x130a
block|,
literal|"Mitsubishi Electric Microcomputer"
block|,
literal|0
block|}
block|,
block|{
literal|0x130b
block|,
literal|"Colorgraphic Communications Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x130f
block|,
literal|"Advanet Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1310
block|,
literal|"Gespac"
block|,
literal|0
block|}
block|,
block|{
literal|0x1312
block|,
literal|"Robotic Vision Systems Incorporated"
block|,
literal|0
block|}
block|,
block|{
literal|0x1313
block|,
literal|"Yaskawa Electric Co."
block|,
literal|0
block|}
block|,
block|{
literal|0x1316
block|,
literal|"Teradyne Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1317
block|,
literal|"Admtek Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1318
block|,
literal|"Packet Engines, Inc."
block|,
name|pci_device_1318
block|}
block|,
block|{
literal|0x1319
block|,
literal|"Forte Media, Inc."
block|,
name|pci_device_1319
block|}
block|,
block|{
literal|0x131f
block|,
literal|"SIIG"
block|,
literal|0
block|}
block|,
block|{
literal|0x1325
block|,
literal|"Salix Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1326
block|,
literal|"Seachange International"
block|,
literal|0
block|}
block|,
block|{
literal|0x1331
block|,
literal|"RadiSys Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1335
block|,
literal|"Videomail Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x133d
block|,
literal|"Prisa Networks"
block|,
literal|0
block|}
block|,
block|{
literal|0x133f
block|,
literal|"SCM Microsystems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1342
block|,
literal|"Promax Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1344
block|,
literal|"Micron Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1347
block|,
literal|"Odetics"
block|,
literal|0
block|}
block|,
block|{
literal|0x134a
block|,
literal|"DTC Technology Corp."
block|,
name|pci_device_134a
block|}
block|,
block|{
literal|0x134b
block|,
literal|"ARK Research Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x134c
block|,
literal|"Chori Joho System Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x134d
block|,
literal|"PCTEL Inc."
block|,
name|pci_device_134d
block|}
block|,
block|{
literal|0x135a
block|,
literal|"Brain Boxes Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x135b
block|,
literal|"Giganet Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x135c
block|,
literal|"Quatech Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x135d
block|,
literal|"ABB Network Partner AB"
block|,
literal|0
block|}
block|,
block|{
literal|0x135e
block|,
literal|"Sealevel Systems Inc."
block|,
name|pci_device_135e
block|}
block|,
block|{
literal|0x135f
block|,
literal|"I-Data International A-S"
block|,
literal|0
block|}
block|,
block|{
literal|0x1360
block|,
literal|"Meinberg Funkuhren"
block|,
literal|0
block|}
block|,
block|{
literal|0x1361
block|,
literal|"Soliton Systems K.K."
block|,
literal|0
block|}
block|,
block|{
literal|0x1363
block|,
literal|"Phoenix Technologies Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1367
block|,
literal|"Hitachi Zosen Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1368
block|,
literal|"Skyware Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1369
block|,
literal|"Digigram"
block|,
literal|0
block|}
block|,
block|{
literal|0x136b
block|,
literal|"Kawasaki Steel Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x136c
block|,
literal|"Adtek System Science Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1375
block|,
literal|"Boeing - Sunnyvale"
block|,
literal|0
block|}
block|,
block|{
literal|0x1377
block|,
literal|"GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x137a
block|,
literal|"Mark Of The Unicorn Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x137b
block|,
literal|"PPT Vision"
block|,
literal|0
block|}
block|,
block|{
literal|0x137c
block|,
literal|"Iwatsu Electric Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x137d
block|,
literal|"Dynachip Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x137e
block|,
literal|"Patriot Scientific Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1380
block|,
literal|"Sanritz Automation Co LTC"
block|,
literal|0
block|}
block|,
block|{
literal|0x1381
block|,
literal|"Brains Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1384
block|,
literal|"Stellar Semiconductor Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1385
block|,
literal|"Netgear"
block|,
name|pci_device_1385
block|}
block|,
block|{
literal|0x1387
block|,
literal|"Systran Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1388
block|,
literal|"Hitachi Information Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1389
block|,
literal|"Applicom International"
block|,
name|pci_device_1389
block|}
block|,
block|{
literal|0x138b
block|,
literal|"Tokimec Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x138e
block|,
literal|"Basler GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x138f
block|,
literal|"Patapsco Designs Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1390
block|,
literal|"Concept Development Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1393
block|,
literal|"Moxa Technologies Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1395
block|,
literal|"Ambicom Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1396
block|,
literal|"Cipher Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1397
block|,
literal|"Cologne Chip Designs GmbH"
block|,
name|pci_device_1397
block|}
block|,
block|{
literal|0x1398
block|,
literal|"Clarion Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x139a
block|,
literal|"Alacritech Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x139d
block|,
literal|"Xstreams PLC/ EPL Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x139e
block|,
literal|"Echostar Data Networks"
block|,
literal|0
block|}
block|,
block|{
literal|0x13a0
block|,
literal|"Crystal Group Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13a1
block|,
literal|"Kawasaki Heavy Industries Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x13a4
block|,
literal|"Rascom Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13a7
block|,
literal|"Teles AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x13a8
block|,
literal|"Exar Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x13a9
block|,
literal|"Siemens Medical Systems Ultrasound Group"
block|,
literal|0
block|}
block|,
block|{
literal|0x13aa
block|,
literal|"Nortel Networks - BWA Division"
block|,
literal|0
block|}
block|,
block|{
literal|0x13af
block|,
literal|"T.Sqware"
block|,
literal|0
block|}
block|,
block|{
literal|0x13b1
block|,
literal|"Tamura Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x13b4
block|,
literal|"Wellbean Co Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13b5
block|,
literal|"ARM Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x13b6
block|,
literal|"DLoG GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x13b8
block|,
literal|"Nokia Telecommunications OY"
block|,
literal|0
block|}
block|,
block|{
literal|0x13bf
block|,
literal|"Sharewave Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13c0
block|,
literal|"Microgate Corp."
block|,
name|pci_device_13c0
block|}
block|,
block|{
literal|0x13c1
block|,
literal|"3ware Inc."
block|,
name|pci_device_13c1
block|}
block|,
block|{
literal|0x13c2
block|,
literal|"Technotrend Systemtechnik GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x13c3
block|,
literal|"Janz Computer AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x13c7
block|,
literal|"Blue Chip Technology Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x13cc
block|,
literal|"Metheus Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x13cf
block|,
literal|"Studio Audio& Video Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x13d0
block|,
literal|"B2C2 Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13d1
block|,
literal|"Abocom Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13d4
block|,
literal|"Graphics Microsystems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13d6
block|,
literal|"K.I. Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x13d7
block|,
literal|"Toshiba Engineering Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x13d8
block|,
literal|"Phobos Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x13d9
block|,
literal|"Apex Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13dc
block|,
literal|"Netboost Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x13de
block|,
literal|"ABB Robotics Products AB"
block|,
literal|0
block|}
block|,
block|{
literal|0x13df
block|,
literal|"E-Tech Inc."
block|,
name|pci_device_13df
block|}
block|,
block|{
literal|0x13e0
block|,
literal|"GVC Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x13e3
block|,
literal|"Nest Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13e4
block|,
literal|"Calculex Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13e5
block|,
literal|"Telesoft Design Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x13e9
block|,
literal|"Intraserver Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13ea
block|,
literal|"Dallas Semiconductor"
block|,
literal|0
block|}
block|,
block|{
literal|0x13f0
block|,
literal|"Sundance Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13f1
block|,
literal|"OCE - Industries S.A."
block|,
literal|0
block|}
block|,
block|{
literal|0x13f4
block|,
literal|"Troika Networks Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x13f6
block|,
literal|"C-Media Electronics Inc."
block|,
name|pci_device_13f6
block|}
block|,
block|{
literal|0x13f9
block|,
literal|"NTT Advanced Technology Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x13fa
block|,
literal|"Pentland Systems Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x13fb
block|,
literal|"Aydin Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x13fd
block|,
literal|"Micro Science Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1400
block|,
literal|"ARTX Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1402
block|,
literal|"Meilhaus Electronic GmbH Germany"
block|,
literal|0
block|}
block|,
block|{
literal|0x1404
block|,
literal|"Fundamental Software Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1406
block|,
literal|"Océ Printing Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1407
block|,
literal|"Lava Computer MFG Inc."
block|,
name|pci_device_1407
block|}
block|,
block|{
literal|0x1408
block|,
literal|"Aloka Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1409
block|,
literal|"eTIMedia Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x140a
block|,
literal|"DSP Research Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x140b
block|,
literal|"Ramix Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x140d
block|,
literal|"Matsushita Electric Works Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x140f
block|,
literal|"Salient Systems Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1412
block|,
literal|"IC Ensemble, Inc."
block|,
name|pci_device_1412
block|}
block|,
block|{
literal|0x1413
block|,
literal|"Addonics"
block|,
literal|0
block|}
block|,
block|{
literal|0x1415
block|,
literal|"Oxford Semiconductor Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1418
block|,
literal|"Kyushu Electronics Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1419
block|,
literal|"Excel Switching Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x141b
block|,
literal|"Zoom Telephonics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x141e
block|,
literal|"Fanuc Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x141f
block|,
literal|"Visiontech Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1420
block|,
literal|"Psion Dacom PLC"
block|,
literal|0
block|}
block|,
block|{
literal|0x1425
block|,
literal|"ASIC Designers Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1428
block|,
literal|"Edec Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1429
block|,
literal|"Unex Technology Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x142a
block|,
literal|"Kingmax Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x142b
block|,
literal|"Radiolan"
block|,
literal|0
block|}
block|,
block|{
literal|0x142c
block|,
literal|"Minton Optic Industry Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x142d
block|,
literal|"Pixstream Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1430
block|,
literal|"ITT Aerospace/Communications Division"
block|,
literal|0
block|}
block|,
block|{
literal|0x1433
block|,
literal|"Eltec Elektronik AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x1436
block|,
literal|"CIS Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1437
block|,
literal|"Nissin Inc Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x1438
block|,
literal|"Atmel-Dream"
block|,
literal|0
block|}
block|,
block|{
literal|0x143f
block|,
literal|"Lightwell Co Ltd - Zax Division"
block|,
literal|0
block|}
block|,
block|{
literal|0x1441
block|,
literal|"Agie SA."
block|,
literal|0
block|}
block|,
block|{
literal|0x1445
block|,
literal|"Logical Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1446
block|,
literal|"Graphin Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1447
block|,
literal|"Aim GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1448
block|,
literal|"Alesis Studio"
block|,
name|pci_device_1448
block|}
block|,
block|{
literal|0x144a
block|,
literal|"Adlink Technology"
block|,
name|pci_device_144a
block|}
block|,
block|{
literal|0x144b
block|,
literal|"Loronix Information Systems, Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x144d
block|,
literal|"Samsung Electronics Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1450
block|,
literal|"Octave Communications Ind."
block|,
literal|0
block|}
block|,
block|{
literal|0x1451
block|,
literal|"SP3D Chip Design GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1453
block|,
literal|"Mycom Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1455
block|,
literal|"Logic Plus PLUS Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1458
block|,
literal|"Giga-Byte Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x145c
block|,
literal|"Cryptek"
block|,
literal|0
block|}
block|,
block|{
literal|0x145f
block|,
literal|"Baldor Electric Company"
block|,
name|pci_device_145f
block|}
block|,
block|{
literal|0x1460
block|,
literal|"Dynarc Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1462
block|,
literal|"Micro-Star International Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1463
block|,
literal|"Fast Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1464
block|,
literal|"Interactive Circuits& Systems Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1465
block|,
literal|"GN Nettest Telecom Div."
block|,
literal|0
block|}
block|,
block|{
literal|0x1468
block|,
literal|"Ambit Microsystems Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1469
block|,
literal|"Cleveland Motion Controls"
block|,
literal|0
block|}
block|,
block|{
literal|0x146c
block|,
literal|"Ruby Tech Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x146d
block|,
literal|"Tachyon Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x146e
block|,
literal|"WMS Gaming"
block|,
literal|0
block|}
block|,
block|{
literal|0x1471
block|,
literal|"Integrated Telecom Express Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1473
block|,
literal|"Zapex Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1474
block|,
literal|"Doug Carson& Associates"
block|,
literal|0
block|}
block|,
block|{
literal|0x1477
block|,
literal|"Net Insight"
block|,
literal|0
block|}
block|,
block|{
literal|0x1478
block|,
literal|"Diatrend Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x147b
block|,
literal|"Abit Computer Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x147f
block|,
literal|"Nihon Unisys Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1482
block|,
literal|"Isytec - Integrierte Systemtechnik Gmbh"
block|,
literal|0
block|}
block|,
block|{
literal|0x1483
block|,
literal|"Labway Coporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1485
block|,
literal|"Erma - Electronic GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1489
block|,
literal|"KYE Systems Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x148a
block|,
literal|"Opto 22"
block|,
literal|0
block|}
block|,
block|{
literal|0x148b
block|,
literal|"Innomedialogic Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x148d
block|,
literal|"Digicom Systems Inc."
block|,
name|pci_device_148d
block|}
block|,
block|{
literal|0x148e
block|,
literal|"OSI Plus Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x148f
block|,
literal|"Plant Equipment Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1490
block|,
literal|"TC Labs Pty Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1493
block|,
literal|"Maker Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0x1495
block|,
literal|"Tokai Communications Industry Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1496
block|,
literal|"Joytech Computer Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1497
block|,
literal|"SMA Regelsysteme GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1499
block|,
literal|"Micro-Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x149b
block|,
literal|"Seiko Instruments Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x149e
block|,
literal|"Mapletree Networks Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x149f
block|,
literal|"Lectron Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x14a0
block|,
literal|"Softing GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x14a2
block|,
literal|"Millennium Engineering Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14a4
block|,
literal|"GVC/BCM Advanced Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x14a5
block|,
literal|"Xionics Document Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14a9
block|,
literal|"Hivertec Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14ab
block|,
literal|"Mentor Graphics Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x14b1
block|,
literal|"Nextcom K.K."
block|,
literal|0
block|}
block|,
block|{
literal|0x14b3
block|,
literal|"Xpeed Inc."
block|,
name|pci_device_14b3
block|}
block|,
block|{
literal|0x14b4
block|,
literal|"Philips Business Electronics B.V."
block|,
literal|0
block|}
block|,
block|{
literal|0x14b6
block|,
literal|"Quantum Data Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x14b7
block|,
literal|"Proxim Inc."
block|,
name|pci_device_14b7
block|}
block|,
block|{
literal|0x14b9
block|,
literal|"Aironet Wireless Communication"
block|,
name|pci_device_14b9
block|}
block|,
block|{
literal|0x14ba
block|,
literal|"Internix Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14bb
block|,
literal|"Semtech Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x14be
block|,
literal|"L3 Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0x14c1
block|,
literal|"Myricom Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14c2
block|,
literal|"DTK Computer"
block|,
literal|0
block|}
block|,
block|{
literal|0x14c4
block|,
literal|"Iwasaki Information Systems Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x14c5
block|,
literal|"ABB Automation Products AB"
block|,
literal|0
block|}
block|,
block|{
literal|0x14c6
block|,
literal|"Data Race Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14c9
block|,
literal|"Odin Telesystems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14cb
block|,
literal|"Billionton Systems Inc./Cadmus Micro Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14cd
block|,
literal|"Universal Scientific Ind."
block|,
literal|0
block|}
block|,
block|{
literal|0x14cf
block|,
literal|"TEK Microsystems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14d2
block|,
literal|"Oxford Semiconductor"
block|,
literal|0
block|}
block|,
block|{
literal|0x14d4
block|,
literal|"Panacom Technology Corporation"
block|,
name|pci_device_14d4
block|}
block|,
block|{
literal|0x14d5
block|,
literal|"Nitsuko Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x14d6
block|,
literal|"Accusys Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14d7
block|,
literal|"Hirakawa Hewtech Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x14d8
block|,
literal|"Hopf Elektronik GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x14d9
block|,
literal|"Alpha Processor Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14db
block|,
literal|"Avlab Technology Inc."
block|,
name|pci_device_14db
block|}
block|,
block|{
literal|0x14dc
block|,
literal|"Amplicon Liveline Inc."
block|,
name|pci_device_14dc
block|}
block|,
block|{
literal|0x14dd
block|,
literal|"Imodl Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14de
block|,
literal|"Applied Integration Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x14e3
block|,
literal|"Amtelco"
block|,
literal|0
block|}
block|,
block|{
literal|0x14e4
block|,
literal|"Broadcom Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x14eb
block|,
literal|"Seiko Epson Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x14ec
block|,
literal|"Acqiris"
block|,
literal|0
block|}
block|,
block|{
literal|0x14ed
block|,
literal|"Datakinetics Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x14ef
block|,
literal|"Carry Computer Eng. Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x14f1
block|,
literal|"Conexant Systems, Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14f2
block|,
literal|"Mobility Electronics, Inc."
block|,
name|pci_device_14f2
block|}
block|,
block|{
literal|0x14f4
block|,
literal|"Tokyo Electronic Industry Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x14f5
block|,
literal|"Sopac Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x14f6
block|,
literal|"Coyote Technologies LLC"
block|,
literal|0
block|}
block|,
block|{
literal|0x14f7
block|,
literal|"Wolf Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14f8
block|,
literal|"Audiocodes Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x14f9
block|,
literal|"AG Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0x14fb
block|,
literal|"Transas Marine (UK) Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x14fc
block|,
literal|"Quadrics Supercomputers World"
block|,
literal|0
block|}
block|,
block|{
literal|0x14fd
block|,
literal|"Japan Computer Industry Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x14fe
block|,
literal|"Archtek Telecom Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x14ff
block|,
literal|"Twinhead International Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1500
block|,
literal|"DELTA Electronics, Inc."
block|,
name|pci_device_1500
block|}
block|,
block|{
literal|0x1501
block|,
literal|"Banksoft Canada Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1502
block|,
literal|"Mitsubishi Electric Logistics Support Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x1503
block|,
literal|"Kawasaki LSI USA Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1504
block|,
literal|"Kaiser Electronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x1506
block|,
literal|"Chameleon Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1507
block|,
literal|"Htec Ltd."
block|,
name|pci_device_1507
block|}
block|,
block|{
literal|0x1509
block|,
literal|"First International Computer Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x150b
block|,
literal|"Yamashita Systems Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x150c
block|,
literal|"Kyopal Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x150d
block|,
literal|"Warpspped Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x150e
block|,
literal|"C-Port Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x150f
block|,
literal|"Intec GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1510
block|,
literal|"Behavior Tech Computer Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1511
block|,
literal|"Centillium Technology Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1512
block|,
literal|"Rosun Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1513
block|,
literal|"Raychem"
block|,
literal|0
block|}
block|,
block|{
literal|0x1514
block|,
literal|"TFL LAN Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1515
block|,
literal|"ICS Advent"
block|,
literal|0
block|}
block|,
block|{
literal|0x1516
block|,
literal|"Myson Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1517
block|,
literal|"Echotek Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1518
block|,
literal|"PEP Modular Computers GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1519
block|,
literal|"Telefon Aktiebolaget LM Ericsson"
block|,
literal|0
block|}
block|,
block|{
literal|0x151a
block|,
literal|"Globetek Inc."
block|,
name|pci_device_151a
block|}
block|,
block|{
literal|0x151b
block|,
literal|"Combox Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x151c
block|,
literal|"Digital Audio Labs Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x151d
block|,
literal|"Fujitsu Computer Products Of America"
block|,
literal|0
block|}
block|,
block|{
literal|0x151e
block|,
literal|"Matrix Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x151f
block|,
literal|"Topic Semiconductor Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1520
block|,
literal|"Chaplet System Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1521
block|,
literal|"Bell Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1522
block|,
literal|"Mainpine Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x1523
block|,
literal|"Music Semiconductors"
block|,
literal|0
block|}
block|,
block|{
literal|0x1524
block|,
literal|"ENE Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1525
block|,
literal|"Impact Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x1526
block|,
literal|"ISS Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1527
block|,
literal|"Solectron"
block|,
literal|0
block|}
block|,
block|{
literal|0x1528
block|,
literal|"Acksys"
block|,
literal|0
block|}
block|,
block|{
literal|0x1529
block|,
literal|"American Microsystems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x152a
block|,
literal|"Quickturn Design Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x152b
block|,
literal|"Flytech Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x152c
block|,
literal|"Macraigor Systems LLC"
block|,
literal|0
block|}
block|,
block|{
literal|0x152d
block|,
literal|"Quanta Computer Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x152e
block|,
literal|"Melec Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x152f
block|,
literal|"Philips - Crypto"
block|,
literal|0
block|}
block|,
block|{
literal|0x1532
block|,
literal|"Echelon Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1533
block|,
literal|"Baltimore"
block|,
literal|0
block|}
block|,
block|{
literal|0x1534
block|,
literal|"Road Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1535
block|,
literal|"Evergreen Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1537
block|,
literal|"Datalex Communcations"
block|,
literal|0
block|}
block|,
block|{
literal|0x1538
block|,
literal|"Aralion Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1539
block|,
literal|"Atelier Informatiques et Electronique Et"
block|,
literal|0
block|}
block|,
block|{
literal|0x153a
block|,
literal|"ONO Sokki"
block|,
literal|0
block|}
block|,
block|{
literal|0x153b
block|,
literal|"Terratec Electronic GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x153c
block|,
literal|"Antal Electronic"
block|,
literal|0
block|}
block|,
block|{
literal|0x153d
block|,
literal|"Filanet Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x153e
block|,
literal|"Techwell Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x153f
block|,
literal|"MIPS Denmark"
block|,
literal|0
block|}
block|,
block|{
literal|0x1540
block|,
literal|"Provideo Multimedia Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1541
block|,
literal|"Telocity Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1542
block|,
literal|"Vivid Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1543
block|,
literal|"Silicon Laboratories"
block|,
literal|0
block|}
block|,
block|{
literal|0x1544
block|,
literal|"DCM Data Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1545
block|,
literal|"Visiontek"
block|,
literal|0
block|}
block|,
block|{
literal|0x1546
block|,
literal|"IOI Technology Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1547
block|,
literal|"Mitutoyo Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1548
block|,
literal|"Jet Propulsion Laboratory"
block|,
literal|0
block|}
block|,
block|{
literal|0x1549
block|,
literal|"Interconnect Systems Solutions"
block|,
literal|0
block|}
block|,
block|{
literal|0x154a
block|,
literal|"Max Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x154b
block|,
literal|"Computex Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x154c
block|,
literal|"Visual Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x154d
block|,
literal|"PAN International Industrial Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x154e
block|,
literal|"Servotest Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x154f
block|,
literal|"Stratabeam Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1550
block|,
literal|"Open Network Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1551
block|,
literal|"Smart Electronic Development GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1552
block|,
literal|"Racal Airtech Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1553
block|,
literal|"Chicony Electronics Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1554
block|,
literal|"Prolink Microsystems Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1556
block|,
literal|"PLD Applications"
block|,
literal|0
block|}
block|,
block|{
literal|0x1557
block|,
literal|"Mediastar Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1558
block|,
literal|"Clevo/Kapok Computer"
block|,
literal|0
block|}
block|,
block|{
literal|0x1559
block|,
literal|"SI Logic Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x155a
block|,
literal|"Innomedia Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x155b
block|,
literal|"Protac International Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x155c
block|,
literal|"Cemax-Icon Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x155d
block|,
literal|"MAC System Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x155e
block|,
literal|"LP Elektronik GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x155f
block|,
literal|"Perle Systems Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x1560
block|,
literal|"Terayon Communications Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1561
block|,
literal|"Viewgraphics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1562
block|,
literal|"Symbol Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x1563
block|,
literal|"A-Trend Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1564
block|,
literal|"Yamakatsu Electronics Industry Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1565
block|,
literal|"Biostar Microtech Intl Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1566
block|,
literal|"Ardent Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1567
block|,
literal|"Jungsoft"
block|,
literal|0
block|}
block|,
block|{
literal|0x1568
block|,
literal|"DDK Electronics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1569
block|,
literal|"Palit Microsystems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x156a
block|,
literal|"Avtec Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x156b
block|,
literal|"2wire Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x156c
block|,
literal|"Vidac Electronics GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x156d
block|,
literal|"Alpha-Top Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x156e
block|,
literal|"Alfa Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x156f
block|,
literal|"M-Systems Flash Disk Pioneers Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1570
block|,
literal|"Lecroy Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1571
block|,
literal|"Contemporary Controls"
block|,
literal|0
block|}
block|,
block|{
literal|0x1572
block|,
literal|"Otis Elevator Company"
block|,
literal|0
block|}
block|,
block|{
literal|0x1573
block|,
literal|"Lattice - Vantis"
block|,
literal|0
block|}
block|,
block|{
literal|0x1574
block|,
literal|"Fairchild Semiconductor"
block|,
literal|0
block|}
block|,
block|{
literal|0x1575
block|,
literal|"Voltaire Advanced Data Security Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1576
block|,
literal|"Viewcast Com"
block|,
literal|0
block|}
block|,
block|{
literal|0x1578
block|,
literal|"Hitt"
block|,
literal|0
block|}
block|,
block|{
literal|0x1579
block|,
literal|"Dual Technology Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x157a
block|,
literal|"Japan Elecronics Ind. Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x157b
block|,
literal|"Star Multimedia Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x157c
block|,
literal|"Eurosoft (UK)"
block|,
name|pci_device_157c
block|}
block|,
block|{
literal|0x157d
block|,
literal|"Gemflex Networks"
block|,
literal|0
block|}
block|,
block|{
literal|0x157e
block|,
literal|"Transition Networks"
block|,
literal|0
block|}
block|,
block|{
literal|0x157f
block|,
literal|"PX Instruments Technology Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1580
block|,
literal|"Primex Aerospace Co."
block|,
literal|0
block|}
block|,
block|{
literal|0x1581
block|,
literal|"SEH Computertechnik GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1582
block|,
literal|"Cytec Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1583
block|,
literal|"Inet Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1584
block|,
literal|"Uniwill Computer Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1585
block|,
literal|"Marconi Commerce Systems SRL"
block|,
literal|0
block|}
block|,
block|{
literal|0x1586
block|,
literal|"Lancast Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1587
block|,
literal|"Konica Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1588
block|,
literal|"Solidum Systems Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1589
block|,
literal|"Atlantek Microsystems Pty Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x158a
block|,
literal|"Digalog Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x158b
block|,
literal|"Allied Data Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x158c
block|,
literal|"Hitachi Semiconductor& Devices Sales Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x158d
block|,
literal|"Point Multimedia Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x158e
block|,
literal|"Lara Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x158f
block|,
literal|"Ditect Coop"
block|,
literal|0
block|}
block|,
block|{
literal|0x1590
block|,
literal|"3pardata Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1591
block|,
literal|"ARN"
block|,
literal|0
block|}
block|,
block|{
literal|0x1592
block|,
literal|"Syba Tech Ltd."
block|,
name|pci_device_1592
block|}
block|,
block|{
literal|0x1593
block|,
literal|"Bops Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1594
block|,
literal|"Netgame Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1595
block|,
literal|"Diva Systems Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1596
block|,
literal|"Folsom Research Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1597
block|,
literal|"Memec Design Services"
block|,
literal|0
block|}
block|,
block|{
literal|0x1598
block|,
literal|"Granite Microsystems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1599
block|,
literal|"Delta Electronics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x159a
block|,
literal|"General Instrument"
block|,
literal|0
block|}
block|,
block|{
literal|0x159b
block|,
literal|"Faraday Technology Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x159c
block|,
literal|"Stratus Computer Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x159d
block|,
literal|"Ningbo Harrison Electronics Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x159e
block|,
literal|"A-Max Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x159f
block|,
literal|"Galea Network Security"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a0
block|,
literal|"Compumaster SRL"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a1
block|,
literal|"Geocast Network Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a2
block|,
literal|"Catalyst Enterprises Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a3
block|,
literal|"Italtel"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a4
block|,
literal|"X-Net OY"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a5
block|,
literal|"Toyota MACS Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a6
block|,
literal|"Sunlight Ultrasound Technologies Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a7
block|,
literal|"SSE Telecom Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15a8
block|,
literal|"Shanghai Communications Technologies Cen"
block|,
literal|0
block|}
block|,
block|{
literal|0x15aa
block|,
literal|"Moreton Bay"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ab
block|,
literal|"Bluesteel Networks Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ac
block|,
literal|"North Atlantic Instruments"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ad
block|,
literal|"VMware Inc."
block|,
name|pci_device_15ad
block|}
block|,
block|{
literal|0x15ae
block|,
literal|"Amersham Pharmacia Biotech"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b0
block|,
literal|"Zoltrix International Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b1
block|,
literal|"Source Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b2
block|,
literal|"Mosaid Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15b3
block|,
literal|"Mellanox Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b4
block|,
literal|"CCI/Triad"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b5
block|,
literal|"Cimetrics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b6
block|,
literal|"Texas Memory Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b7
block|,
literal|"Sandisk Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x15b8
block|,
literal|"Addi-Data GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x15b9
block|,
literal|"Maestro Digital Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ba
block|,
literal|"Impacct Technology Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x15bb
block|,
literal|"Portwell Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15bc
block|,
literal|"Agilent Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x15bd
block|,
literal|"DFI Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15be
block|,
literal|"Sola Electronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x15bf
block|,
literal|"High Tech Computer Corp (HTC)"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c0
block|,
literal|"BVM Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c1
block|,
literal|"Quantel"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c2
block|,
literal|"Newer Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c3
block|,
literal|"Taiwan Mycomp Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c4
block|,
literal|"EVSX Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c5
block|,
literal|"Procomp Informatics Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c6
block|,
literal|"Technical University Of Budapest"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c7
block|,
literal|"Tateyama System Laboratory Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c8
block|,
literal|"Penta Media Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15c9
block|,
literal|"Serome Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ca
block|,
literal|"Bitboys OY"
block|,
literal|0
block|}
block|,
block|{
literal|0x15cb
block|,
literal|"AG Electronics Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15cc
block|,
literal|"Hotrail Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15cd
block|,
literal|"Dreamtech Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ce
block|,
literal|"Genrad Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15cf
block|,
literal|"Hilscher GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d1
block|,
literal|"Infineon Technologies AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d2
block|,
literal|"FIC (First International Computer Inc)"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d3
block|,
literal|"NDS Technologies Israel Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d4
block|,
literal|"Iwill Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d5
block|,
literal|"Tatung Co."
block|,
literal|0
block|}
block|,
block|{
literal|0x15d6
block|,
literal|"Entridia Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d7
block|,
literal|"Rockwell-Collins Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d8
block|,
literal|"Cybernetics Technology Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15d9
block|,
literal|"Super Micro Computer Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15da
block|,
literal|"Cyberfirm Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15db
block|,
literal|"Applied Computing Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15dc
block|,
literal|"Litronic Inc."
block|,
name|pci_device_15dc
block|}
block|,
block|{
literal|0x15dd
block|,
literal|"Sigmatel Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15de
block|,
literal|"Malleable Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15df
block|,
literal|"Infinilink Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x15e0
block|,
literal|"Cacheflow Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15e1
block|,
literal|"Voice Technologies Group"
block|,
literal|0
block|}
block|,
block|{
literal|0x15e2
block|,
literal|"Quicknet Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15e3
block|,
literal|"Networth Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15e4
block|,
literal|"VSN Systemen BV"
block|,
literal|0
block|}
block|,
block|{
literal|0x15e5
block|,
literal|"Valley Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15e6
block|,
literal|"Agere Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15e7
block|,
literal|"GET Engineering Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x15e8
block|,
literal|"National Datacomm Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x15e9
block|,
literal|"Pacific Digital Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x15ea
block|,
literal|"Tokyo Denshi Sekei K.K."
block|,
literal|0
block|}
block|,
block|{
literal|0x15eb
block|,
literal|"Drsearch GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ec
block|,
literal|"Beckhoff GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ed
block|,
literal|"Macrolink Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ee
block|,
literal|"IN Win Development Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15ef
block|,
literal|"Intelligent Paradigm Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f0
block|,
literal|"B-Tree Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f1
block|,
literal|"Times N Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f2
block|,
literal|"Diagnostic Instruments Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f3
block|,
literal|"Digitmedia Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x15f4
block|,
literal|"Valuesoft"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f5
block|,
literal|"Power Micro Research"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f6
block|,
literal|"Extreme Packet Device Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f7
block|,
literal|"Banctec"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f8
block|,
literal|"Koga Electronics Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x15f9
block|,
literal|"Zenith Electronics Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x15fa
block|,
literal|"J.P. Axzam Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x15fb
block|,
literal|"Zilog Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x15fc
block|,
literal|"Techsan Electronics Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x15fd
block|,
literal|"N-Cubed.Net"
block|,
literal|0
block|}
block|,
block|{
literal|0x15fe
block|,
literal|"Kinpo Electronics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x15ff
block|,
literal|"Fastpoint Technologies Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1600
block|,
literal|"Northrop Grumman - Canada Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1601
block|,
literal|"Tenta Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1602
block|,
literal|"Prosys-TEC Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1603
block|,
literal|"Nokia Wireless Business Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0x1604
block|,
literal|"Central System Research Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1605
block|,
literal|"Pairgain Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x1606
block|,
literal|"Europop AG"
block|,
literal|0
block|}
block|,
block|{
literal|0x1607
block|,
literal|"Lava Semiconductor Manufacturing Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1608
block|,
literal|"Automated Wagering International"
block|,
literal|0
block|}
block|,
block|{
literal|0x1609
block|,
literal|"Sciemetric Instruments Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x160a
block|,
literal|"Kollmorgen Servotronix"
block|,
literal|0
block|}
block|,
block|{
literal|0x160b
block|,
literal|"Onkyo Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x160c
block|,
literal|"Oregon Micro Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x160d
block|,
literal|"Aaeon Electronics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x160e
block|,
literal|"CML Emergency Services"
block|,
literal|0
block|}
block|,
block|{
literal|0x160f
block|,
literal|"ITEC Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1610
block|,
literal|"Tottori Sanyo Electric Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1611
block|,
literal|"Bel Fuse Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1612
block|,
literal|"Telesynergy Research Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1613
block|,
literal|"System Craft Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1614
block|,
literal|"Jace Tech Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1615
block|,
literal|"Equus Computer Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1616
block|,
literal|"Iotech Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1617
block|,
literal|"Rapidstream Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1618
block|,
literal|"Esec SA"
block|,
literal|0
block|}
block|,
block|{
literal|0x1619
block|,
literal|"FarSite Communications Limited"
block|,
name|pci_device_1619
block|}
block|,
block|{
literal|0x161a
block|,
literal|"Wvinten Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x161b
block|,
literal|"Mobilian Israel Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x161c
block|,
literal|"Berkshire Products"
block|,
literal|0
block|}
block|,
block|{
literal|0x161d
block|,
literal|"Gatec"
block|,
literal|0
block|}
block|,
block|{
literal|0x161e
block|,
literal|"Kyoei Sangyo Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x161f
block|,
literal|"Arima Computer Co"
block|,
literal|0
block|}
block|,
block|{
literal|0x1620
block|,
literal|"Sigmacom Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1621
block|,
literal|"Lynx Studio Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1622
block|,
literal|"Nokia Home Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0x1623
block|,
literal|"KRF Tech Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1624
block|,
literal|"CE Infosys GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1625
block|,
literal|"Warp Nine Engineering"
block|,
literal|0
block|}
block|,
block|{
literal|0x1626
block|,
literal|"TDK Semiconductor Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1627
block|,
literal|"BCom Electronics Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1629
block|,
literal|"Kongsberg Spacetec a.s."
block|,
literal|0
block|}
block|,
block|{
literal|0x162a
block|,
literal|"Sejin Computerland Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x162b
block|,
literal|"Shanghai Bell Company Limited"
block|,
literal|0
block|}
block|,
block|{
literal|0x162c
block|,
literal|"C&H Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x162d
block|,
literal|"Reprosoft Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x162e
block|,
literal|"Margi Systems Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x162f
block|,
literal|"Rohde& Schwarz GMBH& Co KG"
block|,
literal|0
block|}
block|,
block|{
literal|0x1630
block|,
literal|"Sky Computers Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1631
block|,
literal|"NEC Computer International"
block|,
literal|0
block|}
block|,
block|{
literal|0x1632
block|,
literal|"Verisys Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1633
block|,
literal|"Adac Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1634
block|,
literal|"Visionglobal Network Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1635
block|,
literal|"Decros"
block|,
literal|0
block|}
block|,
block|{
literal|0x1636
block|,
literal|"Jean Company Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1637
block|,
literal|"NSI"
block|,
literal|0
block|}
block|,
block|{
literal|0x1638
block|,
literal|"Eumitcom Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x163a
block|,
literal|"Air Prime Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x163b
block|,
literal|"Glotrex Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x163c
block|,
literal|"Smart Link"
block|,
literal|0
block|}
block|,
block|{
literal|0x163d
block|,
literal|"Heidelberg Digital LLC"
block|,
literal|0
block|}
block|,
block|{
literal|0x163e
block|,
literal|"3dpower"
block|,
literal|0
block|}
block|,
block|{
literal|0x163f
block|,
literal|"Renishaw PLC"
block|,
literal|0
block|}
block|,
block|{
literal|0x1640
block|,
literal|"Intelliworxx Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1641
block|,
literal|"MKNet Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1642
block|,
literal|"Bitland"
block|,
literal|0
block|}
block|,
block|{
literal|0x1643
block|,
literal|"Hajime Industries Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1644
block|,
literal|"Western Avionics Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1645
block|,
literal|"Quick-Serv. Computer Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1646
block|,
literal|"Nippon Systemware Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x1647
block|,
literal|"Hertz Systemtechnik GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0x1648
block|,
literal|"MeltDown Systems LLC"
block|,
literal|0
block|}
block|,
block|{
literal|0x1649
block|,
literal|"Jupiter Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x164a
block|,
literal|"Aiwa Co. Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x164c
block|,
literal|"Department Of Defense"
block|,
literal|0
block|}
block|,
block|{
literal|0x164d
block|,
literal|"Ishoni Networks"
block|,
literal|0
block|}
block|,
block|{
literal|0x164e
block|,
literal|"Micrel Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x164f
block|,
literal|"Datavoice (Pty) Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1650
block|,
literal|"Admore Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1651
block|,
literal|"Chaparral Network Storage"
block|,
literal|0
block|}
block|,
block|{
literal|0x1652
block|,
literal|"Spectrum Digital Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1653
block|,
literal|"Nature Worldwide Technology Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1654
block|,
literal|"Sonicwall Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1655
block|,
literal|"Dazzle Multimedia Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1656
block|,
literal|"Insyde Software Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x1657
block|,
literal|"Brocade Communications Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x1658
block|,
literal|"Med Associates Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1659
block|,
literal|"Shiba Denshi Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x165a
block|,
literal|"Epix Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x165b
block|,
literal|"Real-Time Digital Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x165c
block|,
literal|"Gidel Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x165d
block|,
literal|"Hsing Tech. Enterprise Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x165e
block|,
literal|"Hyunju Computer Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x165f
block|,
literal|"Add One Company"
block|,
literal|0
block|}
block|,
block|{
literal|0x1660
block|,
literal|"Network Security Technologies Inc. (Net "
block|,
literal|0
block|}
block|,
block|{
literal|0x1661
block|,
literal|"Worldspace Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x1662
block|,
literal|"Int Labs"
block|,
literal|0
block|}
block|,
block|{
literal|0x1663
block|,
literal|"Elmec Inc. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1664
block|,
literal|"Fastfame Technology Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1665
block|,
literal|"Edax Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1666
block|,
literal|"Norpak Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1667
block|,
literal|"CoSystems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x166a
block|,
literal|"Komatsu Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x166b
block|,
literal|"Supernet Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x166c
block|,
literal|"Shade Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x166d
block|,
literal|"Sibyte Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x166e
block|,
literal|"Schneider Automation Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x166f
block|,
literal|"Televox Software Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1670
block|,
literal|"Rearden Steel"
block|,
literal|0
block|}
block|,
block|{
literal|0x1671
block|,
literal|"Atan Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1672
block|,
literal|"Unitec Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1673
block|,
literal|"Connex"
block|,
literal|0
block|}
block|,
block|{
literal|0x1675
block|,
literal|"Square Wave Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x1676
block|,
literal|"Emachines Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x1677
block|,
literal|"Bernecker + Rainer"
block|,
literal|0
block|}
block|,
block|{
literal|0x1678
block|,
literal|"INH Semiconductor"
block|,
literal|0
block|}
block|,
block|{
literal|0x1679
block|,
literal|"Tokyo Electron Device Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x1813
block|,
literal|"Ambient Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x1a08
block|,
literal|"Sierra Semiconductor"
block|,
name|pci_device_1a08
block|}
block|,
block|{
literal|0x1b13
block|,
literal|"Jaton Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x1c1c
block|,
literal|"Symphony"
block|,
name|pci_device_1c1c
block|}
block|,
block|{
literal|0x1d44
block|,
literal|"Distributed Processing Technology"
block|,
name|pci_device_1d44
block|}
block|,
block|{
literal|0x1de1
block|,
literal|"Tekram"
block|,
name|pci_device_1de1
block|}
block|,
block|{
literal|0x2001
block|,
literal|"Temporal Research Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x2348
block|,
literal|"Racore"
block|,
name|pci_device_2348
block|}
block|,
block|{
literal|0x2646
block|,
literal|"Kingston Technology Co."
block|,
literal|0
block|}
block|,
block|{
literal|0x270f
block|,
literal|"ChainTech Computer Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x2ec1
block|,
literal|"Zenic Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x3000
block|,
literal|"Hansol Electronics Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x3142
block|,
literal|"Post Impressions Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x3388
block|,
literal|"Hint Corp."
block|,
name|pci_device_3388
block|}
block|,
block|{
literal|0x3411
block|,
literal|"Quantum Designs (H.K.) Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x3513
block|,
literal|"ARCOM Control Systems Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x38ef
block|,
literal|"4links"
block|,
literal|0
block|}
block|,
block|{
literal|0x3d3d
block|,
literal|"3Dlabs, Inc. Ltd"
block|,
name|pci_device_3d3d
block|}
block|,
block|{
literal|0x4005
block|,
literal|"Avance Logic Inc."
block|,
name|pci_device_4005
block|}
block|,
block|{
literal|0x4033
block|,
literal|"Addtron Technology Co., Inc."
block|,
name|pci_device_4033
block|}
block|,
block|{
literal|0x4143
block|,
literal|"Digital Equipment Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x416c
block|,
literal|"Aladdin Knowledge Systems"
block|,
literal|0
block|}
block|,
block|{
literal|0x4444
block|,
literal|"ICompression Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x4468
block|,
literal|"Bridgeport Machines"
block|,
literal|0
block|}
block|,
block|{
literal|0x4594
block|,
literal|"Cogetec Informatique Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x45fb
block|,
literal|"Baldor Electric Company"
block|,
literal|0
block|}
block|,
block|{
literal|0x4680
block|,
literal|"UMAX Computer Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x4843
block|,
literal|"Hercules Computer Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0x4943
block|,
literal|"Growth Networks"
block|,
literal|0
block|}
block|,
block|{
literal|0x4954
block|,
literal|"Integral Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x4978
block|,
literal|"Axil Computer Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x4a14
block|,
literal|"NetVin"
block|,
name|pci_device_4a14
block|}
block|,
block|{
literal|0x4b10
block|,
literal|"Buslogic Inc"
block|,
name|pci_device_4b10
block|}
block|,
block|{
literal|0x4c48
block|,
literal|"Lung Hwa Electronics"
block|,
literal|0
block|}
block|,
block|{
literal|0x4c53
block|,
literal|"SBS-OR Industrial Computers"
block|,
literal|0
block|}
block|,
block|{
literal|0x4ca1
block|,
literal|"Seanix Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x4d51
block|,
literal|"Mediaq Inc."
block|,
name|pci_device_4d51
block|}
block|,
block|{
literal|0x4d54
block|,
literal|"Microtechnica Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x4ddc
block|,
literal|"ILC Data Device Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x5053
block|,
literal|"TBS/Voyetra Technologies"
block|,
name|pci_device_5053
block|}
block|,
block|{
literal|0x5136
block|,
literal|"S S Technologies"
block|,
literal|0
block|}
block|,
block|{
literal|0x5143
block|,
literal|"Qualcomm Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x5145
block|,
literal|"ENSONIQ"
block|,
name|pci_device_5145
block|}
block|,
block|{
literal|0x5301
block|,
literal|"Alliance Semicondutor Corp."
block|,
name|pci_device_5301
block|}
block|,
block|{
literal|0x5333
block|,
literal|"S3 Incorporated"
block|,
name|pci_device_5333
block|}
block|,
block|{
literal|0x544c
block|,
literal|"Teralogic Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0x5455
block|,
literal|"Technische Universtiaet Berlin"
block|,
name|pci_device_5455
block|}
block|,
block|{
literal|0x5519
block|,
literal|"Cnet Technoliges, Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x5555
block|,
literal|"Genroco Inc."
block|,
name|pci_device_5555
block|}
block|,
block|{
literal|0x5700
block|,
literal|"Netpower"
block|,
literal|0
block|}
block|,
block|{
literal|0x6356
block|,
literal|"UltraStor"
block|,
name|pci_device_6356
block|}
block|,
block|{
literal|0x6374
block|,
literal|"c't Magazin f_r Computertechnik"
block|,
name|pci_device_6374
block|}
block|,
block|{
literal|0x6409
block|,
literal|"Logitec Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0x6666
block|,
literal|"Decision Computer International Co."
block|,
name|pci_device_6666
block|}
block|,
block|{
literal|0x7604
block|,
literal|"O.N. Electric Co. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0x7747
block|,
literal|"DaoGuo Technology Co.,Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0x7bde
block|,
literal|"MIDAC Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x7fed
block|,
literal|"PowerTV"
block|,
literal|0
block|}
block|,
block|{
literal|0x8001
block|,
literal|"Beyertone AG - Germany"
block|,
name|pci_device_8001
block|}
block|,
block|{
literal|0x8008
block|,
literal|"QUANCOM Informationssysteme GmbH"
block|,
name|pci_device_8008
block|}
block|,
block|{
literal|0x8086
block|,
literal|"Intel Corporation"
block|,
name|pci_device_8086
block|}
block|,
block|{
literal|0x8800
block|,
literal|"Trigem Computer"
block|,
name|pci_device_8800
block|}
block|,
block|{
literal|0x8866
block|,
literal|"T-Square Design Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x8888
block|,
literal|"Silicon Magic"
block|,
literal|0
block|}
block|,
block|{
literal|0x8e0e
block|,
literal|"Computone Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0x8e2e
block|,
literal|"KTI"
block|,
name|pci_device_8e2e
block|}
block|,
block|{
literal|0x9004
block|,
literal|"Adaptec"
block|,
name|pci_device_9004
block|}
block|,
block|{
literal|0x9005
block|,
literal|"Adaptec"
block|,
name|pci_device_9005
block|}
block|,
block|{
literal|0x907f
block|,
literal|"Atronics"
block|,
name|pci_device_907f
block|}
block|,
block|{
literal|0x919a
block|,
literal|"Gigapixel Corp"
block|,
literal|0
block|}
block|,
block|{
literal|0x9412
block|,
literal|"Holtek"
block|,
name|pci_device_9412
block|}
block|,
block|{
literal|0x9699
block|,
literal|"Omni Media Technology Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0x9902
block|,
literal|"Starbridge Technologies Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0xa0a0
block|,
literal|"Aopen Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0xa0f1
block|,
literal|"Unisys Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0xa200
block|,
literal|"NEC Corp."
block|,
literal|0
block|}
block|,
block|{
literal|0xa259
block|,
literal|"Hewlett Packard"
block|,
literal|0
block|}
block|,
block|{
literal|0xa25b
block|,
literal|"Hewlett Packard GmbH PL24-MKT"
block|,
literal|0
block|}
block|,
block|{
literal|0xa304
block|,
literal|"Sony"
block|,
literal|0
block|}
block|,
block|{
literal|0xa727
block|,
literal|"3com Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0xaa42
block|,
literal|"Scitex Digital Video"
block|,
literal|0
block|}
block|,
block|{
literal|0xac1e
block|,
literal|"Digital Receiver Technology Inc"
block|,
literal|0
block|}
block|,
block|{
literal|0xb1b3
block|,
literal|"Shiva Europe Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0xb894
block|,
literal|"Brown& Sharpe Mfg. Co."
block|,
literal|0
block|}
block|,
block|{
literal|0xc001
block|,
literal|"TSI Telsys"
block|,
literal|0
block|}
block|,
block|{
literal|0xc0a9
block|,
literal|"Micron/Crucial Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0xc0de
block|,
literal|"Motorola"
block|,
literal|0
block|}
block|,
block|{
literal|0xc0fe
block|,
literal|"Motion Engineering Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0xc622
block|,
literal|"Hudson Soft Co Ltd"
block|,
literal|0
block|}
block|,
block|{
literal|0xca50
block|,
literal|"Varian Australia Pty. Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0xcafe
block|,
literal|"Chrysalis-ITS"
block|,
literal|0
block|}
block|,
block|{
literal|0xcccc
block|,
literal|"Catapult Communications"
block|,
literal|0
block|}
block|,
block|{
literal|0xd4d4
block|,
literal|"DY4 Systems Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0xd84d
block|,
literal|"Exsys"
block|,
literal|0
block|}
block|,
block|{
literal|0xdc93
block|,
literal|"Dawicontrol"
block|,
literal|0
block|}
block|,
block|{
literal|0xdead
block|,
literal|"Indigita Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0xe000
block|,
literal|"Winbond"
block|,
name|pci_device_e000
block|}
block|,
block|{
literal|0xe159
block|,
literal|"Tiger Jet Network Inc"
block|,
name|pci_device_e159
block|}
block|,
block|{
literal|0xe4bf
block|,
literal|"EKF Elektronik GMBH"
block|,
literal|0
block|}
block|,
block|{
literal|0xea01
block|,
literal|"Eagle Technology"
block|,
literal|0
block|}
block|,
block|{
literal|0xecc0
block|,
literal|"Echo Corporation"
block|,
literal|0
block|}
block|,
block|{
literal|0xedd8
block|,
literal|"ARK Logic, Inc"
block|,
name|pci_device_edd8
block|}
block|,
block|{
literal|0xf5f5
block|,
literal|"F5 Networks Inc."
block|,
literal|0
block|}
block|,
block|{
literal|0xfa57
block|,
literal|"Fast Search& Transfer ASA"
block|,
literal|0
block|}
block|,
block|{
literal|0xfeda
block|,
literal|"Epigram Inc                             "
block|,
literal|0
block|}
block|,
block|{
literal|0xfffe
block|,
literal|"VMware Inc."
block|,
name|pci_device_fffe
block|}
block|,
block|{
literal|0xffff
block|,
literal|"ILLEGITIMATE VENDOR ID"
block|,
name|pci_device_ffff
block|}
block|,
block|{
literal|0x00c7
block|,
literal|"Modular Technology Ltd."
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

