begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/****************************************************************************  *  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corporation.  * All rights reserved.  *  * Copyright (c) 1998 I2O Special Interest Group (I2O SIG)  * All rights reserved  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of this driver software, even if advised  * of the possibility of such damage.  *  * This information is provided on an as-is basis without warranty of any  * kind, either express or implied, including but not limited to, implied  * warranties or merchantability and fitness for a particular purpose. I2O SIG  * does not warrant that this program will meet the user's requirements or  * that the operation of these programs will be uninterrupted or error-free.  * The I2O SIG disclaims all liability, including liability for infringement  * of any proprietary rights, relating to implementation of information in  * this specification. The I2O SIG does not warrant or represent that such  * implementations(s) will not infringe such rights. Acceptance and use of  * this program constitutes the user's understanding that he will have no  * recourse to I2O SIG for any actual or consequential damages including, but  * not limited to, loss profits arising out of use or inability to use this  * program.  *  * This information is provided for the purpose of recompilation of the  * driver code provided by Distributed Processing Technology only. It is  * NOT to be used for any other purpose.  *  * To develop other products based upon I2O definitions, it is necessary to  * become a "Registered Developer" of the I2O SIG. This can be done by calling  * 415-750-8352 in the US, or via http://www.i2osig.org.  *  **************************************************************************/
end_comment

begin_comment
comment|/*  * This template provides place holders for architecture and compiler  * dependencies. It should be filled in and renamed as i2odep.h.  * i2odep.h is included by i2otypes.h.<xxx> marks the places to fill.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__INCi2odeph
end_ifndef

begin_define
define|#
directive|define
name|__INCi2odeph
end_define

begin_define
define|#
directive|define
name|I2ODEP_REV
value|1_5_4
end_define

begin_comment
comment|/*  * Pragma macros. These are to assure appropriate alignment between  * host/IOP as defined by the I2O Specification. Each one of the shared  * header files includes these macros.  */
end_comment

begin_define
define|#
directive|define
name|PRAGMA_ALIGN_PUSH
end_define

begin_define
define|#
directive|define
name|PRAGMA_ALIGN_POP
end_define

begin_define
define|#
directive|define
name|PRAGMA_PACK_PUSH
end_define

begin_define
define|#
directive|define
name|PRAGMA_PACK_POP
end_define

begin_comment
comment|/* Setup the basics */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|S8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|S16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|U8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|U16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|U32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|S32
typedef|;
end_typedef

begin_comment
comment|/* Bitfields */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|U16
name|BF
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|U32
name|BF
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VOID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__VOID
end_ifndef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_ARC
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|void
name|VOID
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__VOID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Boolean */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BOOL
end_ifndef

begin_define
define|#
directive|define
name|__BOOL
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOL
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|__FAR__
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|__FAR__
value|far
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FAR__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NULL */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|NULL
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|NULL
value|((VOID __FAR__ *)0L)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__SPARC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|char
name|CHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|pCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|INT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|pINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|pUINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
modifier|*
name|pINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
modifier|*
name|pUINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
modifier|*
name|pINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
modifier|*
name|pUINT32
typedef|;
end_typedef

begin_comment
comment|//typedef SCSI_REQUEST_BLOCK     OS_REQUEST_T;
end_comment

begin_comment
comment|//typedef PSCSI_REQUEST_BLOCK    pOS_REQUEST_T;
end_comment

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__NEAR__
end_ifndef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|__NEAR__
value|near
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__NEAR__
end_define

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
name|pVOID
value|void *
end_define

begin_define
define|#
directive|define
name|pBOOLEAN
value|BOOLEAN *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1996-2000 Distributed Processing Technology Corporation  * Copyright (c) 2000 Adaptec Corporation.  * All rights reserved.  */
end_comment

begin_comment
comment|/*  *      Define some generalized portability macros  *      These macros follow the following parameterization:  *          _F_getXXX(pointer,primaryElement<,offset>,referredElement)  *          _F_setXXX(pointer,primaryElement<,offset>,referredElement,newValue)  *      These parameters are shortened to u, w, x, y and z to reduce clutter.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|I2O_TID_MASK
value|((U16)((1L<<I2O_TID_SZ)-1))
end_define

begin_comment
comment|/* First 12 bits */
end_comment

begin_define
define|#
directive|define
name|_F_getTID
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(*((U16 __FAR__ *)(&((w)->x)))& I2O_TID_MASK)
end_define

begin_define
define|#
directive|define
name|_F_setTID
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(*((U16 __FAR__ *)(&((w)->x)))\&= 0xFFFF - I2O_TID_MASK);\                               (*((U16 __FAR__ *)(&((w)->x)))\                                |=(U16)(z)&I2O_TID_MASK)
end_define

begin_comment
comment|/* Seconds 12 bits (optimized with the assumption of 12& 12) */
end_comment

begin_define
define|#
directive|define
name|_F_getTID1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((*(U16 __FAR__ *)(((U8 __FAR__ *)(&((w)->x)))\                                + (I2O_TID_SZ/8)))\>> (I2O_TID_SZ-((I2O_TID_SZ/8)*8)))
end_define

begin_define
define|#
directive|define
name|_F_setTID1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((*((U16 __FAR__ *)(((U8 __FAR__ *)(&((w)->x)))\                                + (I2O_TID_SZ/8))))&= (0xFFFF>> I2O_TID_SZ));\                               ((*((U16 __FAR__ *)(((U8 __FAR__ *)(&((w)->x)))\                                + (I2O_TID_SZ/8)))) |= (z)\<< (I2O_TID_SZ-((I2O_TID_SZ/8)*8)))
end_define

begin_comment
comment|/* Last 8 bits */
end_comment

begin_define
define|#
directive|define
name|_F_getFunc
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(((U8 __FAR__ *)(&((w)->x)))\                                + ((I2O_TID_SZ+I2O_TID_SZ)/8)))
end_define

begin_define
define|#
directive|define
name|_F_setFunc
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(_F_getFunc(w,x,y) = (z))
end_define

begin_define
define|#
directive|define
name|I2O_SG_COUNT_MASK
value|((U32)((1L<<I2O_SG_COUNT_SZ)-1))
end_define

begin_comment
comment|/* First 24 bits */
end_comment

begin_define
define|#
directive|define
name|_F_getCount
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(*((U32 __FAR__ *)(&((w)->x)))&I2O_SG_COUNT_MASK)
end_define

