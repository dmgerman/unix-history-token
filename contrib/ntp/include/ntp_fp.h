begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_fp.h - definitions for NTP fixed/floating-point arithmetic  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_FP_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_FP_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/*  * NTP uses two fixed point formats.  The first (l_fp) is the "long"  * format and is 64 bits long with the decimal between bits 31 and 32.  * This is used for time stamps in the NTP packet header (in network  * byte order) and for internal computations of offsets (in local host  * byte order). We use the same structure for both signed and unsigned  * values, which is a big hack but saves rewriting all the operators  * twice. Just to confuse this, we also sometimes just carry the  * fractional part in calculations, in both signed and unsigned forms.  * Anyway, an l_fp looks like:  *  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			       Integral Part			     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			       Fractional Part			     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
name|u_int32
name|Xl_ui
decl_stmt|;
name|int32
name|Xl_i
decl_stmt|;
block|}
name|Ul_i
union|;
union|union
block|{
name|u_int32
name|Xl_uf
decl_stmt|;
name|int32
name|Xl_f
decl_stmt|;
block|}
name|Ul_f
union|;
block|}
name|l_fp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|l_ui
value|Ul_i.Xl_ui
end_define

begin_comment
comment|/* unsigned integral part */
end_comment

begin_define
define|#
directive|define
name|l_i
value|Ul_i.Xl_i
end_define

begin_comment
comment|/* signed integral part */
end_comment

begin_define
define|#
directive|define
name|l_uf
value|Ul_f.Xl_uf
end_define

begin_comment
comment|/* unsigned fractional part */
end_comment

begin_define
define|#
directive|define
name|l_f
value|Ul_f.Xl_f
end_define

begin_comment
comment|/* signed fractional part */
end_comment

begin_comment
comment|/*  * Fractional precision (of an l_fp) is actually the number of  * bits in a long.  */
end_comment

begin_define
define|#
directive|define
name|FRACTION_PREC
value|(32)
end_define

begin_comment
comment|/*  * The second fixed point format is 32 bits, with the decimal between  * bits 15 and 16.  There is a signed version (s_fp) and an unsigned  * version (u_fp).  This is used to represent synchronizing distance  * and synchronizing dispersion in the NTP packet header (again, in  * network byte order) and internally to hold both distance and  * dispersion values (in local byte order).  In network byte order  * it looks like:  *  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |		  Integer Part	     |	   Fraction Part	     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  */
end_comment

begin_typedef
typedef|typedef
name|int32
name|s_fp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32
name|u_fp
typedef|;
end_typedef

begin_comment
comment|/*  * A unit second in fp format.  Actually 2**(half_the_bits_in_a_long)  */
end_comment

begin_define
define|#
directive|define
name|FP_SECOND
value|(0x10000)
end_define

begin_comment
comment|/*  * Byte order conversions  */
end_comment

begin_define
define|#
directive|define
name|HTONS_FP
parameter_list|(
name|x
parameter_list|)
value|(htonl(x))
end_define

begin_define
define|#
directive|define
name|HTONL_FP
parameter_list|(
name|h
parameter_list|,
name|n
parameter_list|)
value|do { (n)->l_ui = htonl((h)->l_ui); \ 			     (n)->l_uf = htonl((h)->l_uf); } while (0)
end_define

begin_define
define|#
directive|define
name|NTOHS_FP
parameter_list|(
name|x
parameter_list|)
value|(ntohl(x))
end_define

begin_define
define|#
directive|define
name|NTOHL_FP
parameter_list|(
name|n
parameter_list|,
name|h
parameter_list|)
value|do { (h)->l_ui = ntohl((n)->l_ui); \ 			     (h)->l_uf = ntohl((n)->l_uf); } while (0)
end_define

begin_define
define|#
directive|define
name|NTOHL_MFP
parameter_list|(
name|ni
parameter_list|,
name|nf
parameter_list|,
name|hi
parameter_list|,
name|hf
parameter_list|)
define|\
value|do { (hi) = ntohl(ni); (hf) = ntohl(nf); } while (0)
end_define

