begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    av.h  *  *    Copyright (c) 1991-2000, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
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
comment|/* max index for which array has space */
name|IV
name|xof_off
decl_stmt|;
comment|/* ptr is incremented by offset */
name|NV
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

begin_comment
comment|/* AVf_REAL is set for all AVs whose xav_array contents are refcounted.  * Some things like "@_" and the scratchpad list do not set this, to  * indicate that they are cheating (for efficiency) by not refcounting  * the AV's contents.  *   * AVf_REIFY is only meaningful on such "fake" AVs (i.e. where AVf_REAL  * is not set).  It indicates that the fake AV is capable of becoming  * real if the array needs to be modified in some way.  Functions that  * modify fake AVs check both flags to call av_reify() as appropriate.  *  * Note that the Perl stack has neither flag set. (Thus, items that go  * on the stack are never refcounted.)  *  * These internal details are subject to change any time.  AV  * manipulations external to perl should not care about any of this.  * GSAR 1999-09-10  */
end_comment

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

begin_comment
comment|/* XXX this is not used anywhere */
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

begin_comment
comment|/* =for apidoc AmU||Nullav Null AV pointer.  =for apidoc Am|int|AvFILL|AV* av Same as C<av_len()>.  Deprecated, use C<av_len()> instead.  =cut */
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