begin_comment
comment|/*  * The following is less efficient because of compiler inefficiencies:  *  * # define _F_setCount(w,x,y,z)  *((U16 __FAR__ *)(&((w)->x))) = (U16)(z);\  *                              ((U8 __FAR__ *)(&((w)->x)))[2]= (U8)((z)>>16L)  *  * so we will use the apparently more code intensive:  */
end_comment

begin_define
define|#
directive|define
name|_F_setCount
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(*((U32 __FAR__ *)(&((w)->x)))\&= 0xFFFFFFFFL - I2O_SG_COUNT_MASK);\                               (*((U32 __FAR__ *)(&((w)->x)))\                                |= (z)& I2O_SG_COUNT_MASK)
end_define

begin_comment
comment|/* Last 8 bits */
end_comment

begin_define
define|#
directive|define
name|_F_getFlags
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(*(((U8 __FAR__ *)(&((w)->x)))\                                + (I2O_SG_COUNT_SZ/8)))
end_define

begin_define
define|#
directive|define
name|_F_setFlags
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(_F_getFlags(w,x,y) = (z))
end_define

begin_comment
comment|/* Other accesses that are simpler */
end_comment

begin_define
define|#
directive|define
name|_F_get1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get4bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set4bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U16)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get12bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U16)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set12bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U16)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_elif
elif|#
directive|elif
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
end_elif

begin_comment
comment|/* First 12 bits */
end_comment

begin_define
define|#
directive|define
name|_F_getTID
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|getL12bit(w,x,0)
end_define

begin_define
define|#
directive|define
name|_F_setTID
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|setL12bit(w,x,0,z)
end_define

begin_define
define|#
directive|define
name|_F_getTID1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|getL12bit1(w,x,0)
end_define

begin_define
define|#
directive|define
name|_F_setTID1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|setL12bit1(w,x,0,z)
end_define

begin_define
define|#
directive|define
name|_F_getFunc
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|getL8bit(w,x,3)
end_define

begin_define
define|#
directive|define
name|_F_setFunc
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|setL8bit(w,x,3,z)
end_define

begin_define
define|#
directive|define
name|_F_getCount
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|getL24bit1(w,x,0)
end_define

begin_define
define|#
directive|define
name|_F_setCount
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|setL24bit1(w,x,0,z)
end_define

begin_define
define|#
directive|define
name|_F_getFlags
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|getL8bit(w,x,3)
end_define

begin_define
define|#
directive|define
name|_F_setFlags
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|setL8bit(w,x,3,z)
end_define

begin_comment
comment|/* Other accesses that are simpler */
end_comment

begin_define
define|#
directive|define
name|_F_get1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|getL1bit(w,x,y)
end_define

begin_define
define|#
directive|define
name|_F_set1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|setL1bit(w,x,y,u)
end_define

begin_define
define|#
directive|define
name|_F_get1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|getL1bit1(w,x,y)
end_define

begin_define
define|#
directive|define
name|_F_set1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|setL1bit1(w,x,y,u)
end_define

begin_define
define|#
directive|define
name|_F_get4bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|getL4bit(w,x,y)
end_define

begin_define
define|#
directive|define
name|_F_set4bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|setL4bit(w,x,y,u)
end_define

begin_define
define|#
directive|define
name|_F_get8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|getL8bit(w,x,y)
end_define

begin_define
define|#
directive|define
name|_F_set8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|setL8bit(w,x,y,u)
end_define

begin_define
define|#
directive|define
name|_F_get12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|getL12bit(w,x,y)
end_define

begin_define
define|#
directive|define
name|_F_set12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|setL12bit(w,x,y,z)
end_define

begin_define
define|#
directive|define
name|_F_get12bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|getL12bit1(w,x,(y)-1)
end_define

begin_define
define|#
directive|define
name|_F_set12bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|setL12bit1(w,x,(y)-1,u)
end_define

begin_define
define|#
directive|define
name|_F_get16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|getL16bit(w,x,y)
end_define

begin_define
define|#
directive|define
name|_F_set16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|setL16bit(w,x,y,u)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_F_getTID
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((U16)((w)->y))
end_define

begin_define
define|#
directive|define
name|_F_setTID
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((w)->y = (z))
end_define

begin_define
define|#
directive|define
name|_F_getTID1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((U16)((w)->y))
end_define

begin_define
define|#
directive|define
name|_F_setTID1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((w)->y = (z))
end_define

begin_define
define|#
directive|define
name|_F_getFunc
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((U8)((w)->y))
end_define

begin_define
define|#
directive|define
name|_F_setFunc
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((w)->y = (z))
end_define

begin_define
define|#
directive|define
name|_F_getCount
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((U32)((w)->y))
end_define

begin_define
define|#
directive|define
name|_F_setCount
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((w)->y = (z))
end_define

begin_define
define|#
directive|define
name|_F_getFlags
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((U8)((w)->y))
end_define

begin_define
define|#
directive|define
name|_F_setFlags
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((w)->y = (z))
end_define

begin_define
define|#
directive|define
name|_F_get1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get4bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set4bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U8)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U16)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get12bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U16)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set12bit4
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_define
define|#
directive|define
name|_F_get16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|((U16)((w)->z))
end_define

begin_define
define|#
directive|define
name|_F_set16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|,
name|u
parameter_list|)
value|((w)->z = (u))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *      Define some specific portability macros  *      These macros follow the following parameterization:  *              XXX_getYYY (pointer)  *              XXX_setYYY (pointer, newValue)  *      These parameters are shortened to x and y to reduce clutter.  */
end_comment

begin_comment
comment|/*  * General SGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_FLAGS_COUNT_getCount
parameter_list|(
name|x
parameter_list|)
value|_F_getCount(x,Count,Count)
end_define

begin_define
define|#
directive|define
name|I2O_FLAGS_COUNT_setCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|_F_setCount(x,Count,Count,y)
end_define

begin_define
define|#
directive|define
name|I2O_FLAGS_COUNT_getFlags
parameter_list|(
name|x
parameter_list|)
value|_F_getFlags(x,Count,Flags)
end_define

begin_define
define|#
directive|define
name|I2O_FLAGS_COUNT_setFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|_F_setFlags(x,Count,Flags,y)
end_define

begin_comment
comment|/*  * I2O_SGE_SIMPLE_ELEMENT  */
end_comment

begin_define
define|#
directive|define
name|I2O_SGE_SIMPLE_ELEMENT_getPhysicalAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->PhysicalAddress),0)
end_define