begin_define
define|#
directive|define
name|HTONL_MFP
parameter_list|(
name|hi
parameter_list|,
name|hf
parameter_list|,
name|ni
parameter_list|,
name|nf
parameter_list|)
define|\
value|do { (ni) = ntohl(hi); (nf) = ntohl(hf); } while (0)
end_define

begin_comment
comment|/* funny ones.  Converts ts fractions to net order ts */
end_comment

begin_define
define|#
directive|define
name|HTONL_UF
parameter_list|(
name|uf
parameter_list|,
name|nts
parameter_list|)
define|\
value|do { (nts)->l_ui = 0; (nts)->l_uf = htonl(uf); } while (0)
end_define

begin_define
define|#
directive|define
name|HTONL_F
parameter_list|(
name|f
parameter_list|,
name|nts
parameter_list|)
value|do { (nts)->l_uf = htonl(f); \ 				if ((f)& 0x80000000) \ 					(nts)->l_i = -1; \ 				else \ 					(nts)->l_i = 0; \ 			} while (0)
end_define

begin_comment
comment|/*  * Conversions between the two fixed point types  */
end_comment

begin_define
define|#
directive|define
name|MFPTOFP
parameter_list|(
name|x_i
parameter_list|,
name|x_f
parameter_list|)
value|(((x_i)>= 0x00010000) ? 0x7fffffff : \ 				(((x_i)<= -0x00010000) ? 0x80000000 : \ 				(((x_i)<<16) | (((x_f)>>16)&0xffff))))
end_define

begin_define
define|#
directive|define
name|LFPTOFP
parameter_list|(
name|v
parameter_list|)
value|MFPTOFP((v)->l_i, (v)->l_f)
end_define

begin_define
define|#
directive|define
name|UFPTOLFP
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|((v)->l_ui = (u_fp)(x)>>16, (v)->l_uf = (x)<<16)
end_define

begin_define
define|#
directive|define
name|FPTOLFP
parameter_list|(
name|x
parameter_list|,
name|v
parameter_list|)
value|(UFPTOLFP((x), (v)), (x)< 0 ? (v)->l_ui -= 0x10000 : 0)
end_define

begin_define
define|#
directive|define
name|MAXLFP
parameter_list|(
name|v
parameter_list|)
value|((v)->l_ui = 0x7fffffff, (v)->l_uf = 0xffffffff)
end_define

begin_define
define|#
directive|define
name|MINLFP
parameter_list|(
name|v
parameter_list|)
value|((v)->l_ui = 0x80000000, (v)->l_uf = 0)
end_define

begin_comment
comment|/*  * Primitive operations on long fixed point values.  If these are  * reminiscent of assembler op codes it's only because some may  * be replaced by inline assembler for particular machines someday.  * These are the (kind of inefficient) run-anywhere versions.  */
end_comment

