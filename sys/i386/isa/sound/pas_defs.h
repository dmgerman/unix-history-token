begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 																*/
end_comment

begin_comment
comment|/*	Port addresses and bit fields for the Media Vision Pro AudioSpectrum second generation sound cards.			*/
end_comment

begin_comment
comment|/* 																*/
end_comment

begin_comment
comment|/* 	Feel free to use this header file in any application you create that has support for the Media Vision			*/
end_comment

begin_comment
comment|/*	Pro AudioSpectrum second generation sound cards. Other uses prohibited without prior permission.			*/
end_comment

begin_comment
comment|/* 																*/
end_comment

begin_comment
comment|/*										- cmetz@thor.tjhsst.edu				*/
end_comment

begin_comment
comment|/* 																*/
end_comment

begin_comment
comment|/*	Notes:															*/
end_comment

begin_comment
comment|/* 																*/
end_comment

begin_comment
comment|/*	*	All of these ports go into the MVD101 multimedia controller chip, which	then signals the other chips to do	*/
end_comment

begin_comment
comment|/* 		the actual work. Many ports like the FM ones functionally attach directly to the destination chip though 	*/
end_comment

begin_comment
comment|/* 		they don't actually have a direct connection.									*/
end_comment

begin_comment
comment|/* 																*/
end_comment

begin_comment
comment|/* 	*	The PAS2 series cards have an MVD101 multimedia controller chip, the original PAS cards don't. The original	*/
end_comment

begin_comment
comment|/* 		PAS cards are pretty defunct now, so no attempt is made here to support them. 					*/
end_comment

begin_comment
comment|/*																*/
end_comment

begin_comment
comment|/*	*	The PAS2 series cards are all really different at the hardware level, though the MVD101 hides some of the 	*/
end_comment

begin_comment
comment|/*		incompatibilities, there still are differences that need to be accounted for.					*/
end_comment

begin_comment
comment|/*																*/
end_comment

begin_comment
comment|/*		Card		CD-ROM interface	PCM chip		Mixer chip		FM chip			*/
end_comment

begin_comment
comment|/* 		PAS Plus	Sony proprietary	(Crystal?) 8-bit DAC	National 		OPL3			*/
end_comment

begin_comment
comment|/* 		PAS 16		Zilog SCSI		MVA416 16-bit Codec	MVA508 			OPL3			*/
end_comment

begin_comment
comment|/* 		CDPC		Sony proprietary	Sony 16-bit Codec	National		OPL3			*/
end_comment

begin_comment
comment|/*		Fusion CD 16	Sony proprietary	MVA416 16-bit Codec	MVA508			OPL3			*/
end_comment

begin_comment
comment|/*		Fusion CD	Sony proprietary	(Crystal?) 8-bit DAC	National		OPL3			*/
end_comment

begin_comment
comment|/* 																*/
end_comment

begin_define
define|#
directive|define
name|PAS_DEFAULT_BASE
value|0x388
end_define

begin_comment
comment|/*      Symbolic Name			Value 		   R W  Subsystem	Description					*/
end_comment

begin_define
define|#
directive|define
name|SPEAKER_CONTROL
value|0x61
end_define

begin_comment
comment|/*   W	PC speaker 	Control register 				*/
end_comment

begin_define
define|#
directive|define
name|SPEAKER_CONTROL_GHOST
value|0x738B
end_define

begin_comment
comment|/* R W	PC speaker 	Control ghost register				*/
end_comment

begin_define
define|#
directive|define
name|SPEAKER_TIMER_CONTROL
value|0x43
end_define

begin_comment
comment|/*   W  PC speaker 	Timer control register				*/
end_comment

begin_define
define|#
directive|define
name|SPEAKER_TIMER_CONTROL_GHOST
value|0x778B
end_define

begin_comment
comment|/* R W  PC speaker 	Timer control register ghost			*/
end_comment

begin_define
define|#
directive|define
name|SPEAKER_TIMER_DATA
value|0x42
end_define

begin_comment
comment|/*   W  PC speaker 	Timer data register				*/
end_comment

begin_define
define|#
directive|define
name|SPEAKER_TIMER_DATA_GHOST
value|0x138A
end_define

begin_comment
comment|/* R W  PC speaker	Timer data register ghost			*/
end_comment