begin_define
define|#
directive|define
name|I2O_SGE_SIMPLE_ELEMENT_setPhysicalAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->PhysicalAddress),0,y)
end_define

begin_comment
comment|/*  * I2O_SGE_LONG_TRANSACTION_ELEMENT  */
end_comment

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSACTION_ELEMENT_getLongElementLength
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getCount(x,LongElementLength,LongElementLength)
end_define

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSACTION_ELEMENT_setLongElementLength
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setCount(x,LongElementLength,LongElementLength,y)
end_define

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSACTION_ELEMENT_getFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFlags(x,LongElementLength,Flags)
end_define

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSACTION_ELEMENT_setFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFlags(x,LongElementLength,Flags,y)
end_define

begin_comment
comment|/*  * I2O_SGE_LONG_TRANSPORT_ELEMENT  */
end_comment

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSPORT_ELEMENT_getLongElementLength
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getCount(x,LongElementLength,LongElementLength)
end_define

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSPORT_ELEMENT_setLongElementLength
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setCount(x,LongElementLength,LongElementLength,y)
end_define

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSPORT_ELEMENT_getFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFlags(x,LongElementLength,Flags)
end_define

begin_define
define|#
directive|define
name|I2O_SGE_LONG_TRANSPORT_ELEMENT_setFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFlags(x,LongElementLength,Flags,y)
end_define

begin_comment
comment|/*  * I2O_EXEC_ADAPTER_ASSIGN_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_ADAPTER_ASSIGN_MESSAGE_getDdmTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,DdmTID,DdmTID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_ADAPTER_ASSIGN_MESSAGE_setDdmTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,DDdmTID,DdmTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_ADAPTER_ASSIGN_MESSAGE_getOperationFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,DdmTID,OperationFlags)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_ADAPTER_ASSIGN_MESSAGE_setOperationFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,DdmTID,OperationFlags,y)
end_define

begin_comment
comment|/*  * I2O_EXEC_BIOS_INFO_SET_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_BIOS_INFO_SET_MESSAGE_getDeviceTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,DeviceTID,DeviceTID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_BIOS_INFO_SET_MESSAGE_setDeviceTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,DeviceTID,DeviceTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_BIOS_INFO_SET_MESSAGE_getBiosInfo
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,DeviceTID,BiosInfo)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_BIOS_INFO_SET_MESSAGE_setBiosInfo
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,DeviceTID,BiosInfo,y)
end_define

begin_comment
comment|/*  * I2O_ALIAS_CONNECT_SETUP  */
end_comment

begin_define
define|#
directive|define
name|I2O_ALIAS_CONNECT_SETUP_getIOP1AliasForTargetDevice
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,IOP1AliasForTargetDevice,IOP1AliasForTargetDevice)
end_define

begin_define
define|#
directive|define
name|I2O_ALIAS_CONNECT_SETUP_setIOP1AliasForTargetDevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,IOP1AliasForTargetDevice,IOP1AliasForTargetDevice,y)
end_define

begin_define
define|#
directive|define
name|I2O_ALIAS_CONNECT_SETUP_getIOP2AliasForInitiatorDevice
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,IOP1AliasForTargetDevice,IOP2AliasForInitiatorDevice)
end_define

begin_define
define|#
directive|define
name|I2O_ALIAS_CONNECT_SETUP_setIOP2AliasForInitiatorDevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,IOP1AliasForTargetDevice,IOP2AliasForInitiatorDevice,y)
end_define

begin_comment
comment|/*  * I2O_OBJECT_CONNECT_SETUP  */
end_comment

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_SETUP_getTargetDevice
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,TargetDevice,TargetDevice)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_SETUP_setTargetDevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,TargetDevice,TargetDevice,y)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_SETUP_getInitiatorDevice
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,TargetDevice,InitiatorDevice)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_SETUP_setInitiatorDevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,TargetDevice,InitiatorDevice,y)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_SETUP_getOperationFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,TargetDevice,OperationFlags)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_SETUP_setOperationFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,TargetDevice,OperationFlags,y)
end_define

begin_comment
comment|/*  * I2O_OBJECT_CONNECT_REPLY  */
end_comment

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_REPLY_getTargetDevice
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,TargetDevice,TargetDevice)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_REPLY_setTargetDevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,TargetDevice,TargetDevice,y)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_REPLY_getInitiatorDevice
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,TargetDevice,InitiatorDevice)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_REPLY_setInitiatorDevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,TargetDevice,InitiatorDevice,y)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_REPLY_getReplyStatusCode
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,TargetDevice,ReplyStatusCode)
end_define

begin_define
define|#
directive|define
name|I2O_OBJECT_CONNECT_REPLY_setReplyStatusCode
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,TargetDevice,ReplyStatusCode,y)
end_define

