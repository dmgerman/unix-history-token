begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996-1999 Distributed Processing Technology Corporation  * All rights reserved.  *  * Redistribution and use in source form, with or without modification, are  * permitted provided that redistributions of source code must retain the  * above copyright notice, this list of conditions and the following disclaimer.  *  * This software is provided `as is' by Distributed Processing Technology and  * any express or implied warranties, including, but not limited to, the  * implied warranties of merchantability and fitness for a particular purpose,  * are disclaimed. In no event shall Distributed Processing Technology be  * liable for any direct, indirect, incidental, special, exemplary or  * consequential damages (including, but not limited to, procurement of  * substitute goods or services; loss of use, data, or profits; or business  * interruptions) however caused and on any theory of liability, whether in  * contract, strict liability, or tort (including negligence or otherwise)  * arising in any way out of the use of x driver software, even if advised  * of the possibility of such damage.  *  * DPT Alignment Description File  *  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|__DPTALIGN_H
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|__DPTALIGN_H
end_define

begin_comment
comment|/*  *      File -  DPTALIGN.H  *  *      Description:  This file contains basic Alignment support definitions.  *  *      Copyright Distributed Processing Technology, Corp.  *        140 Candace Dr.  *        Maitland, Fl. 32751   USA  *        Phone: (407) 830-5522  Fax: (407) 260-5366  *        All Rights Reserved  *  *      Author: Mark Salyzyn  *      Date:   Aug 29 1996  *  *  *	Fifth Gen product enhancements and additions  *      Author: Ben Ghofrani  *      Date:   April 6 1998  */
end_comment

begin_comment
comment|/*  *      Description: Support macros for active alignment  *      Requires:  *              osdLocal2(x)  *              osdLocal4(x)  *              osdSwap2(x)  *              osdSwap4(x)  */
end_comment

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

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|)
operator|&&
operator|(
operator|!
name|defined
argument_list|(
name|_ILP32
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|DPT_4_BYTES
value|int
end_define

begin_comment
comment|/* 64 bit OS */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPT_4_BYTES
value|long
end_define

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
name|osdSwap2
argument_list|)
operator|)
end_if

begin_comment
comment|/*  *      Name: osdSwap2(value)  *      Description: Mandatory byte swapping routine for words. We allow an  *      override of x routine if the OS supplies it's own byte swapping  *      routine, inline or macro.  */
end_comment

begin_define
define|#
directive|define
name|osdSwap2
parameter_list|(
name|x
parameter_list|)
value|(((unsigned short)(x)>> 8) \                     | ((unsigned short)((unsigned char)(x))<< 8))
end_define

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
name|osdSwap4
argument_list|)
operator|)
end_if

begin_comment
comment|/*  *      Name: osdSwap4(value)  *      Description: Mandatory byte swapping routine for DPT_4_BYTES words. We allow  *      an override of x routine if the OS supplies it's own byte swapping  *      routine, inline or macro. The following is universal, but may be  *      more optimally performed by an OS or driver processor dependant  *      routine.  */
end_comment

begin_define
define|#
directive|define
name|osdSwap4
parameter_list|(
name|x
parameter_list|)
value|(                                                   \     (((unsigned DPT_4_BYTES)(x))>> 24L)                                            \   | ((unsigned DPT_4_BYTES)(((unsigned short)((unsigned DPT_4_BYTES)(x)>> 8L))& 0xFF00)) \   | (((unsigned DPT_4_BYTES)(((unsigned short)(x))& 0xFF00))<< 8L)                \   | (((unsigned DPT_4_BYTES)((unsigned char)(x)))<< 24L))
end_define

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
name|osdLocal2
argument_list|)
operator|)
end_if

begin_comment
comment|/*  *      Name: osdLocal2(pointer)  *      Description: Local byte order to Big Endian Format for short words.  *      Could be replaced with an OS defined localization routine, macro or  *      inline.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdLocal2
parameter_list|(
name|x
parameter_list|)
value|(*((unsigned short __FAR__ *)(x)))
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|osdSwap2
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdSLocal2
parameter_list|(
name|x
parameter_list|)
value|osdSwap2(osdLocal2(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|osdSLocal2
parameter_list|(
name|x
parameter_list|)
value|((unsigned short)(((unsigned char __FAR__ *)(x))[1])\                + ((unsigned int)((unsigned short)(((unsigned char __FAR__ *)(x))[0]))<< 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|osdSLocal2
parameter_list|(
name|x
parameter_list|)
value|(*((unsigned short __FAR__ *)(x)))
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|osdSwap2
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdLocal2
parameter_list|(
name|x
parameter_list|)
value|osdSwap2(osdSLocal2(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|osdLocal2
parameter_list|(
name|x
parameter_list|)
value|((unsigned short)(((unsigned char __FAR__*)(x))[1]) \                 + (((unsigned short)(((unsigned char __FAR__*)(x))[0]))<< 8))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|osdLocal3
argument_list|)
operator|)
end_if

begin_comment
comment|/*  *      Name: osdLocal3(pointer)  *      Description: Local byte order to Big Endian Format for DPT_4_BYTES words.  *      Could be replaced with an OS defined localization routine, macro or  *      inline.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdLocal3
parameter_list|(
name|x
parameter_list|)
value|(*((unsigned DPT_4_BYTES __FAR__ *)(x)))
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|osdSwap3
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdLocal3
parameter_list|(
name|x
parameter_list|)
value|osdSwap3(*((unsigned DPT_4_BYTES __FAR__ *)(x)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|osdLocal3
parameter_list|(
name|x
parameter_list|)
value|((unsigned DPT_4_BYTES)osdLocal2(((unsigned char __FAR__ *) \        (x)+1)) + (((unsigned DPT_4_BYTES)(((unsigned char __FAR__ *)(x))[0]))<< 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|osdLocal4
argument_list|)
operator|)
end_if

begin_comment
comment|/*  *      Name: osdLocal4(pointer)  *      Description: Local byte order to Big Endian Format for DPT_4_BYTES words.  *      Could be replaced with an OS defined localization routine, macro or  *      inline.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdLocal4
parameter_list|(
name|x
parameter_list|)
value|(*(unsigned DPT_4_BYTES __FAR__ *)(x))
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|osdSwap4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdSLocal4
parameter_list|(
name|x
parameter_list|)
value|osdSwap4(osdLocal4(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|osdSLocal4
parameter_list|(
name|x
parameter_list|)
value|((unsigned DPT_4_BYTES)osdSLocal2(((unsigned char __FAR__ *)\     (x)+2)) + (((unsigned DPT_4_BYTES)((unsigned char __FAR__ *)(x))[1])<< 16) \             + (((unsigned DPT_4_BYTES)((unsigned char __FAR__ *)(x))[0])<< 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|osdSLocal4
parameter_list|(
name|x
parameter_list|)
value|(*(unsigned DPT_4_BYTES __FAR__ *)(x))
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|osdSwap4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|osdLocal4
parameter_list|(
name|x
parameter_list|)
value|osdSwap4(osdSLocal4(x))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|osdLocal4
parameter_list|(
name|x
parameter_list|)
value|((unsigned DPT_4_BYTES)osdLocal2(((unsigned char __FAR__ *) \         (x)+2)) + (((unsigned DPT_4_BYTES)((unsigned char __FAR__ *)(x))[1])<< 16) \                 + (((unsigned DPT_4_BYTES)((unsigned char __FAR__ *)(x))[0])<< 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|I2O_TID_MASK
value|((unsigned DPT_4_BYTES) ((1L<<I2O_TID_SZ)-1))
end_define

begin_comment
comment|/*  *      Now the access macros used throughout in order to methodize the  * active alignment.  */
end_comment

begin_define
define|#
directive|define
name|getUP1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((unsigned char __FAR__ *)(x))+(unsigned DPT_4_BYTES)(y))
end_define

begin_define
define|#
directive|define
name|getU1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(*getUP1(x,y))
end_define

begin_define
define|#
directive|define
name|setU1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(*((unsigned char *)getUP1(x,y)) = (unsigned char)(z))
end_define

begin_define
define|#
directive|define
name|orU1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(*getUP1(x,y) |= (unsigned char)(z))
end_define

begin_define
define|#
directive|define
name|andU1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(*getUP1(x,y)&= (unsigned char)(z))
end_define

begin_define
define|#
directive|define
name|getUP2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short __FAR__ *)(((unsigned char __FAR__ *) \                                 (x))+(unsigned DPT_4_BYTES)(y)))
end_define

begin_define
define|#
directive|define
name|getBU2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short)osdLocal2((unsigned short __FAR__ *)  \                                 getUP1(x,y)))
end_define

begin_define
define|#
directive|define
name|getLU2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short)osdSLocal2((unsigned short __FAR__ *) \                                 getUP1(x,y)))
end_define

begin_comment
comment|/* to be deleted  */
end_comment

begin_define
define|#
directive|define
name|getU2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short)osdLocal2((unsigned short __FAR__ *)  \                                 getUP1(x,y)))
end_define

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|setU2
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setU2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ unsigned short hold = (unsigned short)(z);  \                         *((unsigned short __FAR__ *)getUP1(x,y))    \                           = osdLocal2(&hold);                       \                       }
end_define

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
name|setBU2
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setBU2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ unsigned short hold = (unsigned short)(z);  \                         *((unsigned short __FAR__ *)getUP1(x,y))    \                           = osdLocal2(&hold);                       \                       }
end_define

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
name|setLU2
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setLU2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ unsigned short hold = (unsigned short)(z); \                          *((unsigned short __FAR__ *)getUP1(x,y))   \                            = osdSLocal2(&hold);                     \                        }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* to be deleted */
end_comment

begin_define
define|#
directive|define
name|getU3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned DPT_4_BYTES)osdLocal3((unsigned DPT_4_BYTES __FAR__ *) \                                 getUP1(x,y)))
end_define

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|setU3
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setU3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{   unsigned DPT_4_BYTES hold = z;                        \             *(getUP1(x,y)) = (unsigned char)(hold>> 16L); \             *((unsigned short __FAR__ *)(getUP1(x,y) + 1)) \               = (unsigned short)hold;                      \         }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|setU3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{   unsigned DPT_4_BYTES hold = z;                            \             *(getUP1(x,y) + 0) = (unsigned char)(hold>> 16) ; \             *(getUP1(x,y) + 1) = (unsigned char)(hold>> 8L);  \             *(getUP1(x,y) + 2) = (unsigned char)(hold);        \         }
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
comment|/* up to here to be deleted */
end_comment

begin_define
define|#
directive|define
name|getBU3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned DPT_4_BYTES)osdLocal3((unsigned DPT_4_BYTES __FAR__ *) \                                 getUP1(x,y)))
end_define

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|setBU3
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_DPT_BIG_ENDIAN
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setBU3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{   unsigned DPT_4_BYTES hold = z;                        \             *(getUP1(x,y)) = (unsigned char)(hold>> 16L); \             *((unsigned short __FAR__ *)(getUP1(x,y) + 1)) \               = (unsigned short)hold;                      \         }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|setBU3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
define|\
value|{   unsigned DPT_4_BYTES hold = z;                            \             *(getUP1(x,y) + 0) = (unsigned char)(hold>> 16) ; \             *(getUP1(x,y) + 1) = (unsigned char)(hold>> 8L);  \             *(getUP1(x,y) + 2) = (unsigned char)(hold);        \         }
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
name|getUP4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned DPT_4_BYTES __FAR__ *)(((unsigned char __FAR__ *) \                                 (x))+(unsigned DPT_4_BYTES)(y)))
end_define

begin_define
define|#
directive|define
name|getBU4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned DPT_4_BYTES)osdLocal4((unsigned DPT_4_BYTES __FAR__ *)   \                                 getUP1(x,y)))
end_define

begin_define
define|#
directive|define
name|getLU4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned DPT_4_BYTES)osdSLocal4((unsigned DPT_4_BYTES __FAR__ *)  \                                 getUP1(x,y)))
end_define

begin_comment
comment|/* to be deleted */
end_comment

begin_define
define|#
directive|define
name|getU4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned DPT_4_BYTES)osdSLocal4((unsigned DPT_4_BYTES __FAR__ *)  \                                 getUP1(x,y)))
end_define

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|setU4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setU4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ unsigned DPT_4_BYTES hold = z;                 \                         *((unsigned DPT_4_BYTES __FAR__ *)getUP1(x,y)) \                           = osdLocal4(&hold);                   \                       }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* up to here */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|setBU4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setBU4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ unsigned DPT_4_BYTES hold = z;                 \                         *((unsigned DPT_4_BYTES __FAR__ *)getUP1(x,y)) \                           = osdLocal4(&hold);                   \                       }
end_define

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
name|setLU4
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|setLU4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ unsigned DPT_4_BYTES hold = z;                 \                          *((unsigned DPT_4_BYTES __FAR__ *)getUP1(x,y)) \                            = osdSLocal4(&hold);                  \                        }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|osdSwap16bit
parameter_list|(
name|x
parameter_list|)
value|( (((unsigned short )x& 0xf000)>> 12) | \ 			  (((unsigned short )x& 0x0f00)>> 4) | \ 			  (((unsigned short )x& 0x00f0)<< 4)  | \ 			  (((unsigned short )x& 0x000f)<< 12 )   )
end_define

begin_comment
comment|/*  * note that in big endian a 12 bit number (0x123) is stored as   1203  */
end_comment

begin_define
define|#
directive|define
name|osdSwap12bit
parameter_list|(
name|x
parameter_list|)
value|(( (((unsigned short )x& 0x0f00)>> 8) | \ 			((unsigned short )x& 0x00f0)  | \ 			(((unsigned short )x& 0x000f)<< 8 )  ) )
end_define

begin_define
define|#
directive|define
name|osdSwap8bit
parameter_list|(
name|x
parameter_list|)
value|( (((unsigned char )x& 0x0f)<< 4) | \ 			(((unsigned char )x&0xf0)>> 4 ) )
end_define

begin_define
define|#
directive|define
name|getL24bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned DPT_4_BYTES)((unsigned char __FAR__ *)(&w->x))[0+(y)] \ 			+ ((((unsigned DPT_4_BYTES)((unsigned char __FAR__ *)(&w->x))[1+(y)])<< 8)& 0xFF00) \ 			+ ((((unsigned DPT_4_BYTES)((unsigned char __FAR__ *)(&w->x))[2+(y)])<< 16)& 0xFF0000))
end_define

begin_define
define|#
directive|define
name|setL24bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ ((unsigned char __FAR__ *)(&w->x))[0+(y)] = (z); \ 			   ((unsigned char __FAR__ *)(&w->x))[1+(y)] = ((z)>> 8)& 0xFF; \ 			   ((unsigned char __FAR__ *)(&w->x))[2+(y)] = ((z)>> 16)& 0xFF; \ 			   }
end_define

begin_define
define|#
directive|define
name|getL16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short)((unsigned char __FAR__ *)(&w->x))[0+(y)] \ 			 + ((((unsigned short)((unsigned char __FAR__ *)(&w->x))[1+(y)])<< 8)& 0xFF00))
end_define

begin_define
define|#
directive|define
name|setL16bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ ((unsigned char __FAR__ *)(&w->x))[0+(y)] = (z); \ 			   ((unsigned char __FAR__ *)(&w->x))[1+(y)] = ((z)>> 8)& 0xFF; \ 			   }
end_define

begin_define
define|#
directive|define
name|getL16bit2
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short)((unsigned char __FAR__ *)(&w->x))[2+(y)] \ 			 + ((((unsigned short)((unsigned char __FAR__ *)(&w->x))[3+(y)])<< 8)& 0xFF00))
end_define

begin_define
define|#
directive|define
name|setL16bit2
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ ((unsigned char __FAR__ *)(&w->x))[2+(y)] = (z); \ 			   ((unsigned char __FAR__ *)(&w->x))[3+(y)] = ((z)>> 8)& 0xFF; \ 			   }
end_define

begin_comment
comment|/* y is the number of bytes from beg of DPT_4_BYTES to get upper 4 bit of the addressed byte */
end_comment

begin_define
define|#
directive|define
name|getL4bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((unsigned char)(((unsigned char __FAR__ *)(&w->x))[0+(y)]>> 4)& 0x0f)
end_define

begin_define
define|#
directive|define
name|setL4bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ \ 			   ((unsigned char __FAR__ *)(&w->x))[0+(y)]&= 0xF0; \ 				((unsigned char __FAR__ *)(&w->x))[0+(y)] |= ((z)<< 4)& 0xF0; \ 				}
end_define

begin_comment
comment|/* y is number of bytes from beg of DPT_4_BYTES */
end_comment

begin_define
define|#
directive|define
name|getL1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((unsigned char)(((unsigned char __FAR__ *)(&w->x))[0+(y)] )& 0x01)
end_define

begin_define
define|#
directive|define
name|setL1bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ \ 			   ((unsigned char __FAR__ *)(&w->x))[0+(y)]&= 0xFE; \ 				((unsigned char __FAR__ *)(&w->x))[0+(y)] |= (z)& 0x01; \ 				}
end_define

begin_define
define|#
directive|define
name|getL1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((unsigned char)(((unsigned char __FAR__ *)(&w->x))[0+(y)]>> 1)& 0x01)
end_define

begin_define
define|#
directive|define
name|setL1bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ \ 			   ((unsigned char __FAR__ *)(&w->x))[0+(y)]&= 0xFD; \ 				((unsigned char __FAR__ *)(&w->x))[0+(y)] |= (z<< 1)& 0x02; \ 				}
end_define

begin_comment
comment|/* 12 bit at the first 12 bits of a DPT_4_BYTES word */
end_comment

begin_define
define|#
directive|define
name|getL12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short)((unsigned char __FAR__ *)(&w->x))[0+(y)] \ 			 + ((((unsigned short)((unsigned char __FAR__ *)(&w->x))[1+(y)])<< 8)& 0xF00))
end_define

begin_define
define|#
directive|define
name|setL12bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ ((unsigned char __FAR__ *)(&w->x))[0+(y)] = (z); \ 			   ((unsigned char __FAR__ *)(&w->x))[1+(y)]&= 0xF0; \ 			   ((unsigned char __FAR__ *)(&w->x))[1+(y)] |= ((z)>> 8)& 0xF; \ 			   }
end_define

begin_comment
comment|/* 12 bit after another 12 bit in DPT_4_BYTES word */
end_comment

begin_define
define|#
directive|define
name|getL12bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(((unsigned short)((unsigned char __FAR__ *)(&w->x))[1+(y)])>> 4 \ 			 + ((((unsigned short)((unsigned char __FAR__ *)(&w->x))[2+(y)])<< 4) ))
end_define

begin_define
define|#
directive|define
name|setL12bit1
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ ((unsigned char __FAR__ *)(&w->x))[1+(y)]&= 0x0F; \ 			   ((unsigned char __FAR__ *)(&w->x))[1+(y)] |= ((z)& 0xF)<< 4; \ 			   ((unsigned char __FAR__ *)(&w->x))[2+(y)]&= 0x00;\ 			   ((unsigned char __FAR__ *)(&w->x))[2+(y)] |= ((z)>> 8)& 0xff;\ 			   }
end_define

begin_comment
comment|/* 12 at the 3rd byte in a DPT_4_BYTES word */
end_comment

begin_define
define|#
directive|define
name|getL12bit2
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|((unsigned short)((unsigned char __FAR__ *)(&w->x))[2+(y)] \ 			 + ((((unsigned short)((unsigned char __FAR__ *)(&w->x))[3+(y)])<< 8)& 0xF00))
end_define

begin_define
define|#
directive|define
name|setL12bit2
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{ ((unsigned char __FAR__ *)(&w->x))[2+(y)] = (z); \ 			   ((unsigned char __FAR__ *)(&w->x))[3+(y)]&= 0xF0; \ 			   ((unsigned char __FAR__ *)(&w->x))[3+(y)] |= ((z)>> 8)& 0xF; \ 			   }
end_define

begin_define
define|#
directive|define
name|getL8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|(\ 	(*(((unsigned char __FAR__ *)(&((w)->x)))\ 		+ y)) )
end_define

begin_define
define|#
directive|define
name|setL8bit
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|{\ 	(*(((unsigned char __FAR__ *)(&((w)->x)))\ 		+ y) = (z));\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DPTALIGN_H */
end_comment

end_unit

