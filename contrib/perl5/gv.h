begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    gv.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_struct
struct|struct
name|gp
block|{
name|SV
modifier|*
name|gp_sv
decl_stmt|;
comment|/* scalar value */
name|U32
name|gp_refcnt
decl_stmt|;
comment|/* how many globs point to this? */
name|struct
name|io
modifier|*
name|gp_io
decl_stmt|;
comment|/* filehandle value */
name|CV
modifier|*
name|gp_form
decl_stmt|;
comment|/* format value */
name|AV
modifier|*
name|gp_av
decl_stmt|;
comment|/* array value */
name|HV
modifier|*
name|gp_hv
decl_stmt|;
comment|/* hash value */
name|GV
modifier|*
name|gp_egv
decl_stmt|;
comment|/* effective gv, if *glob */
name|CV
modifier|*
name|gp_cv
decl_stmt|;
comment|/* subroutine value */
name|U32
name|gp_cvgen
decl_stmt|;
comment|/* generational validity of cached gv_cv */
name|U32
name|gp_flags
decl_stmt|;
comment|/* XXX unused */
name|line_t
name|gp_line
decl_stmt|;
comment|/* line first declared at (for -w) */
name|char
modifier|*
name|gp_file
decl_stmt|;
comment|/* file first declared in (for -w) */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRIPPLED_CC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|iAPX286
argument_list|)
operator|||
name|defined
argument_list|(
name|M_I286
argument_list|)
operator|||
name|defined
argument_list|(
name|I80286
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|MICROPORT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GvXPVGV
parameter_list|(
name|gv
parameter_list|)
value|((XPVGV*)SvANY(gv))
end_define

begin_define
define|#
directive|define
name|GvGP
parameter_list|(
name|gv
parameter_list|)
value|(GvXPVGV(gv)->xgv_gp)
end_define

begin_define
define|#
directive|define
name|GvNAME
parameter_list|(
name|gv
parameter_list|)
value|(GvXPVGV(gv)->xgv_name)
end_define

begin_define
define|#
directive|define
name|GvNAMELEN
parameter_list|(
name|gv
parameter_list|)
value|(GvXPVGV(gv)->xgv_namelen)
end_define

begin_define
define|#
directive|define
name|GvSTASH
parameter_list|(
name|gv
parameter_list|)
value|(GvXPVGV(gv)->xgv_stash)
end_define

begin_define
define|#
directive|define
name|GvFLAGS
parameter_list|(
name|gv
parameter_list|)
value|(GvXPVGV(gv)->xgv_flags)
end_define

begin_comment
comment|/* =for apidoc Am|SV*|GvSV|GV* gv  Return the SV from the GV.  =cut */
end_comment

begin_define
define|#
directive|define
name|GvSV
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_sv)
end_define

begin_define
define|#
directive|define
name|GvREFCNT
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_refcnt)
end_define

begin_define
define|#
directive|define
name|GvIO
parameter_list|(
name|gv
parameter_list|)
value|((gv)&& SvTYPE((SV*)gv) == SVt_PVGV ? GvIOp(gv) : 0)
end_define

begin_define
define|#
directive|define
name|GvIOp
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_io)
end_define

begin_define
define|#
directive|define
name|GvIOn
parameter_list|(
name|gv
parameter_list|)
value|(GvIO(gv) ? GvIOp(gv) : GvIOp(gv_IOadd(gv)))
end_define

begin_define
define|#
directive|define
name|GvFORM
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_form)
end_define

begin_define
define|#
directive|define
name|GvAV
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_av)
end_define

begin_comment
comment|/* This macro is deprecated.  Do not use! */
end_comment

begin_define
define|#
directive|define
name|GvREFCNT_inc
parameter_list|(
name|gv
parameter_list|)
value|((GV*)SvREFCNT_inc(gv))
end_define

begin_comment
comment|/* DO NOT USE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MICROPORT
end_ifdef

begin_comment
comment|/* Microport 2.4 hack */
end_comment

begin_function_decl
name|AV
modifier|*
name|GvAVn
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GvAVn
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_av ? \ 			 GvGP(gv)->gp_av : \ 			 GvGP(gv_AVadd(gv))->gp_av)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GvHV
parameter_list|(
name|gv
parameter_list|)
value|((GvGP(gv))->gp_hv)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MICROPORT
end_ifdef

begin_comment
comment|/* Microport 2.4 hack */
end_comment

begin_function_decl
name|HV
modifier|*
name|GvHVn
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GvHVn
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_hv ? \ 			 GvGP(gv)->gp_hv : \ 			 GvGP(gv_HVadd(gv))->gp_hv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Microport 2.4 hack */
end_comment

begin_define
define|#
directive|define
name|GvCV
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_cv)
end_define

begin_define
define|#
directive|define
name|GvCVGEN
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_cvgen)
end_define

begin_define
define|#
directive|define
name|GvCVu
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_cvgen ? Nullcv : GvGP(gv)->gp_cv)
end_define

begin_define
define|#
directive|define
name|GvGPFLAGS
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_flags)
end_define

begin_define
define|#
directive|define
name|GvLINE
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_line)
end_define

begin_define
define|#
directive|define
name|GvFILE
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_file)
end_define

