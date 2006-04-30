begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *	i4b_hdlc.h - software-HDLC header file  *	--------------------------------------  *  *	$Id: i4b_hdlc.h,v 1.5 2000/08/28 07:41:19 hm Exp $  *  * $FreeBSD$  *  *	last edit-date: [Thu Jan 11 11:31:01 2001]  *  *	Please conform "ihfc/i4b_ihfc_drv.c" (ihfc_hdlc_Bxxxx)  *	for correct usage! (-hp)  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_HDLC_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_HDLC_H_
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|u_short
name|HDLC_FCS_TAB
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|u_short
name|HDLC_BIT_TAB
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------------------------*  *	HDLC_DECODE  *	===========  *  *	u_char:  flag, blevel  *	u_short: crc, ib, tmp, tmp2, len  *  *	next: 'continue' or 'goto xxx'  *  *	cfr: complete frame  *	nfr: new frame  *	     NOTE: must setup 'len' and 'dst', so that 'dst' may be written  *		   at most 'len' times.  *  *	rab: abort  *	rdd: read data (read byte is stored in 'tmp2')  *	rdo: overflow  *  *	d: dummy  *  *	NOTE: setting flag to '0' and len to '0' => recover from rdu  *	NOTE: bits[8 .. ] of tmp2 may be used to store custom data/flags  *	NOTE: these variables have to be 'suspended' / 'resumed' somehow:  *		flag, blevel, crc, ib, tmp, len  *	NOTE: zero is default value for all variables.  *	NOTE: each time 'dst' is written, 'len' is decreased by one.  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|HDLC_DECODE
parameter_list|(
name|dst
parameter_list|,
name|len
parameter_list|,
name|tmp
parameter_list|,
name|tmp2
parameter_list|,
name|blevel
parameter_list|,
name|ib
parameter_list|,
name|crc
parameter_list|,
name|flag
parameter_list|,
name|rddcmd
parameter_list|,
name|nfrcmd
parameter_list|,	\
name|cfrcmd
parameter_list|,
name|rabcmd
parameter_list|,
name|rdocmd
parameter_list|,
name|nextcmd
parameter_list|,
name|d
parameter_list|)
define|\ 										\
value|rddcmd;									\ 										\ 	ib  += HDLC_BIT_TAB[(u_char)tmp2];					\ 										\ 	if ((u_char)ib>= 5)							\ 	{									\ 		if (ib& 0x20)
comment|/* de-stuff (msb) */
value|\ 		{								\ 			if ((u_char)tmp2 == 0x7e) goto j0##d;			\ 			tmp2 += tmp2& 0x7f;					\ 			blevel--;						\ 										\ 			if ((ib += 0x100)& 0xc) tmp2 |= 1;
comment|/* */
value|\ 		}								\ 										\ 		ib&= ~0xe0;							\ 										\ 		if ((u_char)ib == 6)
comment|/* flag seq (lsb) */
value|\ 		{								\ 		 j0##d:	if (flag>= 2)						\ 			{							\ 				len += (4 - flag)& 3;
comment|/* remove CRC bytes */
value|\ 				crc ^= 0xf0b8;					\ 				cfrcmd;						\ 				len = 0;					\ 			}							\ 										\ 			flag   = 1;						\ 										\ 			blevel = (ib>> 8)& 0xf;				\ 			tmp    = ((u_char)tmp2)>> blevel;			\ 			blevel = 8 - blevel;					\ 										\ 			ib>>= 12;						\ 										\ 			nextcmd;						\ 		}								\ 		if ((u_char)ib>= 7)
comment|/* abort (msb& lsb) */
value|\ 		{								\ 			if (flag>= 2)						\ 			{							\ 				rabcmd;						\ 				len = 0;					\ 			}							\ 										\ 			flag = 0;						\ 										\ 			ib>>= 12;						\ 										\ 			nextcmd;						\ 		}								\ 		if ((u_char)ib == 5)
comment|/* de-stuff (lsb) */
value|\ 		{								\ 			tmp2 = (tmp2 | (tmp2 + 1))& ~0x1;			\ 			blevel--;						\ 		}								\ 		if (blevel> 7)
comment|/* EO - bits */
value|\ 		{								\ 			tmp |= (u_char)tmp2>> (8 - (blevel&= 7));		\ 										\ 			ib>>= 12;						\ 										\ 			nextcmd;						\ 		}								\ 	}									\ 										\ 	tmp |= (u_char)tmp2<< blevel;						\ 										\ 	if (!len--)								\ 	{									\ 		len++;								\ 										\ 		if (!flag++) { flag--; goto j5##d;}
comment|/* hunt mode */
value|\ 										\ 		switch (flag)							\ 		{   case 2:
comment|/* new frame */
value|\ 			nfrcmd;							\ 			crc = -1;						\ 			if (!len--) { len++; flag++; goto j4##d; }		\ 			goto j3##d;						\ 		    case 3:
comment|/* CRC (lsb's) */
value|\ 		    case 4:
comment|/* CRC (msb's) */
value|\ 			goto j4##d;						\ 		    case 5:
comment|/* RDO */
value|\ 			rdocmd;							\ 			flag = 0;						\ 			break;							\ 		}								\ 	}									\ 	else									\ 	{ 									\ 	 j3##d:	dst = (u_char)tmp;						\ 	 j4##d: crc = (HDLC_FCS_TAB[(u_char)(tmp ^ crc)] ^ (u_char)(crc>> 8));	\ 	}									\ 										\  j5##d:	ib>>= 12;								\ 	tmp>>= 8;
end_define

begin_comment
unit|\
comment|/*------ end of HDLC_DECODE -------------------------------------------------*/
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------*  *	HDLC_ENCODE  *	===========  *  *	u_char:  flag, src  *	u_short: tmp2, blevel, ib, crc, len  *	u_int:   tmp  *  *	gfr: This is the place where you free the last [mbuf] chain, and get  *	     the next one. If a mbuf is available the code should setup 'len'  *	     and 'src' so that 'src' may be read 'len' times. If no mbuf is  *	     available leave 'len' and 'src' untouched.  *  *	nmb: If your implementation accept/use chained mbufs, this is the  *	     place where you update 'len' and 'src' to the next mbuf of  *	     the chain that makes up a frame. If no further mbuf is  *	     available leave 'len' and 'src' untouched. This is not the  *	     place where you free the mbuf. Leave the block empty if your  *	     implementation does not accept/use chained mbufs.  *  *	wrd: write data (output = (u_char)tmp)  *  *	d: dummy  *  *	NOTE: setting flag to '-2' and len to '0' => abort bytes will be sent  *	NOTE: these variables have to be 'suspended' / 'resumed' somehow:  *		flag, blevel, crc, ib, tmp, len  *	NOTE: zero is default value for all variables.  *	NOTE: each time 'src' is read, 'len' is decreased by one.  *	NOTE: neither cmd's should exit through 'goto' or 'break' statements.  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|HDLC_ENCODE
parameter_list|(
name|src
parameter_list|,
name|len
parameter_list|,
name|tmp
parameter_list|,
name|tmp2
parameter_list|,
name|blevel
parameter_list|,
name|ib
parameter_list|,
name|crc
parameter_list|,
name|flag
parameter_list|,
name|gfrcmd
parameter_list|,
name|nmbcmd
parameter_list|,
name|wrdcmd
parameter_list|,
name|d
parameter_list|)
define|\ 										\
value|if (blevel>= 0x800) { blevel -= 0x800; goto j4##d; }			\ 										\ 	if (!len--)								\ 	{									\ 		len++;								\ 										\ 		switch(++flag)							\ 		{ default:
comment|/* abort */
value|\ 			tmp  = blevel = 0;
comment|/* zero is default */
value|\ 			tmp2 = 0xff;						\ 			goto j3##d;						\ 		  case 1:
comment|/* 1st time FS */
value|\ 		  case 2:
comment|/* 2nd time FS */
value|\ 			tmp2 = 0x7e;						\ 			goto j3##d;						\ 		  case 3:							\ 			gfrcmd;
comment|/* get new frame */
value|\ 			if (!len--)						\ 			{							\ 				len++;						\ 				flag--;
comment|/* don't proceed */
value|\ 				tmp2 = 0x7e;					\ 				goto j3##d;
comment|/* final FS */
value|\ 			}							\ 			else							\ 			{							\ 				crc = -1;					\ 				ib  = 0;					\ 				goto j1##d;
comment|/* first byte */
value|\ 			}							\ 		  case 4:							\ 			nmbcmd;
comment|/* get next mbuf in chain */
value|\ 			if (!len--)						\ 			{							\ 				len++;						\ 				crc ^= -1;					\ 				tmp2 = (u_char)crc;				\ 				goto j2##d;
comment|/* CRC (lsb's) */
value|\ 			}							\ 			else							\ 			{							\ 				flag--;						\ 				goto j1##d;
comment|/* proceed with the frame */
value|\ 			}							\ 		  case 5:							\ 			tmp2  = (u_char)(crc>> 8);				\ 			flag  = 1;						\ 			goto j2##d;
comment|/* CRC (msb's) */
value|\ 		}								\ 	}									\  	else									\   	{ j1##d	:								\ 		tmp2 = (u_char)src;						\ 		crc =(HDLC_FCS_TAB[(u_char)(crc ^ tmp2)] ^ (u_char)(crc>> 8));	\ 	  j2##d:								\ 										\ 		ib>>= 12;							\ 		ib  += HDLC_BIT_TAB[(u_char)tmp2];				\ 										\ 		if ((u_char)ib>= 5)
comment|/* stuffing */
value|\ 		{								\ 			blevel&= ~0xff;					\ 										\ 			if (ib& 0xc0)
comment|/* bit stuff (msb) */
value|\ 			{							\ 				tmp2 += tmp2& (0xff * (ib& 0xc0));		\ 				ib %= 0x5000;					\ 				blevel++;					\ 			}							\ 										\ 			ib&= ~0xf0;						\ 										\ 			if ((u_char)ib>= 5)
comment|/* bit stuff (lsb) */
value|\ 			{							\ 				tmp2 += tmp2& ~0x1f>> ((ib - (ib>> 8) + 1)	\& 7);		\ 				blevel++;					\ 										\ 				if ((u_char)ib>= 10)
comment|/* bit stuff (msb) */
value|\ 				{						\ 					tmp2 += tmp2& ~0x7ff>> ((ib - 	\ 							(ib>> 8) + 1)& 7);	\ 					blevel++;				\ 				}						\ 				if (ib& 0x8000)
comment|/* bit walk */
value|\ 				{						\ 					ib = ((u_char)ib % 5)<< 12;		\ 				}						\ 			}							\ 										\ 			tmp    |= tmp2<< (u_char)(blevel>> 8);		\ 			blevel += (u_char)blevel<< 8;				\ 		}								\ 		else
comment|/* no stuffing */
value|\ 		{								\ 		  j3##d:tmp    |= tmp2<< (u_char)(blevel>> 8);		\ 		}								\ 	}									\ 										\  j4##d:	wrdcmd;									\ 	tmp>>= 8;
end_define

begin_comment
unit|\
comment|/*------ end of HDLC_ENCODE -------------------------------------------------*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_HDLC_H_ */
end_comment

end_unit