begin_comment
comment|/*  * I2O_EXEC_DEVICE_ASSIGN_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_ASSIGN_MESSAGE_getDeviceTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,Object.DeviceTID,Object.DeviceTID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_ASSIGN_MESSAGE_setDeviceTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,Object.DeviceTID,Object.DeviceTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_ASSIGN_MESSAGE_getIOP_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,Object.DeviceTID,Object.IOP_ID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_ASSIGN_MESSAGE_setIOP_ID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,Object.DeviceTID,Object.IOP_ID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_ASSIGN_MESSAGE_getOperationFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,Object.DeviceTID,Object.OperationFlags)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_ASSIGN_MESSAGE_setOperationFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,Object.DeviceTID,Object.OperationFlags,y)
end_define

begin_comment
comment|/*  * I2O_EXEC_DEVICE_RELEASE_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_RELEASE_MESSAGE_getDeviceTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,Object.DeviceTID,Object.DeviceTID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_RELEASE_MESSAGE_setDeviceTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,Object.DeviceTID,Object.DeviceTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_RELEASE_MESSAGE_getIOP_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,Object.DeviceTID,Object.IOP_ID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_RELEASE_MESSAGE_setIOP_ID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,Object.DeviceTID,Object.IOP_ID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_RELEASE_MESSAGE_getOperationFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,Object.DeviceTID,Object.OperationFlags)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_DEVICE_RELEASE_MESSAGE_setOperationFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,Object.DeviceTID,Object.OperationFlags,y)
end_define

begin_comment
comment|/*  * I2O_EXEC_IOP_RESET_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getTargetAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,TargetAddress,TargetAddress)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setTargetAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,TargetAddress,TargetAddress,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getInitiatorAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,TargetAddress,InitiatorAddress)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setInitiatorAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,TargetAddress,InitiatorAddress,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getFunction
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,TargetAddress,Function)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setFunction
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,TargetAddress,Function,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getVersionOffset
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->VersionOffset),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setVersionOffset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->VersionOffset),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getMsgFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->VersionOffset),1)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setMsgFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->VersionOffset),1,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getMessageSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->VersionOffset),2)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setMessageSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->VersionOffset),2,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getStatusWordLowAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->StatusWordLowAddress),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setStatusWordLowAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->StatusWordLowAddress),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_getStatusWordHighAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->StatusWordHighAddress),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_IOP_RESET_MESSAGE_setStatusWordHighAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->StatusWordHighAddress),0,y)
end_define

begin_comment
comment|/*  * I2O_EXEC_STATUS_GET_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getVersionOffset
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->VersionOffset),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setVersionOffset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->VersionOffset),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getMsgFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->VersionOffset),1)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setMsgFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->VersionOffset),1,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getMessageSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->VersionOffset),2)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setMessageSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->VersionOffset),2,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getReplyBufferAddressLow
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->ReplyBufferAddressLow),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setReplyBufferAddressLow
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->ReplyBufferAddressLow),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getReplyBufferAddressHigh
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->ReplyBufferAddressHigh),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setReplyBufferAddressHigh
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->ReplyBufferAddressHigh),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getReplyBufferLength
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->ReplyBufferLength),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setReplyBufferLength
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->ReplyBufferLength),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getTargetAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,TargetAddress,TargetAddress)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setTargetAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,TargetAddress,TargetAddress,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getInitiatorAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,TargetAddress,InitiatorAddress)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setInitiatorAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,TargetAddress,InitiatorAddress,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_getFunction
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,TargetAddress,Function)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_MESSAGE_setFunction
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,TargetAddress,Function,y)
end_define

begin_comment
comment|/*  * I2O_MESSAGE_FRAME  */
end_comment

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_getVersionOffset
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->VersionOffset)),0)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setVersionOffset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1(((&(x)->VersionOffset)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_getMsgFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->VersionOffset)),1)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setMsgFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&((x)->VersionOffset)),1,y)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_getMessageSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->VersionOffset)),2)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setMessageSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&((x)->VersionOffset)),2,y)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_getTargetAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,TargetAddress,TargetAddress)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setTargetAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,TargetAddress,TargetAddress,y)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_getInitiatorAddress
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,TargetAddress,InitiatorAddress)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setInitiatorAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID1(x,TargetAddress,InitiatorAddress,y)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_getFunction
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,TargetAddress,Function)
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setFunction
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,TargetAddress,Function,y)
end_define

begin_comment
comment|/* 32 bit only for now */
end_comment

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_getInitiatorContext
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->InitiatorContext
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setInitiatorContext
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->InitiatorContext = (y))
end_define

begin_comment
comment|/*  *	We are spilling the 64 bit Context field into the Transaction  *	context of the specific frames. Synchronous commands (resetIop  *	et al) do not have this field, so beware. Also, Failed Reply frames  *	can not contain the 64 bit context, the software must reference  *	the PreservedMFA and pick up the 64 bit context from the incoming  *	message frame. The software must make no reference to the  *	TransactionContext field at all.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|800
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|u_int64_t
end_ifndef

begin_define
define|#
directive|define
name|u_int64_t
value|unsigned __int64
end_define

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
name|I2O_MESSAGE_FRAME_getInitiatorContext64
parameter_list|(
name|x
parameter_list|)
define|\
value|(*((u_int64_t *)(&((x)->InitiatorContext))))
end_define

begin_define
define|#
directive|define
name|I2O_MESSAGE_FRAME_setInitiatorContext64
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((*((u_int64_t *)(&((x)->InitiatorContext))))=(y))
end_define

begin_comment
comment|/*  * I2O_EXEC_OUTBOUND_INIT_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_getHostPageFrameSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->HostPageFrameSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_setHostPageFrameSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->HostPageFrameSize),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_getInitCode
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->InitCode),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_setInitCode
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->InitCode),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_getreserved
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->reserved),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_setreserved
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->reserved),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_getOutboundMFrameSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->OutboundMFrameSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_OUTBOUND_INIT_MESSAGE_setOutboundMFrameSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->OutboundMFrameSize),0,y)
end_define

begin_comment
comment|/*  * I2O_EXEC_SYS_TAB_SET_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SET_MESSAGE_getIOP_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,IOP_ID,IOP_ID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SET_MESSAGE_setIOP_ID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,IOP_ID,IOP_ID,y)
end_define

begin_comment
comment|/* #define I2O_EXEC_SYS_TAB_SET_MESSAGE_getreserved1(x) */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SET_MESSAGE_getHostUnitID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get16bit(x,IOP_ID,2,HostUnitID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SET_MESSAGE_setHostUnitID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set16bit(x,IOP_ID,2,HostUnitID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SET_MESSAGE_getSegmentNumber
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,SegmentNumber,SegmentNumber)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_SYS_TAB_SET_MESSAGE_setSegmentNumber
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_get12bit(x,SegmentNumber,SegmentNumber,y)
end_define

begin_comment
comment|/*      later  * I2O_EXEC_SYS_ENABLE_MESSAGE  */
end_comment

begin_comment
comment|/*  * I2O_CLASS_ID  */
end_comment

begin_define
define|#
directive|define
name|I2O_CLASS_ID_getClass
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,Class,0,Class)
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ID_setClass
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,Class,0,Class,y)
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ID_getVersion
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get4bit4(x,Class,1,Version)
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ID_setVersion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set4bit4(x,Class,1,Version,y)
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ID_getOrganizationID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get16bit(x,Class,2,OrganizationID)
end_define

begin_define
define|#
directive|define
name|I2O_CLASS_ID_setOrganizationID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set16bit(x,Class,2,OrganizationID,y)
end_define

begin_comment
comment|/*  * I2O_SET_SYSTAB_HEADER  */
end_comment

begin_define
define|#
directive|define
name|I2O_SET_SYSTAB_HEADER_getNumberEntries
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->NumberEntries)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SET_SYSTAB_HEADER_setNumberEntries
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->NumberEntries),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_SET_SYSTAB_HEADER_getSysTabVersion
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->SysTabVersion)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SET_SYSTAB_HEADER_setSysTabVersion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->SysTabVersion),0,y)
end_define

begin_comment
comment|/*  U16 reserved		*/
end_comment

begin_comment
comment|/*  U32 CurrentChangeIndicator	*/
end_comment

