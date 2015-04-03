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
name|u_int32
name|l_uf
decl_stmt|;
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
comment|/*  * A unit second in fp format.	Actually 2**(half_the_bits_in_a_long)  */
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
name|NTOHS_FP
parameter_list|(
name|x
parameter_list|)
value|(ntohl(x))
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
value|do {							\ 		(hi) = ntohl(ni);				\ 		(hf) = ntohl(nf);				\ 	} while (FALSE)
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
value|do {							\ 		(ni) = htonl(hi);				\ 		(nf) = htonl(hf);				\ 	} while (FALSE)
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
define|\
value|HTONL_MFP((h)->l_ui, (h)->l_uf, (n)->l_ui, (n)->l_uf)
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
define|\
value|NTOHL_MFP((n)->l_ui, (n)->l_uf, (h)->l_ui, (h)->l_uf)
end_define

begin_comment
comment|/* Convert unsigned ts fraction to net order ts */
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
value|do {							\ 		(nts)->l_ui = 0;				\ 		(nts)->l_uf = htonl(uf);			\ 	} while (FALSE)
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
value|MFPTOFP((v)->l_i, (v)->l_uf)
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
value|((v)->l_ui = 0x7fffffffu, (v)->l_uf = 0xffffffffu)
end_define

begin_define
define|#
directive|define
name|MINLFP
parameter_list|(
name|v
parameter_list|)
value|((v)->l_ui = 0x80000000u, (v)->l_uf = 0u)
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
value|do { \ 		(v_f) = ~(v_f) + 1u; \ 		(v_i) = ~(v_i) + ((v_f) == 0); \ 	} while (FALSE)
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
value|do { \ 		(r_f) = ~(a_f) + 1u; \ 		(r_i) = ~(a_i) + ((r_f) == 0); \ 	} while (FALSE)
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
value|do { \ 		u_int32 add_t = (r_f); \ 		(r_f) += (a_f); \ 		(r_i) += (a_i) + ((u_int32)(r_f)< add_t); \ 	} while (FALSE)
end_define

begin_define
define|#
directive|define
name|M_ADD3
parameter_list|(
name|r_o
parameter_list|,
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|a_o
parameter_list|,
name|a_i
parameter_list|,
name|a_f
parameter_list|)
comment|/* r += a, three word */
define|\
value|do { \ 		u_int32 add_t, add_c; \ 		add_t  = (r_f); \ 		(r_f) += (a_f); \ 		add_c  = ((u_int32)(r_f)< add_t); \ 		(r_i) += add_c; \ 		add_c  = ((u_int32)(r_i)< add_c); \ 		add_t  = (r_i); \ 		(r_i) += (a_i); \ 		add_c |= ((u_int32)(r_i)< add_t); \ 		(r_o) += (a_o) + add_c; \ 	} while (FALSE)
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
value|do { \ 		u_int32 sub_t = (r_f); \ 		(r_f) -= (a_f); \ 		(r_i) -= (a_i) + ((u_int32)(r_f)> sub_t); \ 	} while (FALSE)
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
value|do { \ 		(v_f) = ((u_int32)(v_f)>> 1) | ((u_int32)(v_i)<< 31);	\ 		(v_i) = ((u_int32)(v_i)>> 1); \ 	} while (FALSE)
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
value|do { \ 		(v_f) = ((u_int32)(v_f)>> 1) | ((u_int32)(v_i)<< 31);	\ 		(v_i) = ((u_int32)(v_i)>> 1) | ((u_int32)(v_i)& 0x80000000);	\ 	} while (FALSE)
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
value|do { \ 		(v_i) = ((u_int32)(v_i)<< 1) | ((u_int32)(v_f)>> 31);	\ 		(v_f) = ((u_int32)(v_f)<< 1); \ 	} while (FALSE)
end_define

