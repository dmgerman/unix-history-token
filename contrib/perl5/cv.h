begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    cv.h  *  *    Copyright (c) 1991-1999, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_comment
comment|/* This structure much match the beginning of XPVFM */
end_comment

begin_struct
struct|struct
name|xpvcv
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xp_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xof_off
decl_stmt|;
comment|/* integer value */
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
name|HV
modifier|*
name|xcv_stash
decl_stmt|;
name|OP
modifier|*
name|xcv_start
decl_stmt|;
name|OP
modifier|*
name|xcv_root
decl_stmt|;
name|void
argument_list|(
argument|*xcv_xsub
argument_list|)
name|_
argument_list|(
operator|(
name|CV
operator|*
name|_CPERLproto
operator|)
argument_list|)
expr_stmt|;
name|ANY
name|xcv_xsubany
decl_stmt|;
name|GV
modifier|*
name|xcv_gv
decl_stmt|;
name|GV
modifier|*
name|xcv_filegv
decl_stmt|;
name|long
name|xcv_depth
decl_stmt|;
comment|/*>= 2 indicates recursive call */
name|AV
modifier|*
name|xcv_padlist
decl_stmt|;
name|CV
modifier|*
name|xcv_outside
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_THREADS
name|perl_mutex
modifier|*
name|xcv_mutexp
decl_stmt|;
name|struct
name|perl_thread
modifier|*
name|xcv_owner
decl_stmt|;
comment|/* current owner thread */
endif|#
directive|endif
comment|/* USE_THREADS */
name|cv_flags_t
name|xcv_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Nullcv
value|Null(CV*)
end_define

begin_define
define|#
directive|define
name|CvSTASH
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_stash
end_define

begin_define
define|#
directive|define
name|CvSTART
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_start
end_define

begin_define
define|#
directive|define
name|CvROOT
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_root
end_define

begin_define
define|#
directive|define
name|CvXSUB
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_xsub
end_define

begin_define
define|#
directive|define
name|CvXSUBANY
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_xsubany
end_define

begin_define
define|#
directive|define
name|CvGV
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_gv
end_define

begin_define
define|#
directive|define
name|CvFILEGV
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_filegv
end_define

begin_define
define|#
directive|define
name|CvDEPTH
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_depth
end_define

begin_define
define|#
directive|define
name|CvPADLIST
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_padlist
end_define

begin_define
define|#
directive|define
name|CvOUTSIDE
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_outside
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|CvMUTEXP
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_mutexp
end_define

begin_define
define|#
directive|define
name|CvOWNER
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_owner
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_define
define|#
directive|define
name|CvFLAGS
parameter_list|(
name|sv
parameter_list|)
value|((XPVCV*)SvANY(sv))->xcv_flags
end_define

begin_define
define|#
directive|define
name|CVf_CLONE
value|0x0001
end_define

begin_comment
comment|/* anon CV uses external lexicals */
end_comment

begin_define
define|#
directive|define
name|CVf_CLONED
value|0x0002
end_define

begin_comment
comment|/* a clone of one of those */
end_comment

begin_define
define|#
directive|define
name|CVf_ANON
value|0x0004
end_define

begin_comment
comment|/* CvGV() can't be trusted */
end_comment

begin_define
define|#
directive|define
name|CVf_OLDSTYLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|CVf_UNIQUE
value|0x0010
end_define

begin_comment
comment|/* can't be cloned */
end_comment

begin_define
define|#
directive|define
name|CVf_NODEBUG
value|0x0020
end_define

begin_comment
comment|/* no DB::sub indirection for this CV 				   (esp. useful for special XSUBs) */
end_comment

begin_define
define|#
directive|define
name|CVf_METHOD
value|0x0040
end_define

begin_comment
comment|/* CV is explicitly marked as a method */
end_comment

begin_define
define|#
directive|define
name|CVf_LOCKED
value|0x0080
end_define

begin_comment
comment|/* CV locks itself or first arg on entry */
end_comment

begin_define
define|#
directive|define
name|CvCLONE
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_CLONE)
end_define

begin_define
define|#
directive|define
name|CvCLONE_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_CLONE)
end_define

begin_define
define|#
directive|define
name|CvCLONE_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_CLONE)
end_define

begin_define
define|#
directive|define
name|CvCLONED
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_CLONED)
end_define

begin_define
define|#
directive|define
name|CvCLONED_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_CLONED)
end_define

begin_define
define|#
directive|define
name|CvCLONED_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_CLONED)
end_define

begin_define
define|#
directive|define
name|CvANON
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_ANON)
end_define

begin_define
define|#
directive|define
name|CvANON_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_ANON)
end_define

begin_define
define|#
directive|define
name|CvANON_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_ANON)
end_define

begin_define
define|#
directive|define
name|CvOLDSTYLE
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_OLDSTYLE)
end_define

begin_define
define|#
directive|define
name|CvOLDSTYLE_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_OLDSTYLE)
end_define

begin_define
define|#
directive|define
name|CvOLDSTYLE_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_OLDSTYLE)
end_define

begin_define
define|#
directive|define
name|CvUNIQUE
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_UNIQUE)
end_define

begin_define
define|#
directive|define
name|CvUNIQUE_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_UNIQUE)
end_define

begin_define
define|#
directive|define
name|CvUNIQUE_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_UNIQUE)
end_define

begin_define
define|#
directive|define
name|CvNODEBUG
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_NODEBUG)
end_define

begin_define
define|#
directive|define
name|CvNODEBUG_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_NODEBUG)
end_define

begin_define
define|#
directive|define
name|CvNODEBUG_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_NODEBUG)
end_define

begin_define
define|#
directive|define
name|CvMETHOD
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_METHOD)
end_define

begin_define
define|#
directive|define
name|CvMETHOD_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_METHOD)
end_define

begin_define
define|#
directive|define
name|CvMETHOD_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_METHOD)
end_define

begin_define
define|#
directive|define
name|CvLOCKED
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)& CVf_LOCKED)
end_define

begin_define
define|#
directive|define
name|CvLOCKED_on
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv) |= CVf_LOCKED)
end_define

begin_define
define|#
directive|define
name|CvLOCKED_off
parameter_list|(
name|cv
parameter_list|)
value|(CvFLAGS(cv)&= ~CVf_LOCKED)
end_define

begin_define
define|#
directive|define
name|CvEVAL
parameter_list|(
name|cv
parameter_list|)
value|(CvUNIQUE(cv)&& !SvFAKE(cv))
end_define

begin_define
define|#
directive|define
name|CvEVAL_on
parameter_list|(
name|cv
parameter_list|)
value|(CvUNIQUE_on(cv),SvFAKE_off(cv))
end_define

begin_define
define|#
directive|define
name|CvEVAL_off
parameter_list|(
name|cv
parameter_list|)
value|CvUNIQUE_off(cv)
end_define

begin_comment
comment|/* BEGIN|INIT|END */
end_comment

begin_define
define|#
directive|define
name|CvSPECIAL
parameter_list|(
name|cv
parameter_list|)
value|(CvUNIQUE(cv)&& SvFAKE(cv))
end_define

begin_define
define|#
directive|define
name|CvSPECIAL_on
parameter_list|(
name|cv
parameter_list|)
value|(CvUNIQUE_on(cv),SvFAKE_on(cv))
end_define

begin_define
define|#
directive|define
name|CvSPECIAL_off
parameter_list|(
name|cv
parameter_list|)
value|(CvUNIQUE_off(cv),SvFAKE_off(cv))
end_define

end_unit

