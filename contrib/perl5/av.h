begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    av.h  *  *    Copyright (c) 1991-1999, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_struct
struct|struct
name|xpvav
block|{
name|char
modifier|*
name|xav_array
decl_stmt|;
comment|/* pointer to first array element */
name|SSize_t
name|xav_fill
decl_stmt|;
comment|/* Index of last element present */
name|SSize_t
name|xav_max
decl_stmt|;
comment|/* Number of elements for which array has space */
name|IV
name|xof_off
decl_stmt|;
comment|/* ptr is incremented by offset */
name|double
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* magic for scalar array */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
name|SV
modifier|*
modifier|*
name|xav_alloc
decl_stmt|;
comment|/* pointer to malloced string */
name|SV
modifier|*
name|xav_arylen
decl_stmt|;
name|U8
name|xav_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AVf_REAL
value|1
end_define

begin_comment
comment|/* free old entries */
end_comment

begin_define
define|#
directive|define
name|AVf_REIFY
value|2
end_define

begin_comment
comment|/* can become real */
end_comment

begin_define
define|#
directive|define
name|AVf_REUSED
value|4
end_define

begin_comment
comment|/* got undeffed--don't turn old memory into SVs now */
end_comment

begin_define
define|#
directive|define
name|Nullav
value|Null(AV*)
end_define

begin_define
define|#
directive|define
name|AvARRAY
parameter_list|(
name|av
parameter_list|)
value|((SV**)((XPVAV*)  SvANY(av))->xav_array)
end_define

begin_define
define|#
directive|define
name|AvALLOC
parameter_list|(
name|av
parameter_list|)
value|((XPVAV*)  SvANY(av))->xav_alloc
end_define

begin_define
define|#
directive|define
name|AvMAX
parameter_list|(
name|av
parameter_list|)
value|((XPVAV*)  SvANY(av))->xav_max
end_define

begin_define
define|#
directive|define
name|AvFILLp
parameter_list|(
name|av
parameter_list|)
value|((XPVAV*)  SvANY(av))->xav_fill
end_define

begin_define
define|#
directive|define
name|AvARYLEN
parameter_list|(
name|av
parameter_list|)
value|((XPVAV*)  SvANY(av))->xav_arylen
end_define

begin_define
define|#
directive|define
name|AvFLAGS
parameter_list|(
name|av
parameter_list|)
value|((XPVAV*)  SvANY(av))->xav_flags
end_define

begin_define
define|#
directive|define
name|AvREAL
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av)& AVf_REAL)
end_define

begin_define
define|#
directive|define
name|AvREAL_on
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av) |= AVf_REAL)
end_define

begin_define
define|#
directive|define
name|AvREAL_off
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av)&= ~AVf_REAL)
end_define

begin_define
define|#
directive|define
name|AvREIFY
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av)& AVf_REIFY)
end_define

begin_define
define|#
directive|define
name|AvREIFY_on
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av) |= AVf_REIFY)
end_define

begin_define
define|#
directive|define
name|AvREIFY_off
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av)&= ~AVf_REIFY)
end_define

begin_define
define|#
directive|define
name|AvREUSED
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av)& AVf_REUSED)
end_define

begin_define
define|#
directive|define
name|AvREUSED_on
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av) |= AVf_REUSED)
end_define

begin_define
define|#
directive|define
name|AvREUSED_off
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av)&= ~AVf_REUSED)
end_define

begin_define
define|#
directive|define
name|AvREALISH
parameter_list|(
name|av
parameter_list|)
value|(AvFLAGS(av)& (AVf_REAL|AVf_REIFY))
end_define

begin_define
define|#
directive|define
name|AvFILL
parameter_list|(
name|av
parameter_list|)
value|((SvRMAGICAL((SV *) (av))) \ 			  ? mg_size((SV *) av) : AvFILLp(av))
end_define

end_unit