begin_comment
comment|/*  * I2O_IOP_ENTRY  */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getOrganizationID
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->OrganizationID)),0)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setOrganizationID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&((x)->OrganizationID)),0,y)
end_define

begin_comment
comment|/* #define I2O_IOP_ENTRY_getreserved U16; */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getIOP_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,IOP_ID,0,IOP_ID)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setIOP_ID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,IOP_ID,0,IOP_ID,y)
end_define

begin_comment
comment|/*   BF                          reserved3:I2O_RESERVED_4BITS;	*/
end_comment

begin_comment
comment|/*   BF                          reserved1:I2O_RESERVED_16BITS;	*/
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getSegmentNumber
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,SegmentNumber,0,SegmentNumber)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setSegmentNumber
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,SegmentNumber,0,SegmentNumber,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getI2oVersion
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get4bit4(x,SegmentNumber,1,I2oVersion)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setI2oVersion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set4bit4(x,SegmentNumber,1,I2oVersion,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getIopState
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,SegmentNumber,2,IopState)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setIopState
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set8bit(x,SegmentNumber,2,IopState,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getMessengerType
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,SegmentNumber,3,MessengerType)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setMessengerType
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set8bit(x,SegmentNumber,3,MessengerType,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getInboundMessageFrameSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->InboundMessageFrameSize)),0)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setInboundMessageFrameSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&((x)->InboundMessageFrameSize)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getreserved2
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->reserved2)),0)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setreserved2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&((x)->reserved2)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getLastChanged
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->LastChanged)),0)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setLastChanged
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->LastChanged)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getIopCapabilities
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->IopCapabilities)),0)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setIopCapabilities
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->IopCapabilities)),0,y)
end_define

begin_comment
comment|/* might want to declare I2O_MESSENGER_INFO struct */
end_comment

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getInboundMessagePortAddressLow
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->MessengerInfo.InboundMessagePortAddressLow)),0)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setInboundMessagePortAddressLow
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->MessengerInfo.InboundMessagePortAddressLow)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_getInboundMessagePortAddressHigh
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->MessengerInfo.InboundMessagePortAddressHigh)),0)
end_define

begin_define
define|#
directive|define
name|I2O_IOP_ENTRY_setInboundMessagePortAddressHigh
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->MessengerInfo.InboundMessagePortAddressHigh)),0,y)
end_define

begin_comment
comment|/*  *  I2O_HRT  */
end_comment

begin_define
define|#
directive|define
name|I2O_HRT_getNumberEntries
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->NumberEntries)),0)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_setNumberEntries
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->NumberEntries),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_getEntryLength
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->EntryLength),0)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_setEntryLength
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->EntryLength),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_getHRTVersion
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->HRTVersion),0)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_setHRTVersion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->HRTVersion),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_getCurrentChangeIndicator
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->CurrentChangeIndicator),0)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_setCurrentChangeIndicator
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->CurrentChangeIndicator),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_getHRTEntryPtr
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((&((x)->HRTEntry[0+y])))
end_define

begin_comment
comment|/*  *  I2O_HRT_ENTRY  */
end_comment

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_getAdapterID
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->AdapterID)),0)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_setAdapterID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->AdapterID),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_getControllingTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,ControllingTID,ControllingTID)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_setControllingTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,ControllingTID,ControllingTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_getAdapterState
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get4bit4(x,ControllingTID,1,AdapterState)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_setIAdapterState
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set4bit4(x,ControllingTID,1,AdapterState,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_getBusNumber
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,ControllingTID,2,BusNumber)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_setBusNumber
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set8bit(x,ControllingTID,2,BusNumber,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_getBusType
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,ControllingTID,3,BusType)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_setBusType
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set8bit(x,ControllingTID,3,BusType,y)
end_define

begin_define
define|#
directive|define
name|I2O_HRT_ENTRY_getPCIBusPtr
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(&((x)->uBus.PCIBus))
end_define

begin_comment
comment|/*  *  I2O_LCT  */
end_comment

begin_define
define|#
directive|define
name|I2O_LCT_getTableSize
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get16bit(x,TableSize,0,TableSize)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_setTableSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set16bit(x,TableSize,0,TableSize,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_getBootDeviceTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,TableSize,2,BootDeviceTID)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_setBootDeviceTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,TableSize,2,BootDeviceTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_getLctVer
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get4bit4(x,TableSize,3,LctVer)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_setLctVer
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set4bit4(x,TableSize,3,LctVer,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_getIopFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->IopFlags),0)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_setIopFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->IopFlags),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_getCurrentChangeIndicator
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->CurrentChangeIndicator),0)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_setCurrentChangeIndicator
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->CurrentChangeIndicator),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_getLCTEntryPtr
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(&((x)->LCTEntry[0+y]))
end_define

begin_comment
comment|/*  *  I2O_LCT_ENTRY  */
end_comment

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getTableEntrySize
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get16bit(x,TableEntrySize,0,TableEntrySize)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setTableEntrySize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set16bit(x,TableEntrySize,0,TableEntrySize,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getLocalTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,TableEntrySize,2,LocalTID)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setLocalTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,TableEntrySize,2,LocalTID,y)
end_define

begin_comment
comment|/*    BF                  4        reserved:I2O_4BIT_VERSION_SZ; */
end_comment

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getChangeIndicator
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->ChangeIndicator),0)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setChangeIndicator
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->ChangeIndicator),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getDeviceFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->DeviceFlags),0)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setDeviceFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->DeviceFlags),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getClassIDPtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->ClassID))
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getSubClassInfo
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->SubClassInfo),0)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setSubClassInfo
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->SubClassInfo),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getUserTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID(x,UserTID,UserTID)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setUserTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setTID(x,UserTID,UserTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getParentTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getTID1(x,UserTID,ParentTID)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setParentTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_getTID1(x,UserTID,ParentTID,y)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getBiosInfo
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_getFunc(x,UserTID,BiosInfo)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setBiosInfo
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_setFunc(x,UserTID,BiosInfo,y)
end_define

begin_comment
comment|/*  2 ulong   U8                    8      IdentityTag[I2O_IDENTITY_TAG_SZ]; */
end_comment

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_getEventCapabilities
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->EventCapabilities),0)
end_define

begin_define
define|#
directive|define
name|I2O_LCT_ENTRY_setEventCapabilities
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->EventCapabilities),0,y)
end_define