begin_define
define|#
directive|define
name|WARM_BOOT
value|0x41
end_define

begin_comment
comment|/*   W  Control		Used to detect system warm boot	  		*/
end_comment

begin_define
define|#
directive|define
name|WARM_BOOT_GHOST
value|0x7789
end_define

begin_comment
comment|/* ? W  Control		Use to get the card to fake warm boot		*/
end_comment

begin_define
define|#
directive|define
name|MASTER_DECODE
value|0x9A01
end_define

begin_comment
comment|/*   W  Control		Address>> 2 of card base address		*/
end_comment

begin_define
define|#
directive|define
name|PRESCALE_DIVIDER
value|0xBF8A
end_define

begin_comment
comment|/* R W	PCM		Ration between Codec clock and master clock	*/
end_comment

begin_define
define|#
directive|define
name|WAIT_STATE
value|0xBF88
end_define

begin_comment
comment|/* R W	Control		Four-bit bus wait-state count (~140ns ea.)	*/
end_comment

begin_define
define|#
directive|define
name|BOARD_REV_ID
value|0x2789
end_define

begin_comment
comment|/* R	Control		Extended Board Revision ID			*/
end_comment

begin_define
define|#
directive|define
name|CHIP_REV
value|0xFF88
end_define

begin_comment
comment|/* R	0=PAS, 1=PAS+, 2=CDPC, 3=PAS16C, 4=PAS16D */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_CONFIGURATION_1
value|0x8388
end_define

begin_comment
comment|/* R W	Control								*/
end_comment

begin_define
define|#
directive|define
name|S_C_1_PCS_ENABLE
value|0x01
end_define

begin_comment
comment|/* R W  PC speaker	1=enable, 0=disable PC speaker emulation	*/
end_comment

begin_define
define|#
directive|define
name|S_C_1_PCM_CLOCK_SELECT
value|0x02
end_define

begin_comment
comment|/* R W  PCM		1=14.31818Mhz/12, 0=28.224Mhz master clock	*/
end_comment

begin_define
define|#
directive|define
name|S_C_1_FM_EMULATE_CLOCK
value|0x04
end_define

begin_comment
comment|/* R W  FM		1=use 28.224Mhz/2, 0=use 14.31818Mhz clock	*/
end_comment

begin_define
define|#
directive|define
name|S_C_1_PCS_STEREO
value|0x10
end_define

begin_comment
comment|/* R W  PC speaker	1=enable PC speaker stereo effect, 0=disable	*/
end_comment

begin_define
define|#
directive|define
name|S_C_1_PCS_REALSOUND
value|0x20
end_define

begin_comment
comment|/* R W  PC speaker	1=enable RealSound enhancement, 0=disable	*/
end_comment

begin_define
define|#
directive|define
name|S_C_1_FORCE_EXT_RESET
value|0x40
end_define

begin_comment
comment|/* R W  Control		Force external reset				*/
end_comment

begin_define
define|#
directive|define
name|S_C_1_FORCE_INT_RESET
value|0x80
end_define

begin_comment
comment|/* R W  Control		Force internal reset				*/
end_comment

begin_define
define|#
directive|define
name|SYSTEM_CONFIGURATION_2
value|0x8389
end_define

begin_comment
comment|/* R W  Control								*/
end_comment

begin_define
define|#
directive|define
name|S_C_2_PCM_OVERSAMPLING
value|0x03
end_define

begin_comment
comment|/* R W  PCM		00=0x, 01=2x, 10=4x, 11=reserved		*/
end_comment

begin_define
define|#
directive|define
name|S_C_2_PCM_16_BIT
value|0x04
end_define

begin_comment
comment|/* R W	PCM		1=16-bit, 0=8-bit samples			*/
end_comment

begin_define
define|#
directive|define
name|SYSTEM_CONFIGURATION_3
value|0x838A
end_define

begin_comment
comment|/* R W	Control								*/
end_comment

begin_define
define|#
directive|define
name|S_C_3_PCM_CLOCK_SELECT
value|0x02
end_define

begin_comment
comment|/* R W	PCM		1=use 1.008Mhz clock for PCM, 0=don't		*/
end_comment

begin_define
define|#
directive|define
name|SYSTEM_CONFIGURATION_4
value|0x838B
end_define

