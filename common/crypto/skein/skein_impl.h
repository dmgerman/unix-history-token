begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Internal definitions for Skein hashing.  * Source code author: Doug Whiting, 2008.  * This algorithm and source code is released to the public domain.  *  * The following compile-time switches may be defined to control some  * tradeoffs between speed, code size, error checking, and security.  *  * The "default" note explains what happens when the switch is not defined.  *  *  SKEIN_DEBUG            -- make callouts from inside Skein code  *                            to examine/display intermediate values.  *                            [default: no callouts (no overhead)]  *  *  SKEIN_ERR_CHECK        -- how error checking is handled inside Skein  *                            code. If not defined, most error checking  *                            is disabled (for performance). Otherwise,  *                            the switch value is interpreted as:  *                                0: use assert()      to flag errors  *                                1: return SKEIN_FAIL to flag errors  */
end_comment

begin_comment
comment|/* Copyright 2013 Doug Whiting. This code is released to the public domain. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SKEIN_IMPL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SKEIN_IMPL_H_
end_define

begin_include
include|#
directive|include
file|<sys/skein.h>
end_include

begin_include
include|#
directive|include
file|"skein_impl.h"
end_include

begin_include
include|#
directive|include
file|"skein_port.h"
end_include

begin_comment
comment|/* determine where we can get bcopy/bzero declarations */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * "Internal" Skein definitions  *    -- not needed for sequential hashing API, but will be  *           helpful for other uses of Skein (e.g., tree hash mode).  *    -- included here so that they can be shared between  *           reference and optimized code.  */
end_comment

begin_comment
comment|/* tweak word T[1]: bit field starting positions */
end_comment

begin_comment
comment|/* offset 64 because it's the second word  */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BIT
parameter_list|(
name|BIT
parameter_list|)
value|((BIT) - 64)
end_define

begin_comment
comment|/* bits 112..118: level in hash tree */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_POS_TREE_LVL
value|SKEIN_T1_BIT(112)
end_define

begin_comment
comment|/* bit  119: partial final input byte */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_POS_BIT_PAD
value|SKEIN_T1_BIT(119)
end_define

begin_comment
comment|/* bits 120..125: type field */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_POS_BLK_TYPE
value|SKEIN_T1_BIT(120)
end_define

begin_comment
comment|/* bits 126: first block flag */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_POS_FIRST
value|SKEIN_T1_BIT(126)
end_define

begin_comment
comment|/* bit  127: final block flag */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_POS_FINAL
value|SKEIN_T1_BIT(127)
end_define

begin_comment
comment|/* tweak word T[1]: flag bit definition(s) */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_FLAG_FIRST
value|(((uint64_t)1)<< SKEIN_T1_POS_FIRST)
end_define

begin_define
define|#
directive|define
name|SKEIN_T1_FLAG_FINAL
value|(((uint64_t)1)<< SKEIN_T1_POS_FINAL)
end_define

begin_define
define|#
directive|define
name|SKEIN_T1_FLAG_BIT_PAD
value|(((uint64_t)1)<< SKEIN_T1_POS_BIT_PAD)
end_define

begin_comment
comment|/* tweak word T[1]: tree level bit field mask */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_TREE_LVL_MASK
value|(((uint64_t)0x7F)<< SKEIN_T1_POS_TREE_LVL)
end_define

begin_define
define|#
directive|define
name|SKEIN_T1_TREE_LEVEL
parameter_list|(
name|n
parameter_list|)
value|(((uint64_t)(n))<< SKEIN_T1_POS_TREE_LVL)
end_define

begin_comment
comment|/* tweak word T[1]: block type field */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_KEY
value|(0)
end_define

begin_comment
comment|/* key, for MAC and KDF */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_CFG
value|(4)
end_define

begin_comment
comment|/* configuration block */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_PERS
value|(8)
end_define

begin_comment
comment|/* personalization string */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_PK
value|(12)
end_define

begin_comment
comment|/* public key (for signature hashing) */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_KDF
value|(16)
end_define

begin_comment
comment|/* key identifier for KDF */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_NONCE
value|(20)
end_define

begin_comment
comment|/* nonce for PRNG */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_MSG
value|(48)
end_define

begin_comment
comment|/* message processing */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_OUT
value|(63)
end_define

begin_comment
comment|/* output stage */
end_comment

begin_define
define|#
directive|define
name|SKEIN_BLK_TYPE_MASK
value|(63)
end_define