begin_comment
comment|/*  *  I2O_PARAM_OPERATIONS_LIST_HEADER  */
end_comment

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATIONS_LIST_HEADER_getOperationCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->OperationCount),0)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATIONS_LIST_HEADER_setOperationCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->OperationCount),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATIONS_LIST_HEADER_getReserved
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->Reserved),0)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATIONS_LIST_HEADER_setReserved
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->Reserved),0,y)
end_define

begin_comment
comment|/*  *  I2O_PARAM_OPERATION_ALL_TEMPLATE  */
end_comment

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATION_ALL_TEMPLATE_getOperation
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->Operation),0)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATION_ALL_TEMPLATE_setOperation
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->Operation),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATION_ALL_TEMPLATE_getGroupNumber
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->GroupNumber),0)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATION_ALL_TEMPLATE_setGroupNumber
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->GroupNumber),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATION_ALL_TEMPLATE_getFieldCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->FieldCount),0)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_OPERATION_ALL_TEMPLATE_setFieldCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->FieldCount),0,y)
end_define

begin_comment
comment|/*  *  I2O_PARAM_RESULTS_LIST_HEADER  */
end_comment

begin_define
define|#
directive|define
name|I2O_PARAM_RESULTS_LIST_HEADER_getResultCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->ResultCount),0)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_RESULTS_LIST_HEADER_setResultCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->ResultCount),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_RESULTS_LIST_HEADER_getReserved
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->Reserved),0)
end_define

begin_define
define|#
directive|define
name|I2O_PARAM_RESULTS_LIST_HEADER_setReserved
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->Reserved),0,y)
end_define

begin_comment
comment|/*  later  *  I2O_HBA_ADAPTER_RESET_MESSAGE  */
end_comment

begin_comment
comment|/*  LATER  *  I2O_SCSI_DEVICE_RESET_MESSAGE  */
end_comment

begin_comment
comment|/*  LATER  *  I2O_HBA_BUS_RESET_MESSAGE  */
end_comment

begin_comment
comment|/*  *  I2O_EXEC_LCT_NOTIFY_MESSAGE  */
end_comment

begin_comment
comment|/*    I2O_MESSAGE_FRAME           StdMessageFrame; */
end_comment

begin_comment
comment|/*    I2O_TRANSACTION_CONTEXT     TransactionContext; */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_LCT_NOTIFY_MESSAGE_getClassIdentifier
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->ClassIdentifier),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_LCT_NOTIFY_MESSAGE_setClassIdentifier
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->ClassIdentifier),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_LCT_NOTIFY_MESSAGE_getLastReportedChangeIndicator
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->LastReportedChangeIndicator),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_LCT_NOTIFY_MESSAGE_setLastReportedChangeIndicator
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->LastReportedChangeIndicator),0,y)
end_define

begin_comment
comment|/*    I2O_SG_ELEMENT              SGL; */
end_comment

begin_comment
comment|/*  *  I2O_UTIL_PARAMS_GET_MESSAGE  */
end_comment

begin_comment
comment|/*     I2O_MESSAGE_FRAME          StdMessageFrame;	*/
end_comment

begin_comment
comment|/*     I2O_TRANSACTION_CONTEXT    TransactionContext;	*/
end_comment

begin_define
define|#
directive|define
name|I2O_UTIL_PARAMS_GET_MESSAGE_getOperationFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->OperationFlags),0)
end_define

begin_define
define|#
directive|define
name|I2O_UTIL_PARAMS_GET_MESSAGE_setOperationFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->OperationFlags),0,y)
end_define

begin_comment
comment|/*     I2O_SG_ELEMENT             SGL;			*/
end_comment

begin_comment
comment|/*  *  I2O_SCSI_SCB_ABORT_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_ABORT_MESSAGE_getStdMessageFramePtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->StdMessageFrame))
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_ABORT_MESSAGE_getTransactionContext
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->TransactionContext
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_ABORT_MESSAGE_setTransactionContext
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->TransactionContext = (y))
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_ABORT_MESSAGE_getTransactionContextToAbort
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->TransactionContextToAbort
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_ABORT_MESSAGE_setTransactionContextToAbort
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->TransactionContextToAbort = (y))
end_define

begin_comment
comment|/*  *  I2O_DPT_DEVICE_INFO_SCALAR  */
end_comment

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_getDeviceType
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->DeviceType),0)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_setDeviceType
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->DeviceType),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_getFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->Flags),0)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_setFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->Flags),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_getBus
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->Bus),0)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_setBus
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->Bus),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_getIdentifier
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->Identifier),0)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_setIdentifier
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->Identifier),0,y)
end_define

begin_comment
comment|/*     U8          LunInfo[8]; // SCSI-2 8-bit scalar LUN goes into offset 1 */
end_comment

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_getLunInfo
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->LunInfo[0]),1)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_DEVICE_INFO_SCALAR_setLunInfo
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->LunInfo[0]),1,y)
end_define

begin_comment
comment|/*  *       I2O_DPT_EXEC_IOP_BUFFERS_SCALAR  */
end_comment

begin_define
define|#
directive|define
name|I2O_DPT_EXEC_IOP_BUFFERS_SCALAR_getSerialOutputOffset
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->SerialOutputOffset),0)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_EXEC_IOP_BUFFERS_SCALAR_getSerialOutputSizet
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->SerialOutputSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_EXEC_IOP_BUFFERS_SCALAR_getSerialHeaderSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->SerialHeaderSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_DPT_EXEC_IOP_BUFFERS_SCALAR_getSerialFlagsSupported
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->SerialFlagsSupported),0)
end_define

begin_comment
comment|/*  *  I2O_PRIVATE_MESSAGE_FRAME  */
end_comment

begin_comment
comment|/* typedef struct _I2O_PRIVATE_MESSAGE_FRAME { */
end_comment

begin_comment
comment|/*    I2O_MESSAGE_FRAME           StdMessageFrame; */
end_comment

begin_comment
comment|/*    I2O_TRANSACTION_CONTEXT     TransactionContext; */
end_comment

begin_comment
comment|/*    U16                         XFunctionCode; */
end_comment

begin_comment
comment|/*    U16                         OrganizationID; */
end_comment

begin_comment
comment|/*                                PrivatePayload[]; */
end_comment

begin_comment
comment|/* } I2O_PRIVATE_MESSAGE_FRAME, *PI2O_PRIVATE_MESSAGE_FRAME; */
end_comment

begin_define
define|#
directive|define
name|I2O_PRIVATE_MESSAGE_FRAME_getTransactionContext
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->TransactionContext
end_define

