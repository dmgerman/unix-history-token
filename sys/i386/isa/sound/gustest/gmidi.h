begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id$  */
end_comment

begin_decl_stmt
name|char
name|patch_names
index|[]
index|[
literal|9
index|]
init|=
block|{
comment|/*   0 */
literal|"acpiano"
block|,
comment|/*   1 */
literal|"britepno"
block|,
comment|/*   2 */
literal|"synpiano"
block|,
comment|/*   3 */
literal|"honktonk"
block|,
comment|/*   4 */
literal|"epiano1"
block|,
comment|/*   5 */
literal|"epiano2"
block|,
comment|/*   6 */
literal|"hrpschrd"
block|,
comment|/*   7 */
literal|"clavinet"
block|,
comment|/*   8 */
literal|"celeste"
block|,
comment|/*   9 */
literal|"glocken"
block|,
comment|/*  10 */
literal|"musicbox"
block|,
comment|/*  11 */
literal|"vibes"
block|,
comment|/*  12 */
literal|"marimba"
block|,
comment|/*  13 */
literal|"xylophon"
block|,
comment|/*  14 */
literal|"tubebell"
block|,
comment|/*  15 */
literal|"santur"
block|,
comment|/*  16 */
literal|"homeorg"
block|,
comment|/*  17 */
literal|"percorg"
block|,
comment|/*  18 */
literal|"rockorg"
block|,
comment|/*  19 */
literal|"church"
block|,
comment|/*  20 */
literal|"reedorg"
block|,
comment|/*  21 */
literal|"accordn"
block|,
comment|/*  22 */
literal|"harmonca"
block|,
comment|/*  23 */
literal|"concrtna"
block|,
comment|/*  24 */
literal|"nyguitar"
block|,
comment|/*  25 */
literal|"acguitar"
block|,
comment|/*  26 */
literal|"jazzgtr"
block|,
comment|/*  27 */
literal|"cleangtr"
block|,
comment|/*  28 */
literal|"mutegtr"
block|,
comment|/*  29 */
literal|"odguitar"
block|,
comment|/*  30 */
literal|"distgtr"
block|,
comment|/*  31 */
literal|"gtrharm"
block|,
comment|/*  32 */
literal|"acbass"
block|,
comment|/*  33 */
literal|"fngrbass"
block|,
comment|/*  34 */
literal|"pickbass"
block|,
comment|/*  35 */
literal|"fretless"
block|,
comment|/*  36 */
literal|"slapbas1"
block|,
comment|/*  37 */
literal|"slapbas2"
block|,
comment|/*  38 */
literal|"synbass1"
block|,
comment|/*  39 */
literal|"synbass2"
block|,
comment|/*  40 */
literal|"violin"
block|,
comment|/*  41 */
literal|"viola"
block|,
comment|/*  42 */
literal|"cello"
block|,
comment|/*  43 */
literal|"contraba"
block|,
comment|/*  44 */
literal|"marcato"
block|,
comment|/*  45 */
literal|"pizzcato"
block|,
comment|/*  46 */
literal|"harp"
block|,
comment|/*  47 */
literal|"timpani"
block|,
comment|/*  48 */
literal|"marcato"
block|,
comment|/*  49 */
literal|"slowstr"
block|,
comment|/*  50 */
literal|"synstr1"
block|,
comment|/*  51 */
literal|"synstr2"
block|,
comment|/*  52 */
literal|"choir"
block|,
comment|/*  53 */
literal|"doo"
block|,
comment|/*  54 */
literal|"voices"
block|,
comment|/*  55 */
literal|"orchhit"
block|,
comment|/*  56 */
literal|"trumpet"
block|,
comment|/*  57 */
literal|"trombone"
block|,
comment|/*  58 */
literal|"tuba"
block|,
comment|/*  59 */
literal|"mutetrum"
block|,
comment|/*  60 */
literal|"frenchrn"
block|,
comment|/*  61 */
literal|"hitbrass"
block|,
comment|/*  62 */
literal|"synbras1"
block|,
comment|/*  63 */
literal|"synbras2"
block|,
comment|/*  64 */
literal|"sprnosax"
block|,
comment|/*  65 */
literal|"altosax"
block|,
comment|/*  66 */
literal|"tenorsax"
block|,
comment|/*  67 */
literal|"barisax"
block|,
comment|/*  68 */
literal|"oboe"
block|,
comment|/*  69 */
literal|"englhorn"
block|,
comment|/*  70 */
literal|"bassoon"
block|,
comment|/*  71 */
literal|"clarinet"
block|,
comment|/*  72 */
literal|"piccolo"
block|,
comment|/*  73 */
literal|"flute"
block|,
comment|/*  74 */
literal|"recorder"
block|,
comment|/*  75 */
literal|"woodflut"
block|,
comment|/*  76 */
literal|"bottle"
block|,
comment|/*  77 */
literal|"shakazul"
block|,
comment|/*  78 */
literal|"whistle"
block|,
comment|/*  79 */
literal|"ocarina"
block|,
comment|/*  80 */
literal|"sqrwave"
block|,
comment|/*  81 */
literal|"sawwave"
block|,
comment|/*  82 */
literal|"calliope"
block|,
comment|/*  83 */
literal|"chiflead"
block|,
comment|/*  84 */
literal|"voxlead"
block|,
comment|/*  85 */
literal|"voxlead"
block|,
comment|/*  86 */
literal|"lead5th"
block|,
comment|/*  87 */
literal|"basslead"
block|,
comment|/*  88 */
literal|"fantasia"
block|,
comment|/*  89 */
literal|"warmpad"
block|,
comment|/*  90 */
literal|"polysyn"
block|,
comment|/*  91 */
literal|"ghostie"
block|,
comment|/*  92 */
literal|"bowglass"
block|,
comment|/*  93 */
literal|"metalpad"
block|,
comment|/*  94 */
literal|"halopad"
block|,
comment|/*  95 */
literal|"sweeper"
block|,
comment|/*  96 */
literal|"aurora"
block|,
comment|/*  97 */
literal|"soundtrk"
block|,
comment|/*  98 */
literal|"crystal"
block|,
comment|/*  99 */
literal|"atmosphr"
block|,
comment|/* 100 */
literal|"freshair"
block|,
comment|/* 101 */
literal|"unicorn"
block|,
comment|/* 102 */
literal|"sweeper"
block|,
comment|/* 103 */
literal|"startrak"
block|,
comment|/* 104 */
literal|"sitar"
block|,
comment|/* 105 */
literal|"banjo"
block|,
comment|/* 106 */
literal|"shamisen"
block|,
comment|/* 107 */
literal|"koto"
block|,
comment|/* 108 */
literal|"kalimba"
block|,
comment|/* 109 */
literal|"bagpipes"
block|,
comment|/* 110 */
literal|"fiddle"
block|,
comment|/* 111 */
literal|"Shannai"
block|,
comment|/* 112 */
literal|"carillon"
block|,
comment|/* 113 */
literal|"agogo"
block|,
comment|/* 114 */
literal|"steeldrm"
block|,
comment|/* 115 */
literal|"woodblk"
block|,
comment|/* 116 */
literal|"taiko"
block|,
comment|/* 117 */
literal|"toms"
block|,
comment|/* 118 */
literal|"syntom"
block|,
comment|/* 119 */
literal|"revcym"
block|,
comment|/* 120 */
literal|"fx-fret"
block|,
comment|/* 121 */
literal|"fx-blow"
block|,
comment|/* 122 */
literal|"seashore"
block|,
comment|/* 123 */
literal|"jungle"
block|,
comment|/* 124 */
literal|"telephon"
block|,
comment|/* 125 */
literal|"helicptr"
block|,
comment|/* 126 */
literal|"applause"
block|,
comment|/* 127 */
literal|"ringwhsl"
block|}
decl_stmt|;
end_decl_stmt

end_unit