begin_define
define|#
directive|define
name|M_NEG
parameter_list|(
name|v_i
parameter_list|,
name|v_f
parameter_list|)
comment|/* v = -v */
define|\
value|do { \ 		if ((v_f) == 0) \ 			(v_i) = -((s_fp)(v_i)); \ 		else { \ 			(v_f) = -((s_fp)(v_f)); \ 			(v_i) = ~(v_i); \ 		} \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|M_NEGM
parameter_list|(
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|a_i
parameter_list|,
name|a_f
parameter_list|)
comment|/* r = -a */
define|\
value|do { \ 		if ((a_f) == 0) { \ 			(r_f) = 0; \ 			(r_i) = -(a_i); \ 		} else { \ 			(r_f) = -(a_f); \ 			(r_i) = ~(a_i); \ 		} \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|M_ADD
parameter_list|(
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|a_i
parameter_list|,
name|a_f
parameter_list|)
comment|/* r += a */
define|\
value|do { \ 		register u_int32 lo_tmp; \ 		register u_int32 hi_tmp; \ 		\ 		lo_tmp = ((r_f)& 0xffff) + ((a_f)& 0xffff); \ 		hi_tmp = (((r_f)>> 16)& 0xffff) + (((a_f)>> 16)& 0xffff); \ 		if (lo_tmp& 0x10000) \ 			hi_tmp++; \ 		(r_f) = ((hi_tmp& 0xffff)<< 16) | (lo_tmp& 0xffff); \ 		\ 		(r_i) += (a_i); \ 		if (hi_tmp& 0x10000) \ 			(r_i)++; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_ADD3
parameter_list|(
name|r_ovr
parameter_list|,
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|a_ovr
parameter_list|,
name|a_i
parameter_list|,
name|a_f
parameter_list|)
comment|/* r += a, three word */
define|\
value|do { \ 		register u_int32 lo_tmp; \ 		register u_int32 hi_tmp; \ 		\ 		lo_tmp = ((r_f)& 0xffff) + ((a_f)& 0xffff); \ 		hi_tmp = (((r_f)>> 16)& 0xffff) + (((a_f)>> 16)& 0xffff); \ 		if (lo_tmp& 0x10000) \ 			hi_tmp++; \ 		(r_f) = ((hi_tmp& 0xffff)<< 16) | (lo_tmp& 0xffff); \ 		\ 		lo_tmp = ((r_i)& 0xffff) + ((a_i)& 0xffff); \ 		if (hi_tmp& 0x10000) \ 			lo_tmp++; \ 		hi_tmp = (((r_i)>> 16)& 0xffff) + (((a_i)>> 16)& 0xffff); \ 		if (lo_tmp& 0x10000) \ 			hi_tmp++; \ 		(r_i) = ((hi_tmp& 0xffff)<< 16) | (lo_tmp& 0xffff); \ 		\ 		(r_ovr) += (a_ovr); \ 		if (hi_tmp& 0x10000) \ 			(r_ovr)++; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_SUB
parameter_list|(
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|a_i
parameter_list|,
name|a_f
parameter_list|)
comment|/* r -= a */
define|\
value|do { \ 		register u_int32 lo_tmp; \ 		register u_int32 hi_tmp; \ 		\ 		if ((a_f) == 0) { \ 			(r_i) -= (a_i); \ 		} else { \ 			lo_tmp = ((r_f)& 0xffff) + ((-((s_fp)(a_f)))& 0xffff); \ 			hi_tmp = (((r_f)>> 16)& 0xffff) \ 			    + (((-((s_fp)(a_f)))>> 16)& 0xffff); \ 			if (lo_tmp& 0x10000) \ 				hi_tmp++; \ 			(r_f) = ((hi_tmp& 0xffff)<< 16) | (lo_tmp& 0xffff); \ 			\ 			(r_i) += ~(a_i); \ 			if (hi_tmp& 0x10000) \ 				(r_i)++; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_RSHIFTU
parameter_list|(
name|v_i
parameter_list|,
name|v_f
parameter_list|)
comment|/* v>>= 1, v is unsigned */
define|\
value|do { \ 		(v_f) = (u_int32)(v_f)>> 1; \ 		if ((v_i)& 01) \ 			(v_f) |= 0x80000000; \ 		(v_i) = (u_int32)(v_i)>> 1; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_RSHIFT
parameter_list|(
name|v_i
parameter_list|,
name|v_f
parameter_list|)
comment|/* v>>= 1, v is signed */
define|\
value|do { \ 		(v_f) = (u_int32)(v_f)>> 1; \ 		if ((v_i)& 01) \ 			(v_f) |= 0x80000000; \ 		if ((v_i)& 0x80000000) \ 			(v_i) = ((v_i)>> 1) | 0x80000000; \ 		else \ 			(v_i) = (v_i)>> 1; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_LSHIFT
parameter_list|(
name|v_i
parameter_list|,
name|v_f
parameter_list|)
comment|/* v<<= 1 */
define|\
value|do { \ 		(v_i)<<= 1; \ 		if ((v_f)& 0x80000000) \ 			(v_i) |= 0x1; \ 		(v_f)<<= 1; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_LSHIFT3
parameter_list|(
name|v_ovr
parameter_list|,
name|v_i
parameter_list|,
name|v_f
parameter_list|)
comment|/* v<<= 1, with overflow */
define|\
value|do { \ 		(v_ovr)<<= 1; \ 		if ((v_i)& 0x80000000) \ 			(v_ovr) |= 0x1; \ 		(v_i)<<= 1; \ 		if ((v_f)& 0x80000000) \ 			(v_i) |= 0x1; \ 		(v_f)<<= 1; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_ADDUF
parameter_list|(
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|uf
parameter_list|)
comment|/* r += uf, uf is u_int32 fraction */
define|\
value|M_ADD((r_i), (r_f), 0, (uf))
end_define

begin_comment
comment|/* let optimizer worry about it */
end_comment

begin_define
define|#
directive|define
name|M_SUBUF
parameter_list|(
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|uf
parameter_list|)
comment|/* r -= uf, uf is u_int32 fraction */
define|\
value|M_SUB((r_i), (r_f), 0, (uf))
end_define

begin_comment
comment|/* let optimizer worry about it */
end_comment

begin_define
define|#
directive|define
name|M_ADDF
parameter_list|(
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|f
parameter_list|)
comment|/* r += f, f is a int32 fraction */
define|\
value|do { \ 		if ((f)> 0) \ 			M_ADD((r_i), (r_f), 0, (f)); \ 		else if ((f)< 0) \ 			M_ADD((r_i), (r_f), (-1), (f));\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|M_ISNEG
parameter_list|(
name|v_i
parameter_list|,
name|v_f
parameter_list|)
comment|/* v< 0 */
define|\
value|(((v_i)& 0x80000000) != 0)
end_define

begin_define
define|#
directive|define
name|M_ISHIS
parameter_list|(
name|a_i
parameter_list|,
name|a_f
parameter_list|,
name|b_i
parameter_list|,
name|b_f
parameter_list|)
comment|/* a>= b unsigned */
define|\
value|(((u_int32)(a_i))> ((u_int32)(b_i)) || \ 	  ((a_i) == (b_i)&& ((u_int32)(a_f))>= ((u_int32)(b_f))))
end_define

begin_define
define|#
directive|define
name|M_ISGEQ
parameter_list|(
name|a_i
parameter_list|,
name|a_f
parameter_list|,
name|b_i
parameter_list|,
name|b_f
parameter_list|)
comment|/* a>= b signed */
define|\
value|(((int32)(a_i))> ((int32)(b_i)) || \ 	  ((a_i) == (b_i)&& ((u_int32)(a_f))>= ((u_int32)(b_f))))
end_define

begin_define
define|#
directive|define
name|M_ISEQU
parameter_list|(
name|a_i
parameter_list|,
name|a_f
parameter_list|,
name|b_i
parameter_list|,
name|b_f
parameter_list|)
comment|/* a == b unsigned */
define|\
value|((a_i) == (b_i)&& (a_f) == (b_f))
end_define

begin_comment
comment|/*  * Operations on the long fp format  */
end_comment

begin_define
define|#
directive|define
name|L_ADD
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|)
value|M_ADD((r)->l_ui, (r)->l_uf, (a)->l_ui, (a)->l_uf)
end_define

begin_define
define|#
directive|define
name|L_SUB
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|)
value|M_SUB((r)->l_ui, (r)->l_uf, (a)->l_ui, (a)->l_uf)
end_define

begin_define
define|#
directive|define
name|L_NEG
parameter_list|(
name|v
parameter_list|)
value|M_NEG((v)->l_ui, (v)->l_uf)
end_define

begin_define
define|#
directive|define
name|L_ADDUF
parameter_list|(
name|r
parameter_list|,
name|uf
parameter_list|)
value|M_ADDUF((r)->l_ui, (r)->l_uf, (uf))
end_define

begin_define
define|#
directive|define
name|L_SUBUF
parameter_list|(
name|r
parameter_list|,
name|uf
parameter_list|)
value|M_SUBUF((r)->l_ui, (r)->l_uf, (uf))
end_define

begin_define
define|#
directive|define
name|L_ADDF
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|)
value|M_ADDF((r)->l_ui, (r)->l_uf, (f))
end_define

begin_define
define|#
directive|define
name|L_RSHIFT
parameter_list|(
name|v
parameter_list|)
value|M_RSHIFT((v)->l_i, (v)->l_uf)
end_define

begin_define
define|#
directive|define
name|L_RSHIFTU
parameter_list|(
name|v
parameter_list|)
value|M_RSHIFT((v)->l_ui, (v)->l_uf)
end_define

begin_define
define|#
directive|define
name|L_LSHIFT
parameter_list|(
name|v
parameter_list|)
value|M_LSHIFT((v)->l_ui, (v)->l_uf)
end_define

begin_define
define|#
directive|define
name|L_CLR
parameter_list|(
name|v
parameter_list|)
value|((v)->l_ui = (v)->l_uf = 0)
end_define

begin_define
define|#
directive|define
name|L_ISNEG
parameter_list|(
name|v
parameter_list|)
value|(((v)->l_ui& 0x80000000) != 0)
end_define

begin_define
define|#
directive|define
name|L_ISZERO
parameter_list|(
name|v
parameter_list|)
value|((v)->l_ui == 0&& (v)->l_uf == 0)
end_define

begin_define
define|#
directive|define
name|L_ISHIS
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->l_ui> (b)->l_ui || \ 			  ((a)->l_ui == (b)->l_ui&& (a)->l_uf>= (b)->l_uf))
end_define

begin_define
define|#
directive|define
name|L_ISGEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->l_i> (b)->l_i || \ 			  ((a)->l_i == (b)->l_i&& (a)->l_uf>= (b)->l_uf))
end_define

begin_define
define|#
directive|define
name|L_ISEQU
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|M_ISEQU((a)->l_ui, (a)->l_uf, (b)->l_ui, (b)->l_uf)
end_define

begin_comment
comment|/*  * s_fp/double and u_fp/double conversions  */
end_comment

begin_define
define|#
directive|define
name|FRIC
value|65536.
end_define

begin_comment
comment|/* 2^16 as a double */
end_comment

begin_define
define|#
directive|define
name|DTOFP
parameter_list|(
name|r
parameter_list|)
value|((s_fp)((r) * FRIC))
end_define

begin_define
define|#
directive|define
name|DTOUFP
parameter_list|(
name|r
parameter_list|)
value|((u_fp)((r) * FRIC))
end_define

begin_define
define|#
directive|define
name|FPTOD
parameter_list|(
name|r
parameter_list|)
value|((double)(r) / FRIC)
end_define

begin_comment
comment|/*  * l_fp/double conversions  */
end_comment

begin_define
define|#
directive|define
name|FRAC
value|4294967296.
end_define

begin_comment
comment|/* 2^32 as a double */
end_comment

begin_define
define|#
directive|define
name|M_DTOLFP
parameter_list|(
name|d
parameter_list|,
name|r_i
parameter_list|,
name|r_uf
parameter_list|)
comment|/* double to l_fp */
define|\
value|do { \ 		register double d_tmp; \ 		\ 		d_tmp = (d); \ 		if (d_tmp< 0) { \ 			d_tmp = -d_tmp; \ 			(r_i) = (int32)(d_tmp); \ 			(r_uf) = (u_int32)(((d_tmp) - (double)(r_i)) * FRAC); \ 			M_NEG((r_i), (r_uf)); \ 		} else { \ 			(r_i) = (int32)(d_tmp); \ 			(r_uf) = (u_int32)(((d_tmp) - (double)(r_i)) * FRAC); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_LFPTOD
parameter_list|(
name|r_i
parameter_list|,
name|r_uf
parameter_list|,
name|d
parameter_list|)
comment|/* l_fp to double */
define|\
value|do { \ 		register l_fp l_tmp; \ 		\ 		l_tmp.l_i = (r_i); \ 		l_tmp.l_f = (r_uf); \ 		if (l_tmp.l_i< 0) { \ 			M_NEG(l_tmp.l_i, l_tmp.l_uf); \ 			(d) = -((double)l_tmp.l_i + ((double)l_tmp.l_uf) / FRAC); \ 		} else { \ 			(d) = (double)l_tmp.l_i + ((double)l_tmp.l_uf) / FRAC; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DTOLFP
parameter_list|(
name|d
parameter_list|,
name|v
parameter_list|)
value|M_DTOLFP((d), (v)->l_ui, (v)->l_uf)
end_define

begin_define
define|#
directive|define
name|LFPTOD
parameter_list|(
name|v
parameter_list|,
name|d
parameter_list|)
value|M_LFPTOD((v)->l_ui, (v)->l_uf, (d))
end_define

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dofptoa
name|P
argument_list|(
operator|(
name|u_fp
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dolfptoa
name|P
argument_list|(
operator|(
name|u_long
operator|,
name|u_long
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atolfp
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|buftvtots
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fptoa
name|P
argument_list|(
operator|(
name|s_fp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fptoms
name|P
argument_list|(
operator|(
name|s_fp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fptoms
name|P
argument_list|(
operator|(
name|s_fp
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hextolfp
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|gpstolfp
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|unsigned
name|long
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mstolfp
name|P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|prettydate
name|P
argument_list|(
operator|(
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|gmprettydate
name|P
argument_list|(
operator|(
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|uglydate
name|P
argument_list|(
operator|(
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mfp_mul
name|P
argument_list|(
operator|(
name|int32
operator|*
operator|,
name|u_int32
operator|*
operator|,
name|int32
operator|,
name|u_int32
operator|,
name|int32
operator|,
name|u_int32
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|get_systime
name|P
argument_list|(
operator|(
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|step_systime
name|P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|adj_systime
name|P
argument_list|(
operator|(
name|double
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|lfptoa
parameter_list|(
name|_fpv
parameter_list|,
name|_ndec
parameter_list|)
value|mfptoa((_fpv)->l_ui, (_fpv)->l_uf, (_ndec))
end_define

begin_define
define|#
directive|define
name|lfptoms
parameter_list|(
name|_fpv
parameter_list|,
name|_ndec
parameter_list|)
value|mfptoms((_fpv)->l_ui, (_fpv)->l_uf, (_ndec))
end_define

begin_define
define|#
directive|define
name|ntoa
parameter_list|(
name|_sin
parameter_list|)
value|numtoa((_sin)->sin_addr.s_addr)
end_define

begin_define
define|#
directive|define
name|ntohost
parameter_list|(
name|_sin
parameter_list|)
value|numtohost((_sin)->sin_addr.s_addr)
end_define

begin_define
define|#
directive|define
name|ufptoa
parameter_list|(
name|_fpv
parameter_list|,
name|_ndec
parameter_list|)
value|dofptoa((_fpv), 0, (_ndec), 0)
end_define

begin_define
define|#
directive|define
name|ufptoms
parameter_list|(
name|_fpv
parameter_list|,
name|_ndec
parameter_list|)
value|dofptoa((_fpv), 0, (_ndec), 1)
end_define

begin_define
define|#
directive|define
name|ulfptoa
parameter_list|(
name|_fpv
parameter_list|,
name|_ndec
parameter_list|)
value|dolfptoa((_fpv)->l_ui, (_fpv)->l_uf, 0, (_ndec), 0)
end_define

begin_define
define|#
directive|define
name|ulfptoms
parameter_list|(
name|_fpv
parameter_list|,
name|_ndec
parameter_list|)
value|dolfptoa((_fpv)->l_ui, (_fpv)->l_uf, 0, (_ndec), 1)
end_define

begin_define
define|#
directive|define
name|umfptoa
parameter_list|(
name|_fpi
parameter_list|,
name|_fpf
parameter_list|,
name|_ndec
parameter_list|)
value|dolfptoa((_fpi), (_fpf), 0, (_ndec), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_FP_H */
end_comment

end_unit