begin_define
define|#
directive|define
name|I2O_PRIVATE_MESSAGE_FRAME_setTransactionContext
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->TransactionContext = (y))
end_define

begin_define
define|#
directive|define
name|I2O_PRIVATE_MESSAGE_FRAME_getXFunctionCode
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->XFunctionCode),0)
end_define

begin_define
define|#
directive|define
name|I2O_PRIVATE_MESSAGE_FRAME_setXFunctionCode
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->XFunctionCode),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_PRIVATE_MESSAGE_FRAME_getOrganizationID
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->OrganizationID),0)
end_define

begin_define
define|#
directive|define
name|I2O_PRIVATE_MESSAGE_FRAME_setOrganizationID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->OrganizationID),0,y)
end_define

begin_comment
comment|/* typedef struct _PRIVATE_SCSI_SCB_EXECUTE_MESSAGE {  *     I2O_PRIVATE_MESSAGE_FRAME PRIVATE_SCSI_SCB_EXECUTE_MESSAGE;  *     BF                        TID:16; // Upper four bits currently are zero  *     // Command is interpreted by the host  *     BF                        Interpret:1;  *     // if TRUE, deal with Physical Firmware Array information  *     BF                        Physical:1;  *     BF                        Reserved1:14;  *     U8                        CDBLength;  *     U8                        Reserved;  *     I2O_SCB_FLAGS             SCBFlags;  *     U8                        CDB[  I2O_SCSI_CDB_LENGTH=16  ];  *     U32                       ByteCount;  *     I2O_SG_ELEMENT            SGL;  * } PRIVATE_SCSI_SCB_EXECUTE_MESSAGE, * PPRIVATE_SCSI_SCB_EXECUTE_MESSAGE;  */
end_comment

begin_comment
comment|/*  *       PRIVATE_SCSI_SCB_EXECUTE_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getPRIVATE_SCSI_SCB_EXECUTE_MESSAGEPtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->PRIVATE_SCSI_SCB_EXECUTE_MESSAGE))
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getCDBLength
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->CDBLength),0)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_setCDBLength
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->CDBLength),0,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getReserved
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->Reserved),0)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_setReserved
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->Reserved),0,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getSCBFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->SCBFlags),0)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_setSCBFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->SCBFlags),0,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getByteCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->ByteCount)),0)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_setByteCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->ByteCount)),0,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getTID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get16bit(x,TID,0,TID)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_setTID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set16bit(x,TID,0,TID,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getInterpret
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get1bit(x,TID,2,Interpret)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_setInterpret
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set1bit(x,TID,2,Interpret,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getPhysical
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get1bit1(x,TID,2,Physical)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_setPhysical
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set1bit1(x,TID,2,Physical,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_SCSI_SCB_EXECUTE_MESSAGE_getCDBPtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->CDB[0]))
end_define

begin_comment
comment|/*  *  PRIVATE_FLASH_REGION_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_MESSAGE_getFlashRegion
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->FlashRegion)),0)
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_MESSAGE_setFlashRegion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->FlashRegion)),0,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_MESSAGE_getRegionOffset
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->RegionOffset)),0)
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_MESSAGE_setRegionOffset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->RegionOffset)),0,y)
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_MESSAGE_getByteCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->ByteCount)),0)
end_define

begin_define
define|#
directive|define
name|PRIVATE_FLASH_REGION_MESSAGE_setByteCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->ByteCount)),0,y)
end_define

begin_comment
comment|/*  *  I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR  */
end_comment

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getSCSIType
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->SCSIType),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setSCSIType
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->SCSIType),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getProtectionManagement
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->ProtectionManagement),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setProtectionManagement
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->ProtectionManagement),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getSettings
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->Settings),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setSettings
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->Settings),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getReserved1
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->Reserved1),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setReserved1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->Reserved1),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getInitiatorID
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->InitiatorID),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setInitiatorID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->InitiatorID),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getScanLun0Only
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->ScanLun0Only),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setScanLun0Only
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->ScanLun0Only),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getDisableDevice
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->DisableDevice),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setDisableDevice
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->DisableDevice),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getMaxOffset
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->MaxOffset),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setMaxOffset
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->MaxOffset),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getMaxDataWidth
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->MaxDataWidth),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setMaxDataWidth
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->MaxDataWidth),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_getMaxSyncRate
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->MaxSyncRate),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_SCSI_CONTROLLER_INFO_SCALAR_setMaxSyncRate
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->MaxSyncRate),0,y)
end_define

begin_comment
comment|/*  *  I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME  */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME_getStdReplyFramePtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->StdReplyFrame))
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME_getTransferCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->TransferCount),0)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME_setTransferCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->TransferCount),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME_getAutoSenseTransferCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->AutoSenseTransferCount),0)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_ERROR_REPLY_MESSAGE_FRAME_setAutoSenseTransferCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->AutoSenseTransferCount),0,y)
end_define

begin_comment
comment|/*  *  I2O_SINGLE_REPLY_MESSAGE_FRAME  */
end_comment

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_getStdMessageFramePtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->StdMessageFrame))
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_getTransactionContext
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->TransactionContext
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_setTransactionContext
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->TransactionContext = (y))
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_getDetailedStatusCode
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->DetailedStatusCode)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_setDetailedStatusCode
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&((x)->DetailedStatusCode)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_getreserved
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->reserved)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_setreserved
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&((x)->reserved)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_getReqStatus
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->ReqStatus)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SINGLE_REPLY_MESSAGE_FRAME_setReqStatus
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&((x)->ReqStatus)),0,y)
end_define

begin_comment
comment|/*  *  I2O_SCSI_SCB_EXECUTE_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_getStdMessageFramePtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->StdMessageFrame))
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_getTransactionContext
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->TransactionContext
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_setTransactionContext
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->TransactionContext = (y))
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_getCDBLength
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->CDBLength)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_setCDBLength
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&((x)->CDBLength)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_getReserved
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->Reserved)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_setReserved
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&((x)->Reserved)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_getSCBFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->SCBFlags)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_setSCBFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&((x)->SCBFlags)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_getByteCount
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&((x)->ByteCount)),0)
end_define

begin_define
define|#
directive|define
name|I2O_SCSI_SCB_EXECUTE_MESSAGE_setByteCount
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&((x)->ByteCount)),0,y)
end_define

begin_comment
comment|/*  define for these */
end_comment

begin_comment
comment|/*     U8                      CDB[16];	*/
end_comment

begin_comment
comment|/*     I2O_SG_ELEMENT          SGL;	*/
end_comment