begin_comment
comment|/* bit field mask */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE
parameter_list|(
name|T
parameter_list|)
define|\
value|(((uint64_t)(SKEIN_BLK_TYPE_##T))<< SKEIN_T1_POS_BLK_TYPE)
end_define

begin_comment
comment|/* key, for MAC and KDF */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_KEY
value|SKEIN_T1_BLK_TYPE(KEY)
end_define

begin_comment
comment|/* configuration block */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_CFG
value|SKEIN_T1_BLK_TYPE(CFG)
end_define

begin_comment
comment|/* personalization string */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_PERS
value|SKEIN_T1_BLK_TYPE(PERS)
end_define

begin_comment
comment|/* public key (for digital signature hashing) */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_PK
value|SKEIN_T1_BLK_TYPE(PK)
end_define

begin_comment
comment|/* key identifier for KDF */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_KDF
value|SKEIN_T1_BLK_TYPE(KDF)
end_define

begin_comment
comment|/* nonce for PRNG */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_NONCE
value|SKEIN_T1_BLK_TYPE(NONCE)
end_define

begin_comment
comment|/* message processing */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_MSG
value|SKEIN_T1_BLK_TYPE(MSG)
end_define

begin_comment
comment|/* output stage */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_OUT
value|SKEIN_T1_BLK_TYPE(OUT)
end_define

begin_comment
comment|/* field bit mask */
end_comment

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_MASK
value|SKEIN_T1_BLK_TYPE(MASK)
end_define

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_CFG_FINAL
define|\
value|(SKEIN_T1_BLK_TYPE_CFG | SKEIN_T1_FLAG_FINAL)
end_define

begin_define
define|#
directive|define
name|SKEIN_T1_BLK_TYPE_OUT_FINAL
define|\
value|(SKEIN_T1_BLK_TYPE_OUT | SKEIN_T1_FLAG_FINAL)
end_define

begin_define
define|#
directive|define
name|SKEIN_VERSION
value|(1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN_ID_STRING_LE
end_ifndef

begin_comment
comment|/* allow compile-time personalization */
end_comment

begin_define
define|#
directive|define
name|SKEIN_ID_STRING_LE
value|(0x33414853)
end_define

begin_comment
comment|/* "SHA3" (little-endian) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SKEIN_MK_64
parameter_list|(
name|hi32
parameter_list|,
name|lo32
parameter_list|)
value|((lo32) + (((uint64_t)(hi32))<< 32))
end_define

begin_define
define|#
directive|define
name|SKEIN_SCHEMA_VER
value|SKEIN_MK_64(SKEIN_VERSION, SKEIN_ID_STRING_LE)
end_define

begin_define
define|#
directive|define
name|SKEIN_KS_PARITY
value|SKEIN_MK_64(0x1BD11BDA, 0xA9FC1A22)
end_define

begin_define
define|#
directive|define
name|SKEIN_CFG_STR_LEN
value|(4*8)
end_define

begin_comment
comment|/* bit field definitions in config block treeInfo word */
end_comment

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_LEAF_SIZE_POS
value|(0)
end_define

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_NODE_SIZE_POS
value|(8)
end_define

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_MAX_LEVEL_POS
value|(16)
end_define

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_LEAF_SIZE_MSK
define|\
value|(((uint64_t)0xFF)<< SKEIN_CFG_TREE_LEAF_SIZE_POS)
end_define

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_NODE_SIZE_MSK
define|\
value|(((uint64_t)0xFF)<< SKEIN_CFG_TREE_NODE_SIZE_POS)
end_define

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_MAX_LEVEL_MSK
define|\
value|(((uint64_t)0xFF)<< SKEIN_CFG_TREE_MAX_LEVEL_POS)
end_define

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_INFO
parameter_list|(
name|leaf
parameter_list|,
name|node
parameter_list|,
name|maxLvl
parameter_list|)
define|\
value|((((uint64_t)(leaf))<< SKEIN_CFG_TREE_LEAF_SIZE_POS) |	\ 	(((uint64_t)(node))<< SKEIN_CFG_TREE_NODE_SIZE_POS) |	\ 	(((uint64_t)(maxLvl))<< SKEIN_CFG_TREE_MAX_LEVEL_POS))
end_define

begin_comment
comment|/* use as treeInfo in InitExt() call for sequential processing */
end_comment

begin_define
define|#
directive|define
name|SKEIN_CFG_TREE_INFO_SEQUENTIAL
value|SKEIN_CFG_TREE_INFO(0, 0, 0)
end_define

begin_comment
comment|/*  * Skein macros for getting/setting tweak words, etc.  * These are useful for partial input bytes, hash tree init/update, etc.  */
end_comment

begin_define
define|#
directive|define
name|Skein_Get_Tweak
parameter_list|(
name|ctxPtr
parameter_list|,
name|TWK_NUM
parameter_list|)
value|((ctxPtr)->h.T[TWK_NUM])
end_define

begin_define
define|#
directive|define
name|Skein_Set_Tweak
parameter_list|(
name|ctxPtr
parameter_list|,
name|TWK_NUM
parameter_list|,
name|tVal
parameter_list|)
define|\
value|do {						\ 		(ctxPtr)->h.T[TWK_NUM] = (tVal);	\ 		_NOTE(CONSTCOND)			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|Skein_Get_T0
parameter_list|(
name|ctxPtr
parameter_list|)
value|Skein_Get_Tweak(ctxPtr, 0)
end_define

begin_define
define|#
directive|define
name|Skein_Get_T1
parameter_list|(
name|ctxPtr
parameter_list|)
value|Skein_Get_Tweak(ctxPtr, 1)
end_define

begin_define
define|#
directive|define
name|Skein_Set_T0
parameter_list|(
name|ctxPtr
parameter_list|,
name|T0
parameter_list|)
value|Skein_Set_Tweak(ctxPtr, 0, T0)
end_define

begin_define
define|#
directive|define
name|Skein_Set_T1
parameter_list|(
name|ctxPtr
parameter_list|,
name|T1
parameter_list|)
value|Skein_Set_Tweak(ctxPtr, 1, T1)
end_define

begin_comment
comment|/* set both tweak words at once */
end_comment

begin_define
define|#
directive|define
name|Skein_Set_T0_T1
parameter_list|(
name|ctxPtr
parameter_list|,
name|T0
parameter_list|,
name|T1
parameter_list|)
define|\
value|do {					\ 		Skein_Set_T0(ctxPtr, (T0));	\ 		Skein_Set_T1(ctxPtr, (T1));	\ 		_NOTE(CONSTCOND)		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|Skein_Set_Type
parameter_list|(
name|ctxPtr
parameter_list|,
name|BLK_TYPE
parameter_list|)
define|\
value|Skein_Set_T1(ctxPtr, SKEIN_T1_BLK_TYPE_##BLK_TYPE)
end_define

begin_comment
comment|/*  * set up for starting with a new type: h.T[0]=0; h.T[1] = NEW_TYPE; h.bCnt=0;  */
end_comment

begin_define
define|#
directive|define
name|Skein_Start_New_Type
parameter_list|(
name|ctxPtr
parameter_list|,
name|BLK_TYPE
parameter_list|)
define|\
value|do {								\ 		Skein_Set_T0_T1(ctxPtr, 0, SKEIN_T1_FLAG_FIRST |	\ 		    SKEIN_T1_BLK_TYPE_ ## BLK_TYPE);			\ 		(ctxPtr)->h.bCnt = 0;	\ 		_NOTE(CONSTCOND)					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|Skein_Clear_First_Flag
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {								\ 		(hdr).T[1]&= ~SKEIN_T1_FLAG_FIRST;			\ 		_NOTE(CONSTCOND)					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|Skein_Set_Bit_Pad_Flag
parameter_list|(
name|hdr
parameter_list|)
define|\
value|do {								\ 		(hdr).T[1] |=  SKEIN_T1_FLAG_BIT_PAD;			\ 		_NOTE(CONSTCOND)					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|Skein_Set_Tree_Level
parameter_list|(
name|hdr
parameter_list|,
name|height
parameter_list|)
define|\
value|do {								\ 		(hdr).T[1] |= SKEIN_T1_TREE_LEVEL(height);		\ 		_NOTE(CONSTCOND)					\ 	} while (0)
end_define

begin_comment
comment|/*  * "Internal" Skein definitions for debugging and error checking  * Note: in Illumos we always disable debugging features.  */
end_comment

begin_define
define|#
directive|define
name|Skein_Show_Block
parameter_list|(
name|bits
parameter_list|,
name|ctx
parameter_list|,
name|X
parameter_list|,
name|blkPtr
parameter_list|,
name|wPtr
parameter_list|,
name|ksEvenPtr
parameter_list|,
name|ksOddPtr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Skein_Show_Round
parameter_list|(
name|bits
parameter_list|,
name|ctx
parameter_list|,
name|r
parameter_list|,
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Skein_Show_R_Ptr
parameter_list|(
name|bits
parameter_list|,
name|ctx
parameter_list|,
name|r
parameter_list|,
name|X_ptr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Skein_Show_Final
parameter_list|(
name|bits
parameter_list|,
name|ctx
parameter_list|,
name|cnt
parameter_list|,
name|outPtr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Skein_Show_Key
parameter_list|(
name|bits
parameter_list|,
name|ctx
parameter_list|,
name|key
parameter_list|,
name|keyBytes
parameter_list|)
end_define

begin_comment
comment|/* run-time checks (e.g., bad params, uninitialized context)? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SKEIN_ERR_CHECK
end_ifndef

begin_comment
comment|/* default: ignore all Asserts, for performance */
end_comment

begin_define
define|#
directive|define
name|Skein_Assert
parameter_list|(
name|x
parameter_list|,
name|retCode
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Skein_assert
parameter_list|(
name|x
parameter_list|)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SKEIN_ASSERT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/debug.h>
end_include

begin_define
define|#
directive|define
name|Skein_Assert
parameter_list|(
name|x
parameter_list|,
name|retCode
parameter_list|)
value|ASSERT(x)
end_define

begin_define
define|#
directive|define
name|Skein_assert
parameter_list|(
name|x
parameter_list|)
value|ASSERT(x)
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/debug.h>
end_include

begin_comment
comment|/*  caller error */
end_comment

begin_define
define|#
directive|define
name|Skein_Assert
parameter_list|(
name|x
parameter_list|,
name|retCode
parameter_list|)
define|\
value|do {					\ 		if (!(x))			\ 			return (retCode);	\ 		_NOTE(CONSTCOND)		\ 	} while (0)
end_define

begin_comment
comment|/* internal error */
end_comment

begin_define
define|#
directive|define
name|Skein_assert
parameter_list|(
name|x
parameter_list|)
value|ASSERT(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Skein block function constants (shared across Ref and Opt code)  */
end_comment

begin_enum
enum|enum
block|{
comment|/* Skein_256 round rotation constants */
name|R_256_0_0
init|=
literal|14
block|,
name|R_256_0_1
init|=
literal|16
block|,
name|R_256_1_0
init|=
literal|52
block|,
name|R_256_1_1
init|=
literal|57
block|,
name|R_256_2_0
init|=
literal|23
block|,
name|R_256_2_1
init|=
literal|40
block|,
name|R_256_3_0
init|=
literal|5
block|,
name|R_256_3_1
init|=
literal|37
block|,
name|R_256_4_0
init|=
literal|25
block|,
name|R_256_4_1
init|=
literal|33
block|,
name|R_256_5_0
init|=
literal|46
block|,
name|R_256_5_1
init|=
literal|12
block|,
name|R_256_6_0
init|=
literal|58
block|,
name|R_256_6_1
init|=
literal|22
block|,
name|R_256_7_0
init|=
literal|32
block|,
name|R_256_7_1
init|=
literal|32
block|,
comment|/* Skein_512 round rotation constants */
name|R_512_0_0
init|=
literal|46
block|,
name|R_512_0_1
init|=
literal|36
block|,
name|R_512_0_2
init|=
literal|19
block|,
name|R_512_0_3
init|=
literal|37
block|,
name|R_512_1_0
init|=
literal|33
block|,
name|R_512_1_1
init|=
literal|27
block|,
name|R_512_1_2
init|=
literal|14
block|,
name|R_512_1_3
init|=
literal|42
block|,
name|R_512_2_0
init|=
literal|17
block|,
name|R_512_2_1
init|=
literal|49
block|,
name|R_512_2_2
init|=
literal|36
block|,
name|R_512_2_3
init|=
literal|39
block|,
name|R_512_3_0
init|=
literal|44
block|,
name|R_512_3_1
init|=
literal|9
block|,
name|R_512_3_2
init|=
literal|54
block|,
name|R_512_3_3
init|=
literal|56
block|,
name|R_512_4_0
init|=
literal|39
block|,
name|R_512_4_1
init|=
literal|30
block|,
name|R_512_4_2
init|=
literal|34
block|,
name|R_512_4_3
init|=
literal|24
block|,
name|R_512_5_0
init|=
literal|13
block|,
name|R_512_5_1
init|=
literal|50
block|,
name|R_512_5_2
init|=
literal|10
block|,
name|R_512_5_3
init|=
literal|17
block|,
name|R_512_6_0
init|=
literal|25
block|,
name|R_512_6_1
init|=
literal|29
block|,
name|R_512_6_2
init|=
literal|39
block|,
name|R_512_6_3
init|=
literal|43
block|,
name|R_512_7_0
init|=
literal|8
block|,
name|R_512_7_1
init|=
literal|35
block|,
name|R_512_7_2
init|=
literal|56
block|,
name|R_512_7_3
init|=
literal|22
block|,
comment|/* Skein1024 round rotation constants */
name|R1024_0_0
init|=
literal|24
block|,
name|R1024_0_1
init|=
literal|13
block|,
name|R1024_0_2
init|=
literal|8
block|,
name|R1024_0_3
init|=
literal|47
block|,
name|R1024_0_4
init|=
literal|8
block|,
name|R1024_0_5
init|=
literal|17
block|,
name|R1024_0_6
init|=
literal|22
block|,
name|R1024_0_7
init|=
literal|37
block|,
name|R1024_1_0
init|=
literal|38
block|,
name|R1024_1_1
init|=
literal|19
block|,
name|R1024_1_2
init|=
literal|10
block|,
name|R1024_1_3
init|=
literal|55
block|,
name|R1024_1_4
init|=
literal|49
block|,
name|R1024_1_5
init|=
literal|18
block|,
name|R1024_1_6
init|=
literal|23
block|,
name|R1024_1_7
init|=
literal|52
block|,
name|R1024_2_0
init|=
literal|33
block|,
name|R1024_2_1
init|=
literal|4
block|,
name|R1024_2_2
init|=
literal|51
block|,
name|R1024_2_3
init|=
literal|13
block|,
name|R1024_2_4
init|=
literal|34
block|,
name|R1024_2_5
init|=
literal|41
block|,
name|R1024_2_6
init|=
literal|59
block|,
name|R1024_2_7
init|=
literal|17
block|,
name|R1024_3_0
init|=
literal|5
block|,
name|R1024_3_1
init|=
literal|20
block|,
name|R1024_3_2
init|=
literal|48
block|,
name|R1024_3_3
init|=
literal|41
block|,
name|R1024_3_4
init|=
literal|47
block|,
name|R1024_3_5
init|=
literal|28
block|,
name|R1024_3_6
init|=
literal|16
block|,
name|R1024_3_7
init|=
literal|25
block|,
name|R1024_4_0
init|=
literal|41
block|,
name|R1024_4_1
init|=
literal|9
block|,
name|R1024_4_2
init|=
literal|37
block|,
name|R1024_4_3
init|=
literal|31
block|,
name|R1024_4_4
init|=
literal|12
block|,
name|R1024_4_5
init|=
literal|47
block|,
name|R1024_4_6
init|=
literal|44
block|,
name|R1024_4_7
init|=
literal|30
block|,
name|R1024_5_0
init|=
literal|16
block|,
name|R1024_5_1
init|=
literal|34
block|,
name|R1024_5_2
init|=
literal|56
block|,
name|R1024_5_3
init|=
literal|51
block|,
name|R1024_5_4
init|=
literal|4
block|,
name|R1024_5_5
init|=
literal|53
block|,
name|R1024_5_6
init|=
literal|42
block|,
name|R1024_5_7
init|=
literal|41
block|,
name|R1024_6_0
init|=
literal|31
block|,
name|R1024_6_1
init|=
literal|44
block|,
name|R1024_6_2
init|=
literal|47
block|,
name|R1024_6_3
init|=
literal|46
block|,
name|R1024_6_4
init|=
literal|19
block|,
name|R1024_6_5
init|=
literal|42
block|,
name|R1024_6_6
init|=
literal|44
block|,
name|R1024_6_7
init|=
literal|25
block|,
name|R1024_7_0
init|=
literal|9
block|,
name|R1024_7_1
init|=
literal|48
block|,
name|R1024_7_2
init|=
literal|35
block|,
name|R1024_7_3
init|=
literal|52
block|,
name|R1024_7_4
init|=
literal|23
block|,
name|R1024_7_5
init|=
literal|31
block|,
name|R1024_7_6
init|=
literal|37
block|,
name|R1024_7_7
init|=
literal|20
block|}
enum|;
end_enum

begin_comment
comment|/* number of rounds for the different block sizes */
end_comment

begin_define
define|#
directive|define
name|SKEIN_256_ROUNDS_TOTAL
value|(72)
end_define

begin_define
define|#
directive|define
name|SKEIN_512_ROUNDS_TOTAL
value|(72)
end_define

begin_define
define|#
directive|define
name|SKEIN1024_ROUNDS_TOTAL
value|(80)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_256_IV_128
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_256_IV_160
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_256_IV_224
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_256_IV_256
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_512_IV_128
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_512_IV_160
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_512_IV_224
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_512_IV_256
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_512_IV_384
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN_512_IV_512
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN1024_IV_384
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN1024_IV_512
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uint64_t
name|SKEIN1024_IV_1024
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SKEIN_IMPL_H_ */
end_comment

end_unit