begin_comment
comment|/* R W  Control		CD-ROM interface controls			*/
end_comment

begin_define
define|#
directive|define
name|IO_CONFIGURATION_1
value|0xF388
end_define

begin_comment
comment|/* R W	Control								*/
end_comment

begin_define
define|#
directive|define
name|I_C_1_BOOT_RESET_ENABLE
value|0x80
end_define

begin_comment
comment|/* R W  Control		1=reset board on warm boot, 0=don't		*/
end_comment

begin_define
define|#
directive|define
name|I_C_1_JOYSTICK_ENABLE
value|0x40
end_define

begin_comment
comment|/* R W  Control		1=enable joystick port, 0=don't		        */
end_comment

begin_define
define|#
directive|define
name|IO_CONFIGURATION_2
value|0xF389
end_define

begin_comment
comment|/* R W  Control								*/
end_comment

begin_define
define|#
directive|define
name|I_C_2_PCM_DMA_DISABLED
value|0x00
end_define

begin_comment
comment|/* R W  PCM		PCM DMA disabled				*/
end_comment

begin_define
define|#
directive|define
name|IO_CONFIGURATION_3
value|0xF38A
end_define

begin_comment
comment|/* R W	Control								*/
end_comment

begin_define
define|#
directive|define
name|I_C_3_PCM_IRQ_DISABLED
value|0x00
end_define

begin_comment
comment|/* R W  PCM		PCM IRQ disabled				*/
end_comment

begin_define
define|#
directive|define
name|COMPATIBILITY_ENABLE
value|0xF788
end_define

begin_comment
comment|/* R W  Control								*/
end_comment

begin_define
define|#
directive|define
name|C_E_MPU401_ENABLE
value|0x01
end_define

begin_comment
comment|/* R W	MIDI		1=enable, 0=disable MPU401 MIDI emulation	*/
end_comment

begin_define
define|#
directive|define
name|C_E_SB_ENABLE
value|0x02
end_define

begin_comment
comment|/* R W  PCM		1=enable, 0=disable Sound Blaster emulation	*/
end_comment

begin_define
define|#
directive|define
name|C_E_SB_ACTIVE
value|0x04
end_define

begin_comment
comment|/* R    PCM		"Sound Blaster Interrupt active"		*/
end_comment

begin_define
define|#
directive|define
name|C_E_MPU401_ACTIVE
value|0x08
end_define

begin_comment
comment|/* R	MIDI		"MPU UART mode active"				*/
end_comment

begin_define
define|#
directive|define
name|C_E_PCM_COMPRESSION
value|0x10
end_define

begin_comment
comment|/* R W  PCM		1=enable, 0=disabled compression		*/
end_comment

begin_define
define|#
directive|define
name|EMULATION_ADDRESS
value|0xF789
end_define

begin_comment
comment|/* R W  Control								*/
end_comment

begin_define
define|#
directive|define
name|E_A_SB_BASE
value|0x0f
end_define

begin_comment
comment|/* R W  PCM		bits A4-A7 for SB base port			*/
end_comment

begin_define
define|#
directive|define
name|E_A_MPU401_BASE
value|0xf0
end_define

begin_comment
comment|/* R W	MIDI		bits A4-A7 for MPU401 base port 		*/
end_comment

begin_define
define|#
directive|define
name|EMULATION_CONFIGURATION
value|0xFB8A
end_define

begin_comment
comment|/* R W			***** Only valid on newer PAS2 cards (?) *****	*/
end_comment

begin_define
define|#
directive|define
name|E_C_MPU401_IRQ
value|0x07
end_define

begin_comment
comment|/* R W	MIDI		MPU401 emulation IRQ				*/
end_comment

begin_define
define|#
directive|define
name|E_C_SB_IRQ
value|0x38
end_define

begin_comment
comment|/* R W  PCM		SB emulation IRQ				*/
end_comment

begin_define
define|#
directive|define
name|E_C_SB_DMA
value|0xC0
end_define

begin_comment
comment|/* R W	PCM		SB emulation DMA				*/
end_comment

begin_define
define|#
directive|define
name|OPERATION_MODE_1
value|0xEF8B
end_define

begin_comment
comment|/* R	Control								*/
end_comment