begin_comment
comment|/*  *  I2O_FAILURE_REPLY_MESSAGE_FRAME  */
end_comment

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getStdMessageFramePtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->StdMessageFrame))
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getTransactionContext
parameter_list|(
name|x
parameter_list|)
define|\
value|(x)->TransactionContext
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_setTransactionContext
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((x)->TransactionContext = (y))
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getLowestVersion
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->LowestVersion)),0)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_setLowestVersion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&((x)->LowestVersion)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getHighestVersion
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&((x)->HighestVersion)),0)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_setHighestVersion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&((x)->HighestVersion)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getAgeLimit
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->AgeLimit)),0)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_setAgeLimit
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->AgeLimit)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getSeverity
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,Severity,0,Severity)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_setSeverity
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set8bit(x,Severity,0,Severity,y)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getFailureCode
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,Severity,1,FailureCode)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_setFailureCode
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_get8bit(x,Severity,1,FailureCode,y)
end_define

begin_comment
comment|/*  * #define I2O_FAILURE_REPLY_MESSAGE_FRAME_getFailingHostUnitID(x)\  *               _F_get16bit(x,reserved,1,FailingHostUnitID)  * #define I2O_FAILURE_REPLY_MESSAGE_FRAME_setFailingHostUnitID(x,y)\  *               _F_set16bit(x,reserved,1,FailingHostUnitID,y)  */
end_comment

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_getPreservedMFA
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&((x)->PreservedMFA)),0)
end_define

begin_define
define|#
directive|define
name|I2O_FAILURE_REPLY_MESSAGE_FRAME_setPreservedMFA
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&((x)->PreservedMFA)),0,y)
end_define

begin_comment
comment|/*  *  I2O_EXEC_STATUS_GET_REPLY  */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getOrganizationID
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->OrganizationID),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setOrganizationID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->OrganizationID),0,y)
end_define

begin_comment
comment|/* #define I2O_EXEC_STATUS_GET_REPLY_getreserved; */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getIOP_ID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,IOP_ID,0,IOP_ID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setIOP_ID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,IOP_ID,0,IOP_ID,y)
end_define

begin_comment
comment|/* #define I2O_EXEC_STATUS_GET_REPLY_getreserved1(x) */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getHostUnitID
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get16bit(x,IOP_ID,2,HostUnitID)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setHostUnitID
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set16bit(x,IOP_ID,2,HostUnitID,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getSegmentNumber
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get12bit(x,SegmentNumber,0,SegmentNumber)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setSegmentNumber
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set12bit(x,SegmentNumber,0,SegmentNumber,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getI2oVersion
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get4bit4(x,SegmentNumber,1,I2oVersion)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setI2oVersion
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set4bit4(x,SegmentNumber,1,I2oVersion,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getIopState
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,SegmentNumver,2,IopState)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setIopState
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_set8bit(x,SegmentNumver,2,IopState,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getMessengerType
parameter_list|(
name|x
parameter_list|)
define|\
value|_F_get8bit(x,SegmentNumber,3,MessengerType)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setMessengerType
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|_F_get8bit(x,SegmentNumber,3,MessengerType,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getInboundMFrameSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU2((&(x)->InboundMFrameSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setInboundMFrameSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU2((&(x)->InboundMFrameSize),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getInitCode
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->InitCode),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setInitCode
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->InitCode),0,y)
end_define

begin_comment
comment|/* #define I2O_EXEC_STATUS_GET_REPLY_getreserved2(x) */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getMaxInboundMFrames
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->MaxInboundMFrames),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setMaxInboundMFrames
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->MaxInboundMFrames),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getCurrentInboundMFrames
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->CurrentInboundMFrames),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setCurrentInboundMFrames
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->CurrentInboundMFrames),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getMaxOutboundMFrames
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->MaxOutboundMFrames),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setMaxOutboundMFrames
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->MaxOutboundMFrames),0,y)
end_define

begin_comment
comment|/* #define I2O_EXEC_STATUS_GET_REPLY_getProductIDString(x) */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getExpectedLCTSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->ExpectedLCTSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setExpectedLCTSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->ExpectedLCTSize),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getIopCapabilities
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->IopCapabilities),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setIopCapabilities
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->IopCapabilities),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getDesiredPrivateMemSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->DesiredPrivateMemSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setDesiredPrivateMemSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->DesiredPrivateMemSize),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getCurrentPrivateMemSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->CurrentPrivateMemSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setCurrentPrivateMemSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->CurrentPrivateMemSize),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getCurrentPrivateMemBase
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->CurrentPrivateMemBase),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setCurrentPrivateMemBase
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->CurrentPrivateMemBase),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getDesiredPrivateIOSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->DesiredPrivateIOSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setDesiredPrivateIOSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->DesiredPrivateIOSize),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getCurrentPrivateIOSize
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->CurrentPrivateIOSize),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setCurrentPrivateIOSize
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->CurrentPrivateIOSize),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getCurrentPrivateIOBase
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->CurrentPrivateIOBase),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setCurrentPrivateIOBase
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->CurrentPrivateIOBase),0,y)
end_define

begin_comment
comment|/* #define I2O_EXEC_STATUS_GET_REPLY_getreserved3(x) */
end_comment

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_getSyncByte
parameter_list|(
name|x
parameter_list|)
define|\
value|getU1((&(x)->SyncByte),0)
end_define

begin_define
define|#
directive|define
name|I2O_EXEC_STATUS_GET_REPLY_setSyncByte
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setU1((&(x)->SyncByte),0,y)
end_define

begin_comment
comment|/*  *  I2O_HBA_BUS_QUIESCE_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|I2O_HBA_BUS_QUIESCE_MESSAGE_getStdMessageFramePtr
parameter_list|(
name|x
parameter_list|)
define|\
value|(&((x)->StdMessageFrame))
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_QUIESCE_MESSAGE_getTransactionContext
parameter_list|(
name|x
parameter_list|)
define|\
value|getBU4((&((x)->TransactionContext)),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_QUIESCE_MESSAGE_setTransactionContext
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setBU4((&((x)->TransactionContext)),0,y)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_QUIESCE_MESSAGE_getFlags
parameter_list|(
name|x
parameter_list|)
define|\
value|getLU4((&(x)->Flags),0)
end_define

begin_define
define|#
directive|define
name|I2O_HBA_BUS_QUIESCE_MESSAGE_setFlags
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|setLU4((&(x)->Flags),0,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INCi2odeph */
end_comment

end_unit

