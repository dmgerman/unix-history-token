begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    mg.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRUCT_MGVTBL_DEFINITION
end_ifdef

begin_expr_stmt
name|STRUCT_MGVTBL_DEFINITION
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_struct
struct|struct
name|mgvtbl
block|{
name|int
argument_list|(
argument|CPERLscope(*svt_get)
argument_list|)
operator|(
name|pTHX_
name|SV
operator|*
name|sv
operator|,
name|MAGIC
operator|*
name|mg
operator|)
expr_stmt|;
name|int
argument_list|(
argument|CPERLscope(*svt_set)
argument_list|)
operator|(
name|pTHX_
name|SV
operator|*
name|sv
operator|,
name|MAGIC
operator|*
name|mg
operator|)
expr_stmt|;
name|U32
argument_list|(
argument|CPERLscope(*svt_len)
argument_list|)
operator|(
name|pTHX_
name|SV
operator|*
name|sv
operator|,
name|MAGIC
operator|*
name|mg
operator|)
expr_stmt|;
name|int
argument_list|(
argument|CPERLscope(*svt_clear)
argument_list|)
operator|(
name|pTHX_
name|SV
operator|*
name|sv
operator|,
name|MAGIC
operator|*
name|mg
operator|)
expr_stmt|;
name|int
argument_list|(
argument|CPERLscope(*svt_free)
argument_list|)
operator|(
name|pTHX_
name|SV
operator|*
name|sv
operator|,
name|MAGIC
operator|*
name|mg
operator|)
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|magic
block|{
name|MAGIC
modifier|*
name|mg_moremagic
decl_stmt|;
name|MGVTBL
modifier|*
name|mg_virtual
decl_stmt|;
comment|/* pointer to magic functions */
name|U16
name|mg_private
decl_stmt|;
name|char
name|mg_type
decl_stmt|;
name|U8
name|mg_flags
decl_stmt|;
name|SV
modifier|*
name|mg_obj
decl_stmt|;
name|char
modifier|*
name|mg_ptr
decl_stmt|;
name|I32
name|mg_len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MGf_TAINTEDDIR
value|1
end_define

begin_define
define|#
directive|define
name|MGf_REFCOUNTED
value|2
end_define

begin_define
define|#
directive|define
name|MGf_GSKIP
value|4
end_define

begin_define
define|#
directive|define
name|MGf_MINMATCH
value|1
end_define

begin_define
define|#
directive|define
name|MgTAINTEDDIR
parameter_list|(
name|mg
parameter_list|)
value|(mg->mg_flags& MGf_TAINTEDDIR)
end_define

begin_define
define|#
directive|define
name|MgTAINTEDDIR_on
parameter_list|(
name|mg
parameter_list|)
value|(mg->mg_flags |= MGf_TAINTEDDIR)
end_define

begin_define
define|#
directive|define
name|MgTAINTEDDIR_off
parameter_list|(
name|mg
parameter_list|)
value|(mg->mg_flags&= ~MGf_TAINTEDDIR)
end_define

begin_define
define|#
directive|define
name|MgPV
parameter_list|(
name|mg
parameter_list|,
name|lp
parameter_list|)
value|((((int)(lp = (mg)->mg_len)) == HEf_SVKEY) ?   \ 				 SvPV((SV*)((mg)->mg_ptr),lp) :		\ 				 (mg)->mg_ptr)
end_define

begin_define
define|#
directive|define
name|SvTIED_mg
parameter_list|(
name|sv
parameter_list|,
name|how
parameter_list|)
define|\
value|(SvRMAGICAL(sv) ? mg_find((sv),(how)) : Null(MAGIC*))
end_define

begin_define
define|#
directive|define
name|SvTIED_obj
parameter_list|(
name|sv
parameter_list|,
name|mg
parameter_list|)
define|\
value|((mg)->mg_obj ? (mg)->mg_obj : sv_2mortal(newRV(sv)))
end_define

end_unit