begin_define
define|#
directive|define
name|O_M_1_CDROM_TYPE
value|0x03
end_define

begin_comment
comment|/* R	CD-ROM		3=SCSI, 2=Sony, 0=no CD-ROM interface		*/
end_comment

begin_define
define|#
directive|define
name|O_M_1_FM_TYPE
value|0x04
end_define

begin_comment
comment|/* R	FM		1=sterero, 0=mono FM chip			*/
end_comment

begin_define
define|#
directive|define
name|O_M_1_PCM_TYPE
value|0x08
end_define

begin_comment
comment|/* R	PCM		1=16-bit Codec, 0=8-bit DAC			*/
end_comment

begin_define
define|#
directive|define
name|OPERATION_MODE_2
value|0xFF8B
end_define

begin_comment
comment|/* R	Control								*/
end_comment

begin_define
define|#
directive|define
name|O_M_2_PCS_ENABLED
value|0x02
end_define

begin_comment
comment|/* R	PC speaker	PC speaker emulation 1=enabled, 0=disabled	*/
end_comment

begin_define
define|#
directive|define
name|O_M_2_BUS_TIMING
value|0x10
end_define

begin_comment
comment|/* R	Control		1=AT bus timing, 0=XT bus timing		*/
end_comment

begin_define
define|#
directive|define
name|O_M_2_BOARD_REVISION
value|0xe0
end_define

begin_comment
comment|/* R	Control		Board revision					*/
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_MASK
value|0x0B8B
end_define

begin_comment
comment|/* R W	Control								*/
end_comment

begin_define
define|#
directive|define
name|I_M_FM_LEFT_IRQ_ENABLE
value|0x01
end_define

begin_comment
comment|/* R W	FM		Enable FM left interrupt			*/
end_comment

begin_define
define|#
directive|define
name|I_M_FM_RIGHT_IRQ_ENABLE
value|0x02
end_define

begin_comment
comment|/* R W	FM		Enable FM right interrupt			*/
end_comment

begin_define
define|#
directive|define
name|I_M_PCM_RATE_IRQ_ENABLE
value|0x04
end_define

begin_comment
comment|/* R W	PCM		Enable Sample Rate interrupt			*/
end_comment

begin_define
define|#
directive|define
name|I_M_PCM_BUFFER_IRQ_ENABLE
value|0x08
end_define

begin_comment
comment|/* R W	PCM		Enable Sample Buffer interrupt			*/
end_comment

begin_define
define|#
directive|define
name|I_M_MIDI_IRQ_ENABLE
value|0x10
end_define

begin_comment
comment|/* R W	MIDI		Enable MIDI interrupt				*/
end_comment

begin_define
define|#
directive|define
name|I_M_BOARD_REV
value|0xE0
end_define

begin_comment
comment|/* R	Control		Board revision					*/
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_STATUS
value|0x0B89
end_define

begin_comment
comment|/* R W	Control								*/
end_comment

begin_define
define|#
directive|define
name|I_S_FM_LEFT_IRQ
value|0x01
end_define

begin_comment
comment|/* R W	FM		Left FM Interrupt Pending			*/
end_comment

begin_define
define|#
directive|define
name|I_S_FM_RIGHT_IRQ
value|0x02
end_define

begin_comment
comment|/* R W	FM		Right FM Interrupt Pending			*/
end_comment

begin_define
define|#
directive|define
name|I_S_PCM_SAMPLE_RATE_IRQ
value|0x04
end_define

begin_comment
comment|/* R W	PCM		Sample Rate Interrupt Pending			*/
end_comment

begin_define
define|#
directive|define
name|I_S_PCM_SAMPLE_BUFFER_IRQ
value|0x08
end_define

begin_comment
comment|/* R W	PCM		Sample Buffer Interrupt Pending			*/
end_comment

begin_define
define|#
directive|define
name|I_S_MIDI_IRQ
value|0x10
end_define

begin_comment
comment|/* R W	MIDI		MIDI Interrupt Pending				*/
end_comment

begin_define
define|#
directive|define
name|I_S_PCM_CHANNEL
value|0x20
end_define

begin_comment
comment|/* R W	PCM		1=right, 0=left					*/
end_comment

begin_define
define|#
directive|define
name|I_S_RESET_ACTIVE
value|0x40
end_define