begin_define
define|#
directive|define
name|GvFILEGV
parameter_list|(
name|gv
parameter_list|)
value|(gv_fetchfile(GvFILE(gv)))
end_define

begin_define
define|#
directive|define
name|GvEGV
parameter_list|(
name|gv
parameter_list|)
value|(GvGP(gv)->gp_egv)
end_define

begin_define
define|#
directive|define
name|GvENAME
parameter_list|(
name|gv
parameter_list|)
value|GvNAME(GvEGV(gv) ? GvEGV(gv) : gv)
end_define

begin_define
define|#
directive|define
name|GvESTASH
parameter_list|(
name|gv
parameter_list|)
value|GvSTASH(GvEGV(gv) ? GvEGV(gv) : gv)
end_define

begin_define
define|#
directive|define
name|GVf_INTRO
value|0x01
end_define

begin_define
define|#
directive|define
name|GVf_MULTI
value|0x02
end_define

begin_define
define|#
directive|define
name|GVf_ASSUMECV
value|0x04
end_define

begin_define
define|#
directive|define
name|GVf_IN_PAD
value|0x08
end_define

begin_define
define|#
directive|define
name|GVf_IMPORTED
value|0xF0
end_define

begin_define
define|#
directive|define
name|GVf_IMPORTED_SV
value|0x10
end_define

begin_define
define|#
directive|define
name|GVf_IMPORTED_AV
value|0x20
end_define

begin_define
define|#
directive|define
name|GVf_IMPORTED_HV
value|0x40
end_define

begin_define
define|#
directive|define
name|GVf_IMPORTED_CV
value|0x80
end_define

begin_define
define|#
directive|define
name|GvINTRO
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_INTRO)
end_define

begin_define
define|#
directive|define
name|GvINTRO_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_INTRO)
end_define

begin_define
define|#
directive|define
name|GvINTRO_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_INTRO)
end_define

begin_define
define|#
directive|define
name|GvMULTI
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_MULTI)
end_define

begin_define
define|#
directive|define
name|GvMULTI_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_MULTI)
end_define

begin_define
define|#
directive|define
name|GvMULTI_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_MULTI)
end_define

begin_define
define|#
directive|define
name|GvASSUMECV
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_ASSUMECV)
end_define

begin_define
define|#
directive|define
name|GvASSUMECV_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_ASSUMECV)
end_define

begin_define
define|#
directive|define
name|GvASSUMECV_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_ASSUMECV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_IMPORTED)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_IMPORTED)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_IMPORTED)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_SV
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_IMPORTED_SV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_SV_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_IMPORTED_SV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_SV_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_IMPORTED_SV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_AV
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_IMPORTED_AV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_AV_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_IMPORTED_AV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_AV_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_IMPORTED_AV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_HV
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_IMPORTED_HV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_HV_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_IMPORTED_HV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_HV_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_IMPORTED_HV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_CV
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_IMPORTED_CV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_CV_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_IMPORTED_CV)
end_define

begin_define
define|#
directive|define
name|GvIMPORTED_CV_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_IMPORTED_CV)
end_define

begin_define
define|#
directive|define
name|GvIN_PAD
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)& GVf_IN_PAD)
end_define

begin_define
define|#
directive|define
name|GvIN_PAD_on
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv) |= GVf_IN_PAD)
end_define

begin_define
define|#
directive|define
name|GvIN_PAD_off
parameter_list|(
name|gv
parameter_list|)
value|(GvFLAGS(gv)&= ~GVf_IN_PAD)
end_define

begin_define
define|#
directive|define
name|Nullgv
value|Null(GV*)
end_define

begin_define
define|#
directive|define
name|DM_UID
value|0x003
end_define

begin_define
define|#
directive|define
name|DM_RUID
value|0x001
end_define

begin_define
define|#
directive|define
name|DM_EUID
value|0x002
end_define

begin_define
define|#
directive|define
name|DM_GID
value|0x030
end_define

begin_define
define|#
directive|define
name|DM_RGID
value|0x010
end_define

begin_define
define|#
directive|define
name|DM_EGID
value|0x020
end_define

begin_define
define|#
directive|define
name|DM_DELAY
value|0x100
end_define

begin_comment
comment|/*  * symbol creation flags, for use in gv_fetchpv() and get_*v()  */
end_comment

begin_define
define|#
directive|define
name|GV_ADD
value|0x01
end_define

begin_comment
comment|/* add, if symbol not already there */
end_comment

begin_define
define|#
directive|define
name|GV_ADDMULTI
value|0x02
end_define

begin_comment
comment|/* add, pretending it has been added already */
end_comment

begin_define
define|#
directive|define
name|GV_ADDWARN
value|0x04
end_define

begin_comment
comment|/* add, but warn if symbol wasn't already there */
end_comment

begin_define
define|#
directive|define
name|GV_ADDINEVAL
value|0x08
end_define

begin_comment
comment|/* add, as though we're doing so within an eval */
end_comment

begin_define
define|#
directive|define
name|GV_NOINIT
value|0x10
end_define

begin_comment
comment|/* add, but don't init symbol, if type != PVGV */
end_comment

end_unit

