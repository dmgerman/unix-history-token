begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)kbd.c	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * kbd.c -- key-code decoding routine  *   by A.Fujita, Dec-12-1992  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<luna68k/stand/kbdreg.h>
end_include

begin_decl_stmt
name|struct
name|kbd_keymap
name|kbd_keymap
index|[]
init|=
block|{
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   0 [0x00]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   1 [0x01]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   2 [0x02]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   3 [0x03]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   4 [0x04]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   5 [0x05]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   6 [0x06]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   7 [0x07]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*   8 [0x08]	      */
name|KC_CODE
block|,
literal|0x09
block|,
literal|0x09
block|,
comment|/*   9 [0x09]	TAB   */
name|KC_SHIFT
block|,
name|KS_CTRL
block|,
name|KS_CTRL
block|,
comment|/*  10 [0x0A]	CTRL  */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  11 [0x0B]	      */
name|KC_SHIFT
block|,
name|KS_SHIFT
block|,
name|KS_SHIFT
block|,
comment|/*  12 [0x0C]	SHIFT */
name|KC_SHIFT
block|,
name|KS_SHIFT
block|,
name|KS_SHIFT
block|,
comment|/*  13 [0x0D]	SHIFT */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  14 [0x0E]	      */
name|KC_SHIFT
block|,
name|KS_META
block|,
name|KS_META
block|,
comment|/*  15 [0x0F]	META  */
name|KC_CODE
block|,
literal|0x1B
block|,
literal|0x1B
block|,
comment|/*  16 [0x10]	ESC   */
name|KC_CODE
block|,
literal|0x08
block|,
literal|0x08
block|,
comment|/*  17 [0x11]	BS    */
name|KC_CODE
block|,
literal|0x0D
block|,
literal|0x0D
block|,
comment|/*  18 [0x12]	CR    */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  19 [0x13]	      */
name|KC_CODE
block|,
literal|0x20
block|,
literal|0x20
block|,
comment|/*  20 [0x14]	SP    */
name|KC_CODE
block|,
literal|0x7F
block|,
literal|0x7F
block|,
comment|/*  21 [0x15]	DEL   */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  22 [0x16]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  23 [0x17]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  24 [0x18]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  25 [0x19]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  26 [0x1A]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  27 [0x1B]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  28 [0x1C]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  29 [0x1D]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  30 [0x1E]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  31 [0x1F]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  32 [0x20]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  33 [0x21]	      */
name|KC_CODE
block|,
literal|0x31
block|,
literal|0x21
block|,
comment|/*  34 [0x22]	 1    */
name|KC_CODE
block|,
literal|0x32
block|,
literal|0x22
block|,
comment|/*  35 [0x23]	 2    */
name|KC_CODE
block|,
literal|0x33
block|,
literal|0x23
block|,
comment|/*  36 [0x24]	 3    */
name|KC_CODE
block|,
literal|0x34
block|,
literal|0x24
block|,
comment|/*  37 [0x25]	 4    */
name|KC_CODE
block|,
literal|0x35
block|,
literal|0x25
block|,
comment|/*  38 [0x26]	 5    */
name|KC_CODE
block|,
literal|0x36
block|,
literal|0x26
block|,
comment|/*  39 [0x27]	 6    */
name|KC_CODE
block|,
literal|0x37
block|,
literal|0x27
block|,
comment|/*  40 [0x28]	 7    */
name|KC_CODE
block|,
literal|0x38
block|,
literal|0x28
block|,
comment|/*  41 [0x29]	 8    */
name|KC_CODE
block|,
literal|0x39
block|,
literal|0x29
block|,
comment|/*  42 [0x2A]	 9    */
name|KC_CODE
block|,
literal|0x30
block|,
literal|0x30
block|,
comment|/*  43 [0x2B]	 0    */
name|KC_CODE
block|,
literal|0x2D
block|,
literal|0x3D
block|,
comment|/*  44 [0x2C]	 -    */
name|KC_CODE
block|,
literal|0x5E
block|,
literal|0x7E
block|,
comment|/*  45 [0x2D]	 ^    */
name|KC_CODE
block|,
literal|0x5C
block|,
literal|0x7C
block|,
comment|/*  46 [0x2E]	 \    */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  47 [0x2F]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  48 [0x30]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  49 [0x31]	      */
name|KC_CODE
block|,
literal|0x71
block|,
literal|0x51
block|,
comment|/*  50 [0x32]	 q    */
name|KC_CODE
block|,
literal|0x77
block|,
literal|0x57
block|,
comment|/*  51 [0x33]	 w    */
name|KC_CODE
block|,
literal|0x65
block|,
literal|0x45
block|,
comment|/*  52 [0x34]	 e    */
name|KC_CODE
block|,
literal|0x72
block|,
literal|0x52
block|,
comment|/*  53 [0x35]	 r    */
name|KC_CODE
block|,
literal|0x74
block|,
literal|0x54
block|,
comment|/*  54 [0x36]	 t    */
name|KC_CODE
block|,
literal|0x79
block|,
literal|0x59
block|,
comment|/*  55 [0x37]	 y    */
name|KC_CODE
block|,
literal|0x75
block|,
literal|0x55
block|,
comment|/*  56 [0x38]	 u    */
name|KC_CODE
block|,
literal|0x69
block|,
literal|0x49
block|,
comment|/*  57 [0x39]	 i    */
name|KC_CODE
block|,
literal|0x6F
block|,
literal|0x4F
block|,
comment|/*  58 [0x3A]	 o    */
name|KC_CODE
block|,
literal|0x70
block|,
literal|0x50
block|,
comment|/*  59 [0x3B]	 p    */
name|KC_CODE
block|,
literal|0x40
block|,
literal|0x60
block|,
comment|/*  60 [0x3C]	 @    */
name|KC_CODE
block|,
literal|0x5B
block|,
literal|0x7B
block|,
comment|/*  61 [0x3D]	 [    */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  62 [0x3E]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  63 [0x3F]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  64 [0x40]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  65 [0x41]	      */
name|KC_CODE
block|,
literal|0x61
block|,
literal|0x41
block|,
comment|/*  66 [0x42]	 a    */
name|KC_CODE
block|,
literal|0x73
block|,
literal|0x53
block|,
comment|/*  67 [0x43]	 s    */
name|KC_CODE
block|,
literal|0x64
block|,
literal|0x44
block|,
comment|/*  68 [0x44]	 d    */
name|KC_CODE
block|,
literal|0x66
block|,
literal|0x46
block|,
comment|/*  69 [0x45]	 f    */
name|KC_CODE
block|,
literal|0x67
block|,
literal|0x47
block|,
comment|/*  70 [0x46]	 g    */
name|KC_CODE
block|,
literal|0x68
block|,
literal|0x48
block|,
comment|/*  71 [0x47]	 h    */
name|KC_CODE
block|,
literal|0x6A
block|,
literal|0x4A
block|,
comment|/*  72 [0x48]	 j    */
name|KC_CODE
block|,
literal|0x6B
block|,
literal|0x4B
block|,
comment|/*  73 [0x49]	 k    */
name|KC_CODE
block|,
literal|0x6C
block|,
literal|0x4C
block|,
comment|/*  74 [0x4A]	 l    */
name|KC_CODE
block|,
literal|0x3B
block|,
literal|0x2B
block|,
comment|/*  75 [0x4B]	 ;    */
name|KC_CODE
block|,
literal|0x3A
block|,
literal|0x2A
block|,
comment|/*  76 [0x4C]	 :    */
name|KC_CODE
block|,
literal|0x5D
block|,
literal|0x7D
block|,
comment|/*  77 [0x4D]	 ]    */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  78 [0x4E]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  79 [0x4F]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  80 [0x50]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  81 [0x51]	      */
name|KC_CODE
block|,
literal|0x7A
block|,
literal|0x5A
block|,
comment|/*  82 [0x52]	 z    */
name|KC_CODE
block|,
literal|0x78
block|,
literal|0x58
block|,
comment|/*  83 [0x53]	 x    */
name|KC_CODE
block|,
literal|0x63
block|,
literal|0x43
block|,
comment|/*  84 [0x54]	 c    */
name|KC_CODE
block|,
literal|0x76
block|,
literal|0x56
block|,
comment|/*  85 [0x55]	 v    */
name|KC_CODE
block|,
literal|0x62
block|,
literal|0x42
block|,
comment|/*  86 [0x56]	 b    */
name|KC_CODE
block|,
literal|0x6E
block|,
literal|0x4E
block|,
comment|/*  87 [0x57]	 n    */
name|KC_CODE
block|,
literal|0x6D
block|,
literal|0x4D
block|,
comment|/*  88 [0x58]	 m    */
name|KC_CODE
block|,
literal|0x2C
block|,
literal|0x3C
block|,
comment|/*  89 [0x59]	 ,    */
name|KC_CODE
block|,
literal|0x2E
block|,
literal|0x3E
block|,
comment|/*  90 [0x5A]	 .    */
name|KC_CODE
block|,
literal|0x2F
block|,
literal|0x3F
block|,
comment|/*  91 [0x5B]	 /    */
name|KC_CODE
block|,
literal|0x5F
block|,
literal|0x5F
block|,
comment|/*  92 [0x5C]	 _    */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  93 [0x5D]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  94 [0x5E]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  95 [0x5F]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  96 [0x60]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  97 [0x61]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  98 [0x62]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/*  99 [0x63]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 100 [0x64]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 101 [0x65]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 102 [0x66]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 103 [0x67]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 104 [0x68]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 105 [0x69]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 106 [0x6A]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 107 [0x6B]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 108 [0x6C]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 109 [0x6D]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 110 [0x6E]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 111 [0x6F]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 112 [0x70]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 113 [0x71]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 114 [0x72]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 115 [0x73]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 116 [0x74]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 117 [0x75]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 118 [0x76]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 119 [0x77]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 120 [0x78]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 121 [0x79]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 122 [0x7A]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 123 [0x7B]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 124 [0x7C]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 125 [0x7D]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 126 [0x7E]	      */
name|KC_IGNORE
block|,
literal|0
block|,
literal|0
block|,
comment|/* 127 [0x7F]	      */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shift_flag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ctrl_flag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|meta_flag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|kbd_decode
argument_list|(
name|code
argument_list|)
specifier|register
name|u_char
name|code
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|unsigned
name|int
name|c
decl_stmt|,
name|updown
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|code
operator|&
literal|0x80
condition|)
name|updown
operator|=
literal|1
expr_stmt|;
name|code
operator|&=
literal|0x7F
expr_stmt|;
name|c
operator|=
name|kbd_keymap
index|[
name|code
index|]
operator|.
name|km_type
expr_stmt|;
if|if
condition|(
name|c
operator|==
name|KC_IGNORE
condition|)
return|return
operator|(
name|KC_IGNORE
operator|)
return|;
if|if
condition|(
operator|(
name|c
operator|==
name|KC_CODE
operator|)
operator|&&
name|updown
condition|)
return|return
operator|(
name|KC_IGNORE
operator|)
return|;
if|if
condition|(
name|c
operator|==
name|KC_SHIFT
condition|)
block|{
switch|switch
condition|(
name|kbd_keymap
index|[
name|code
index|]
operator|.
name|km_code
index|[
literal|0
index|]
condition|)
block|{
case|case
name|KS_SHIFT
case|:
name|shift_flag
operator|=
literal|1
operator|-
name|updown
expr_stmt|;
break|break;
case|case
name|KS_CTRL
case|:
name|ctrl_flag
operator|=
literal|1
operator|-
name|updown
expr_stmt|;
break|break;
case|case
name|KS_META
case|:
name|meta_flag
operator|=
literal|1
operator|-
name|updown
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|KC_IGNORE
operator|)
return|;
block|}
if|if
condition|(
name|shift_flag
condition|)
name|c
operator|=
name|kbd_keymap
index|[
name|code
index|]
operator|.
name|km_code
index|[
literal|1
index|]
expr_stmt|;
else|else
name|c
operator|=
name|kbd_keymap
index|[
name|code
index|]
operator|.
name|km_code
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|meta_flag
condition|)
name|c
operator||=
literal|0x80
expr_stmt|;
if|if
condition|(
name|ctrl_flag
condition|)
name|c
operator|&=
literal|0x1F
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

end_unit