begin_comment
comment|/* R W	Control		Reset is active (Timed pulse not finished)	*/
end_comment

begin_define
define|#
directive|define
name|I_S_PCM_CLIPPING
value|0x80
end_define

begin_comment
comment|/* R W	PCM		Clipping has occurred				*/
end_comment

begin_define
define|#
directive|define
name|FILTER_FREQUENCY
value|0x0B8A
end_define

begin_comment
comment|/* R W	Control								*/
end_comment

begin_define
define|#
directive|define
name|F_F_FILTER_DISABLED
value|0x00
end_define

begin_comment
comment|/* R W 	Mixer		No filter					*/
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|struct {
comment|/* R W	Mixer		Filter translation				*/
end_comment

begin_comment
unit|unsigned int freq:24; 		unsigned int value:8; 	} F_F_FILTER_translate[] =  	{ { 73500, 0x01 },
comment|/* 73500Hz - divide by  16 */
end_comment

begin_comment
unit|{ 65333, 0x02 },
comment|/* 65333Hz - divide by  18 */
end_comment

begin_comment
unit|{ 49000, 0x09 },
comment|/* 49000Hz - divide by  24 */
end_comment

begin_comment
unit|{ 36750, 0x11 },
comment|/* 36750Hz - divide by  32 */
end_comment

begin_comment
unit|{ 24500, 0x19 },
comment|/* 24500Hz - divide by  48 */
end_comment

begin_comment
unit|{ 18375, 0x07 },
comment|/* 18375Hz - divide by  64 */
end_comment

begin_comment
unit|{ 12783, 0x0f },
comment|/* 12783Hz - divide by  92 */
end_comment

begin_comment
unit|{ 12250, 0x04 },
comment|/* 12250Hz - divide by  96 */
end_comment

begin_comment
unit|{  9188, 0x17 },
comment|/*  9188Hz - divide by 128 */
end_comment

begin_comment
unit|{  6125, 0x1f },
comment|/*  6125Hz - divide by 192 */
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|F_F_MIXER_UNMUTE
value|0x20
end_define

begin_comment
comment|/* R W	Mixer		1=disable, 0=enable board mute			*/
end_comment

begin_define
define|#
directive|define
name|F_F_PCM_RATE_COUNTER
value|0x40
end_define

begin_comment
comment|/* R W	PCM		1=enable, 0=disable sample rate counter		*/
end_comment

begin_define
define|#
directive|define
name|F_F_PCM_BUFFER_COUNTER
value|0x80
end_define

begin_comment
comment|/* R W 	PCM		1=enable, 0=disable sample buffer counter	*/
end_comment

begin_define
define|#
directive|define
name|PAS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|PAS_PLUS
value|1
end_define

begin_define
define|#
directive|define
name|PAS_CDPC
value|2
end_define

begin_define
define|#
directive|define
name|PAS_16
value|3
end_define

begin_define
define|#
directive|define
name|PAS_16D
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_TRANSLATIONS
end_ifdef

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|I_C_2_PCM_DMA_translate
index|[]
init|=
comment|/* R W  PCM		PCM DMA channel value translations		*/
block|{
literal|4
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|0
block|,
literal|5
block|,
literal|6
block|,
literal|7
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|I_C_3_PCM_IRQ_translate
index|[]
init|=
comment|/* R W	PCM		PCM IRQ level value translation			*/
block|{
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|,
literal|6
block|,
literal|0
block|,
literal|1
block|,
literal|7
block|,
literal|8
block|,
literal|9
block|,
literal|0
block|,
literal|10
block|,
literal|11
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|unused
end_ifdef

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|E_C_MPU401_IRQ_translate
index|[]
init|=
comment|/* R W	MIDI		MPU401 emulation IRQ value translation		*/
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x02
block|,
literal|0x00
block|,
literal|0x03
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x01
block|,
literal|0x05
block|,
literal|0x06
block|,
literal|0x07
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|E_C_SB_IRQ_translate
index|[]
init|=
comment|/* R W	PCM		SB emulation IRQ translate			*/
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x00
block|,
literal|0x20
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x28
block|,
literal|0x30
block|,
literal|0x38
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|E_C_SB_DMA_translate
index|[]
init|=
comment|/* R W	PCM		SB emulation DMA translate			*/
block|{
literal|0x00
block|,
literal|0x40
block|,
literal|0x80
block|,
literal|0xC0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|unused
end_ifdef

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|O_M_1_to_card
index|[]
init|=
comment|/* R W	Control		Translate (OM1& 0x0f) to card type		*/
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|4
block|,
literal|0
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PARALLEL_MIXER
value|0x078B
end_define

begin_comment
comment|/*   W	Mixer		Documented for MVD101 as FM Mono Right decode?? */
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_ADDRESS
value|0x80
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Address/mixer select			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|P_M_MV508_LEFT
value|0x20
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Left channel select			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_RIGHT
value|0x40
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Right channel select			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_BOTH
value|0x00
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Both channel select			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_MIXER
value|0x10
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Select a mixer (rather than a volume) 	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_VOLUME
value|0x00
end_define

begin_define
define|#
directive|define
name|P_M_MV508_INPUTMIX
value|0x20
end_define

begin_comment
comment|/*   W  Mixer		MVD508	Select mixer A				*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_OUTPUTMIX
value|0x00
end_define

begin_comment
comment|/*   W  Mixer		MVD508	Select mixer B				*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_MASTER_A
value|0x01
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Master volume control A (output)	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_MASTER_B
value|0x02
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Master volume control B (DSP input)	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_BASS
value|0x03
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Bass control				*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_TREBLE
value|0x04
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Treble control				*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_MODE
value|0x05
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Master mode control			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_LOUDNESS
value|0x04
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Mode control - Loudness filter 		*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_ENHANCE_BITS
value|0x03
end_define

begin_define
define|#
directive|define
name|P_M_MV508_ENHANCE_NONE
value|0x00
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Mode control - No stereo enhancement	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_ENHANCE_40
value|0x01
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Mode control - 40% stereo enhancement	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_ENHANCE_60
value|0x02
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Mode control - 60% stereo enhancement	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_ENHANCE_80
value|0x03
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Mode control - 80% stereo enhancement	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_FM
value|0x00
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 0 - FM				*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_IMIXER
value|0x01
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 1 - Input mixer (rec monitor)	*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_LINE
value|0x02
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 2 - Line in			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_CDROM
value|0x03
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 3 - CD-ROM			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_MIC
value|0x04
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 4 - Microphone			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_PCM
value|0x05
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 5 - PCM				*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_SPEAKER
value|0x06
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 6 - PC Speaker			*/
end_comment

begin_define
define|#
directive|define
name|P_M_MV508_SB
value|0x07
end_define

begin_comment
comment|/*   W	Mixer		MVD508	Channel 7 - SB DSP			*/
end_comment

begin_define
define|#
directive|define
name|SERIAL_MIXER
value|0xB88
end_define

begin_comment
comment|/* R W	Control		Serial mixer control (used other ways)		*/
end_comment

begin_define
define|#
directive|define
name|S_M_PCM_RESET
value|0x01
end_define

begin_comment
comment|/* R W	PCM		Codec/DSP reset					*/
end_comment

begin_define
define|#
directive|define
name|S_M_FM_RESET
value|0x02
end_define

begin_comment
comment|/* R W	FM		FM chip reset					*/
end_comment

begin_define
define|#
directive|define
name|S_M_SB_RESET
value|0x04
end_define

begin_comment
comment|/* R W	PCM		SB emulation chip reset				*/
end_comment

begin_define
define|#
directive|define
name|S_M_MIXER_RESET
value|0x10
end_define

begin_comment
comment|/* R W	Mixer		Mixer chip reset				*/
end_comment

begin_define
define|#
directive|define
name|S_M_INTEGRATOR_ENABLE
value|0x40
end_define

begin_comment
comment|/* R W	Speaker		Enable PC speaker integrator (FORCE RealSound)	*/
end_comment

begin_define
define|#
directive|define
name|S_M_OPL3_DUAL_MONO
value|0x80
end_define

begin_comment
comment|/* R W  FM		Set the OPL-3 to dual mono mode			*/
end_comment

begin_define
define|#
directive|define
name|PCM_CONTROL
value|0xF8A
end_define

begin_comment
comment|/* R W	PCM		PCM Control Register				*/
end_comment

begin_define
define|#
directive|define
name|P_C_MIXER_CROSS_FIELD
value|0x0f
end_define

begin_define
define|#
directive|define
name|P_C_MIXER_CROSS_R_TO_R
value|0x01
end_define

begin_comment
comment|/* R W	Mixer		Connect Right to Right				*/
end_comment

begin_define
define|#
directive|define
name|P_C_MIXER_CROSS_L_TO_R
value|0x02
end_define

begin_comment
comment|/* R W	Mixer		Connect Left  to Right				*/
end_comment

begin_define
define|#
directive|define
name|P_C_MIXER_CROSS_R_TO_L
value|0x04
end_define

begin_comment
comment|/* R W	Mixer		Connect Right to Left				*/
end_comment

begin_define
define|#
directive|define
name|P_C_MIXER_CROSS_L_TO_L
value|0x08
end_define

begin_comment
comment|/* R W	Mixer		Connect Left  to Left				*/
end_comment

begin_define
define|#
directive|define
name|P_C_PCM_DAC_MODE
value|0x10
end_define

begin_comment
comment|/* R W	PCM		Playback (DAC) mode				*/
end_comment

begin_define
define|#
directive|define
name|P_C_PCM_ADC_MODE
value|0x00
end_define

begin_comment
comment|/* R W	PCM		Record (ADC) mode				*/
end_comment

begin_define
define|#
directive|define
name|P_C_PCM_MONO
value|0x20
end_define

begin_comment
comment|/* R W	PCM		Mono mode					*/
end_comment

begin_define
define|#
directive|define
name|P_C_PCM_STEREO
value|0x00
end_define

begin_comment
comment|/* R W	PCM		Stereo mode					*/
end_comment

begin_define
define|#
directive|define
name|P_C_PCM_ENABLE
value|0x40
end_define

begin_comment
comment|/* R W	PCM		Enable PCM engine				*/
end_comment

begin_define
define|#
directive|define
name|P_C_PCM_DMA_ENABLE
value|0x80
end_define

begin_comment
comment|/* R W	PCM		Enable DRQ					*/
end_comment

begin_define
define|#
directive|define
name|SAMPLE_COUNTER_CONTROL
value|0x138B
end_define

begin_comment
comment|/* R W	PCM		Sample counter control register			*/
end_comment

begin_define
define|#
directive|define
name|S_C_C_SQUARE_WAVE
value|0x04
end_define

begin_comment
comment|/* R W	PCM		Square wave generator (use for sample rate)	*/
end_comment

begin_define
define|#
directive|define
name|S_C_C_RATE
value|0x06
end_define

begin_comment
comment|/* R W	PCM		Rate generator (use for sample buffer count)	*/
end_comment

begin_define
define|#
directive|define
name|S_C_C_LSB_THEN_MSB
value|0x30
end_define

begin_comment
comment|/* R W	PCM		Change all 16 bits, LSB first, then MSB		*/
end_comment

begin_comment
comment|/* MVD101 and SDK documentations have S_C_C_SAMPLE_RATE and S_C_C_SAMPLE_BUFFER transposed. Only one works :-) */
end_comment

begin_define
define|#
directive|define
name|S_C_C_SAMPLE_RATE
value|0x00
end_define

begin_comment
comment|/* R W	PCM		Select sample rate timer			*/
end_comment

begin_define
define|#
directive|define
name|S_C_C_SAMPLE_BUFFER
value|0x40
end_define

begin_comment
comment|/* R W	PCM		Select sample buffer counter			*/
end_comment

begin_define
define|#
directive|define
name|S_C_C_PC_SPEAKER
value|0x80
end_define

begin_comment
comment|/* R W	PCM		Select PC speaker counter			*/
end_comment

begin_define
define|#
directive|define
name|SAMPLE_RATE_TIMER
value|0x1388
end_define

begin_comment
comment|/*   W	PCM		Sample rate timer register (PCM wait interval)	*/
end_comment

begin_define
define|#
directive|define
name|SAMPLE_BUFFER_COUNTER
value|0x1389
end_define

begin_comment
comment|/* R W	PCM		Sample buffer counter (DMA buffer size)		*/
end_comment

begin_define
define|#
directive|define
name|MIDI_CONTROL
value|0x178b
end_define

begin_comment
comment|/* R W  MIDI		Midi control register				*/
end_comment

begin_define
define|#
directive|define
name|M_C_ENA_TSTAMP_IRQ
value|0x01
end_define

begin_comment
comment|/* R W	MIDI		Enable Time Stamp Interrupts			*/
end_comment

begin_define
define|#
directive|define
name|M_C_ENA_TME_COMP_IRQ
value|0x02
end_define

begin_comment
comment|/* R W  MIDI		Enable time compare interrupts			*/
end_comment

begin_define
define|#
directive|define
name|M_C_ENA_INPUT_IRQ
value|0x04
end_define

begin_comment
comment|/* R W  MIDI		Enable input FIFO interrupts			*/
end_comment

begin_define
define|#
directive|define
name|M_C_ENA_OUTPUT_IRQ
value|0x08
end_define

begin_comment
comment|/* R W  MIDI		Enable output FIFO interrupts			*/
end_comment

begin_define
define|#
directive|define
name|M_C_ENA_OUTPUT_HALF_IRQ
value|0x10
end_define

begin_comment
comment|/* R W  MIDI		Enable output FIFO half full interrupts		*/
end_comment

begin_define
define|#
directive|define
name|M_C_RESET_INPUT_FIFO
value|0x20
end_define

begin_comment
comment|/* R W  MIDI		Reset input FIFO pointer			*/
end_comment

begin_define
define|#
directive|define
name|M_C_RESET_OUTPUT_FIFO
value|0x40
end_define

begin_comment
comment|/* R W  MIDI		Reset output FIFO pointer			*/
end_comment

begin_define
define|#
directive|define
name|M_C_ENA_THRU_MODE
value|0x80
end_define

begin_comment
comment|/* R W  MIDI		Echo input to output (THRU)			*/
end_comment

begin_define
define|#
directive|define
name|MIDI_STATUS
value|0x1B88
end_define

begin_comment
comment|/* R W  MIDI		Midi (interrupt) status register		*/
end_comment

begin_define
define|#
directive|define
name|M_S_TIMESTAMP
value|0x01
end_define

begin_comment
comment|/* R W  MIDI		Midi time stamp interrupt occurred		*/
end_comment

begin_define
define|#
directive|define
name|M_S_COMPARE
value|0x02
end_define

begin_comment
comment|/* R W  MIDI		Midi compare time interrupt occurred		*/
end_comment

begin_define
define|#
directive|define
name|M_S_INPUT_AVAIL
value|0x04
end_define

begin_comment
comment|/* R W  MIDI		Midi input data available interrupt occurred	*/
end_comment

begin_define
define|#
directive|define
name|M_S_OUTPUT_EMPTY
value|0x08
end_define

begin_comment
comment|/* R W  MIDI		Midi output FIFO empty interrupt occurred	*/
end_comment

begin_define
define|#
directive|define
name|M_S_OUTPUT_HALF_EMPTY
value|0x10
end_define

begin_comment
comment|/* R W  MIDI		Midi output FIFO half empty interrupt occurred	*/
end_comment

begin_define
define|#
directive|define
name|M_S_INPUT_OVERRUN
value|0x20
end_define

begin_comment
comment|/* R W  MIDI		Midi input overrun error occurred		*/
end_comment

begin_define
define|#
directive|define
name|M_S_OUTPUT_OVERRUN
value|0x40
end_define

begin_comment
comment|/* R W  MIDI 		Midi output overrun error occurred		*/
end_comment

begin_define
define|#
directive|define
name|M_S_FRAMING_ERROR
value|0x80
end_define

begin_comment
comment|/* R W  MIDI		Midi input framing error occurred		*/
end_comment

begin_define
define|#
directive|define
name|MIDI_FIFO_STATUS
value|0x1B89
end_define

begin_comment
comment|/* R W  MIDI		Midi fifo status				*/
end_comment

begin_define
define|#
directive|define
name|MIDI_DATA
value|0x178A
end_define

begin_comment
comment|/* R W  MIDI		Midi data register				*/
end_comment

begin_define
define|#
directive|define
name|MIDI_INPUT_AVAILABLE
value|0x0f
end_define

begin_comment
comment|/* RW   MIDI */
end_comment

end_unit