begin_define
define|#
directive|define
name|M_LSHIFT3
parameter_list|(
name|v_o
parameter_list|,
name|v_i
parameter_list|,
name|v_f
parameter_list|)
comment|/* v<<= 1, with overflow */
define|\
value|do { \ 		(v_o) = ((u_int32)(v_o)<< 1) | ((u_int32)(v_i)>> 31);	\ 		(v_i) = ((u_int32)(v_i)<< 1) | ((u_int32)(v_f)>> 31);	\ 		(v_f) = ((u_int32)(v_f)<< 1); \ 	} while (FALSE)
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
value|do { \ 		int32 add_f = (int32)(f); \ 		if (add_f>= 0) \ 			M_ADD((r_i), (r_f), 0, (uint32)( add_f)); \ 		else \ 			M_SUB((r_i), (r_f), 0, (uint32)(-add_f)); \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|M_ISNEG
parameter_list|(
name|v_i
parameter_list|)
comment|/* v< 0 */
define|\
value|(((v_i)& 0x80000000) != 0)
end_define

begin_define
define|#
directive|define
name|M_ISGT
parameter_list|(
name|a_i
parameter_list|,
name|a_f
parameter_list|,
name|b_i
parameter_list|,
name|b_f
parameter_list|)
comment|/* a> b signed */
define|\
value|(((u_int32)((a_i) ^ 0x80000000)> (u_int32)((b_i) ^ 0x80000000)) || \ 	  ((a_i) == (b_i)&& ((u_int32)(a_f))> ((u_int32)(b_f))))
end_define

begin_define
define|#
directive|define
name|M_ISGTU
parameter_list|(
name|a_i
parameter_list|,
name|a_f
parameter_list|,
name|b_i
parameter_list|,
name|b_f
parameter_list|)
comment|/* a> b unsigned */
define|\
value|(((u_int32)(a_i))> ((u_int32)(b_i)) || \ 	  ((a_i) == (b_i)&& ((u_int32)(a_f))> ((u_int32)(b_f))))
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
value|(((u_int32)((a_i) ^ 0x80000000)> (u_int32)((b_i) ^ 0x80000000)) || \ 	  ((a_i) == (b_i)&& (u_int32)(a_f)>= (u_int32)(b_f)))
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
value|((u_int32)(a_i) == (u_int32)(b_i)&& (u_int32)(a_f) == (u_int32)(b_f))
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
value|M_RSHIFTU((v)->l_ui, (v)->l_uf)
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
value|M_ISNEG((v)->l_ui)
end_define

begin_define
define|#
directive|define
name|L_ISZERO
parameter_list|(
name|v
parameter_list|)
value|(((v)->l_ui | (v)->l_uf) == 0)
end_define

begin_define
define|#
directive|define
name|L_ISGT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|M_ISGT((a)->l_i, (a)->l_uf, (b)->l_i, (b)->l_uf)
end_define

begin_define
define|#
directive|define
name|L_ISGTU
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|M_ISGTU((a)->l_ui, (a)->l_uf, (b)->l_ui, (b)->l_uf)
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
value|M_ISHIS((a)->l_ui, (a)->l_uf, (b)->l_ui, (b)->l_uf)
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
value|M_ISGEQ((a)->l_ui, (a)->l_uf, (b)->l_ui, (b)->l_uf)
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
value|65536.0
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
value|4294967296.0
end_define

begin_comment
comment|/* 2^32 as a double */
end_comment

begin_comment
comment|/*  * Use 64 bit integers if available.  Solaris on SPARC has a problem  * compiling parsesolaris.c if ntp_fp.h includes math.h, due to  * archaic gets() and printf() prototypes used in Solaris kernel  * headers.  So far the problem has only been seen with gcc, but it  * may also affect Sun compilers, in which case the defined(__GNUC__)  * term should be removed.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_U_INT64
argument_list|)
operator|&&
expr|\
operator|!
operator|(
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
name|defined
argument_list|(
name|__sun
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|sparc
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/* ldexp() */
end_comment

begin_define
define|#
directive|define
name|M_DTOLFP
parameter_list|(
name|d
parameter_list|,
name|r_ui
parameter_list|,
name|r_uf
parameter_list|)
comment|/* double to l_fp */
define|\
value|do {							\ 		double	d_tmp;					\ 		u_int64	q_tmp;					\ 		int	M_isneg;					\ 								\ 		d_tmp = (d);					\ 		M_isneg = (d_tmp< 0.);				\ 		if (M_isneg) {					\ 			d_tmp = -d_tmp;				\ 		}						\ 		q_tmp = (u_int64)ldexp(d_tmp, 32);		\ 		if (M_isneg) {					\ 			q_tmp = ~q_tmp + 1;			\ 		}						\ 		(r_uf) = (u_int32)q_tmp;			\ 		(r_ui) = (u_int32)(q_tmp>> 32);		\ 	} while (FALSE)
end_define

begin_define
define|#
directive|define
name|M_LFPTOD
parameter_list|(
name|r_ui
parameter_list|,
name|r_uf
parameter_list|,
name|d
parameter_list|)
comment|/* l_fp to double */
define|\
value|do {							\ 		double	d_tmp;					\ 		u_int64	q_tmp;					\ 		int	M_isneg;				\ 								\ 		q_tmp = ((u_int64)(r_ui)<< 32) + (r_uf);	\ 		M_isneg = M_ISNEG(r_ui);			\ 		if (M_isneg) {					\ 			q_tmp = ~q_tmp + 1;			\ 		}						\ 		d_tmp = ldexp((double)q_tmp, -32);		\ 		if (M_isneg) {					\ 			d_tmp = -d_tmp;				\ 		}						\ 		(d) = d_tmp;					\ 	} while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* use only 32 bit unsigned values */
end_comment

begin_define
define|#
directive|define
name|M_DTOLFP
parameter_list|(
name|d
parameter_list|,
name|r_ui
parameter_list|,
name|r_uf
parameter_list|)
comment|/* double to l_fp */
define|\
value|do { \ 		double d_tmp; \ 		if ((d_tmp = (d))< 0) { \ 			(r_ui) = (u_int32)(-d_tmp); \ 			(r_uf) = (u_int32)(-(d_tmp + (double)(r_ui)) * FRAC); \ 			M_NEG((r_ui), (r_uf)); \ 		} else { \ 			(r_ui) = (u_int32)d_tmp; \ 			(r_uf) = (u_int32)((d_tmp - (double)(r_ui)) * FRAC); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|M_LFPTOD
parameter_list|(
name|r_ui
parameter_list|,
name|r_uf
parameter_list|,
name|d
parameter_list|)
comment|/* l_fp to double */
define|\
value|do { \ 		u_int32 l_thi, l_tlo; \ 		l_thi = (r_ui); l_tlo = (r_uf); \ 		if (M_ISNEG(l_thi)) { \ 			M_NEG(l_thi, l_tlo); \ 			(d) = -((double)l_thi + (double)l_tlo / FRAC); \ 		} else { \ 			(d) = (double)l_thi + (double)l_tlo / FRAC; \ 		} \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
specifier|extern
name|char
modifier|*
name|dofptoa
parameter_list|(
name|u_fp
parameter_list|,
name|int
parameter_list|,
name|short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dolfptoa
parameter_list|(
name|u_int32
parameter_list|,
name|u_int32
parameter_list|,
name|int
parameter_list|,
name|short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|atolfp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|buftvtots
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fptoa
parameter_list|(
name|s_fp
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|fptoms
parameter_list|(
name|s_fp
parameter_list|,
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hextolfp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gpstolfp
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mstolfp
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|prettydate
parameter_list|(
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|gmprettydate
parameter_list|(
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|uglydate
parameter_list|(
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfp_mul
parameter_list|(
name|int32
modifier|*
parameter_list|,
name|u_int32
modifier|*
parameter_list|,
name|int32
parameter_list|,
name|u_int32
parameter_list|,
name|int32
parameter_list|,
name|u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_sys_fuzz
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_systime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_systime
parameter_list|(
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|step_systime
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|adj_systime
parameter_list|(
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|tm
modifier|*
name|ntp2unix_tm
parameter_list|(
name|u_int32
name|ntp
parameter_list|,
name|int
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|lfptoa
parameter_list|(
name|fpv
parameter_list|,
name|ndec
parameter_list|)
value|mfptoa((fpv)->l_ui, (fpv)->l_uf, (ndec))
end_define

begin_define
define|#
directive|define
name|lfptoms
parameter_list|(
name|fpv
parameter_list|,
name|ndec
parameter_list|)
value|mfptoms((fpv)->l_ui, (fpv)->l_uf, (ndec))
end_define

begin_define
define|#
directive|define
name|stoa
parameter_list|(
name|addr
parameter_list|)
value|socktoa(addr)
end_define

begin_define
define|#
directive|define
name|ntoa
parameter_list|(
name|addr
parameter_list|)
value|stoa(addr)
end_define

begin_define
define|#
directive|define
name|sptoa
parameter_list|(
name|addr
parameter_list|)
value|sockporttoa(addr)
end_define

begin_define
define|#
directive|define
name|stohost
parameter_list|(
name|addr
parameter_list|)
value|socktohost(addr)
end_define

begin_define
define|#
directive|define
name|ufptoa
parameter_list|(
name|fpv
parameter_list|,
name|ndec
parameter_list|)
value|dofptoa((fpv), 0, (ndec), 0)
end_define

begin_define
define|#
directive|define
name|ufptoms
parameter_list|(
name|fpv
parameter_list|,
name|ndec
parameter_list|)
value|dofptoa((fpv), 0, (ndec), 1)
end_define

begin_define
define|#
directive|define
name|ulfptoa
parameter_list|(
name|fpv
parameter_list|,
name|ndec
parameter_list|)
value|dolfptoa((fpv)->l_ui, (fpv)->l_uf, 0, (ndec), 0)
end_define

begin_define
define|#
directive|define
name|ulfptoms
parameter_list|(
name|fpv
parameter_list|,
name|ndec
parameter_list|)
value|dolfptoa((fpv)->l_ui, (fpv)->l_uf, 0, (ndec), 1)
end_define

begin_define
define|#
directive|define
name|umfptoa
parameter_list|(
name|fpi
parameter_list|,
name|fpf
parameter_list|,
name|ndec
parameter_list|)
value|dolfptoa((fpi), (fpf), 0, (ndec), 0)
end_define

begin_comment
comment|/*  * Optional callback from libntp step_systime() to ntpd.  Optional *  because other libntp clients like ntpdate don't use it.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|time_stepped_callback
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|time_stepped_callback
name|step_callback
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Multi-thread locking for get_systime()  *  * On most systems, get_systime() is used solely by the main ntpd  * thread, but on Windows it's also used by the dedicated I/O thread.  * The [Bug 2037] changes to get_systime() have it keep state between  * calls to ensure time moves in only one direction, which means its  * use on Windows needs to be protected against simultaneous execution  * to avoid falsely detecting Lamport violations by ensuring only one  * thread at a time is in get_systime().  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_decl_stmt
specifier|extern
name|CRITICAL_SECTION
name|get_systime_cs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INIT_GET_SYSTIME_CRITSEC
parameter_list|()
define|\
value|InitializeCriticalSection(&get_systime_cs)
end_define

begin_define
define|#
directive|define
name|ENTER_GET_SYSTIME_CRITSEC
parameter_list|()
define|\
value|EnterCriticalSection(&get_systime_cs)
end_define

begin_define
define|#
directive|define
name|LEAVE_GET_SYSTIME_CRITSEC
parameter_list|()
define|\
value|LeaveCriticalSection(&get_systime_cs)
end_define

begin_define
define|#
directive|define
name|INIT_WIN_PRECISE_TIME
parameter_list|()
define|\
value|init_win_precise_time()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SYS_WINNT follows */
end_comment

begin_define
define|#
directive|define
name|INIT_GET_SYSTIME_CRITSEC
parameter_list|()
define|\
value|do {} while (FALSE)
end_define

begin_define
define|#
directive|define
name|ENTER_GET_SYSTIME_CRITSEC
parameter_list|()
define|\
value|do {} while (FALSE)
end_define

begin_define
define|#
directive|define
name|LEAVE_GET_SYSTIME_CRITSEC
parameter_list|()
define|\
value|do {} while (FALSE)
end_define

begin_define
define|#
directive|define
name|INIT_WIN_PRECISE_TIME
parameter_list|()
define|\
value|do {} while (FALSE)
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
comment|/* NTP_FP_H */
end_comment

end_unit

