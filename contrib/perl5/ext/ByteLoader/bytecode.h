begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|char
modifier|*
name|pvcontents
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|strconst
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|U32
name|PV
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|op_tr_array
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|comment_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SV
modifier|*
name|svindex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|OP
modifier|*
name|opindex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|pvindex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IV
name|IV64
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BGET_FREAD
parameter_list|(
name|argp
parameter_list|,
name|len
parameter_list|,
name|nelem
parameter_list|)
define|\
value|bl_read(bstate->bs_fdata,(char*)(argp),(len),(nelem))
end_define

begin_define
define|#
directive|define
name|BGET_FGETC
parameter_list|()
value|bl_getc(bstate->bs_fdata)
end_define

begin_define
define|#
directive|define
name|BGET_U32
parameter_list|(
name|arg
parameter_list|)
define|\
value|BGET_FREAD(&arg, sizeof(U32), 1)
end_define

begin_define
define|#
directive|define
name|BGET_I32
parameter_list|(
name|arg
parameter_list|)
define|\
value|BGET_FREAD(&arg, sizeof(I32), 1)
end_define

begin_define
define|#
directive|define
name|BGET_U16
parameter_list|(
name|arg
parameter_list|)
define|\
value|BGET_FREAD(&arg, sizeof(U16), 1)
end_define

begin_define
define|#
directive|define
name|BGET_U8
parameter_list|(
name|arg
parameter_list|)
value|arg = BGET_FGETC()
end_define

begin_define
define|#
directive|define
name|BGET_PV
parameter_list|(
name|arg
parameter_list|)
value|STMT_START {					\ 	BGET_U32(arg);							\ 	if (arg) {							\ 	    New(666, bstate->bs_pv.xpv_pv, arg, char);			\ 	    bl_read(bstate->bs_fdata, (void*)bstate->bs_pv.xpv_pv, arg, 1);	\ 	    bstate->bs_pv.xpv_len = arg;				\ 	    bstate->bs_pv.xpv_cur = arg - 1;				\ 	} else {							\ 	    bstate->bs_pv.xpv_pv = 0;					\ 	    bstate->bs_pv.xpv_len = 0;					\ 	    bstate->bs_pv.xpv_cur = 0;					\ 	}								\     } STMT_END
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BYTELOADER_LOG_COMMENTS
end_ifdef

begin_define
define|#
directive|define
name|BGET_comment_t
parameter_list|(
name|arg
parameter_list|)
define|\
value|STMT_START {							\ 	char buf[1024];							\ 	int i = 0;							\ 	do {								\ 	    arg = BGET_FGETC();						\ 	    buf[i++] = (char)arg;					\ 	} while (arg != '\n'&& arg != EOF);				\ 	buf[i] = '\0';							\ 	PerlIO_printf(PerlIO_stderr(), "%s", buf);			\     } STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BGET_comment_t
parameter_list|(
name|arg
parameter_list|)
define|\
value|do { arg = BGET_FGETC(); } while (arg != '\n'&& arg != EOF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * In the following, sizeof(IV)*4 is just a way of encoding 32 on 64-bit-IV  * machines such that 32-bit machine compilers don't whine about the shift  * count being too high even though the code is never reached there.  */
end_comment

begin_define
define|#
directive|define
name|BGET_IV64
parameter_list|(
name|arg
parameter_list|)
value|STMT_START {			\ 	U32 hi, lo;					\ 	BGET_U32(hi);					\ 	BGET_U32(lo);					\ 	if (sizeof(IV) == 8)				\ 	    arg = ((IV)hi<< (sizeof(IV)*4) | (IV)lo);	\ 	else if (((I32)hi == -1&& (I32)lo< 0)		\ 		 || ((I32)hi == 0&& (I32)lo>= 0)) {	\ 	    arg = (I32)lo;				\ 	}						\ 	else {						\ 	    bstate->bs_iv_overflows++;			\ 	    arg = 0;					\ 	}						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BGET_op_tr_array
parameter_list|(
name|arg
parameter_list|)
value|do {			\ 	unsigned short *ary;				\ 	int i;						\ 	New(666, ary, 256, unsigned short);		\ 	BGET_FREAD(ary, sizeof(unsigned short), 256);	\ 	arg = (char *) ary;				\     } while (0)
end_define

begin_define
define|#
directive|define
name|BGET_pvcontents
parameter_list|(
name|arg
parameter_list|)
value|arg = bstate->bs_pv.xpv_pv
end_define

begin_define
define|#
directive|define
name|BGET_strconst
parameter_list|(
name|arg
parameter_list|)
value|STMT_START {	\ 	for (arg = PL_tokenbuf; (*arg = BGET_FGETC()); arg++)
comment|/* nothing */
value|; \ 	arg = PL_tokenbuf;			\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BGET_NV
parameter_list|(
name|arg
parameter_list|)
value|STMT_START {	\ 	char *str;			\ 	BGET_strconst(str);		\ 	arg = Atof(str);		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BGET_objindex
parameter_list|(
name|arg
parameter_list|,
name|type
parameter_list|)
value|STMT_START {	\ 	BGET_U32(ix);				\ 	arg = (type)bstate->bs_obj_list[ix];	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BGET_svindex
parameter_list|(
name|arg
parameter_list|)
value|BGET_objindex(arg, svindex)
end_define

begin_define
define|#
directive|define
name|BGET_opindex
parameter_list|(
name|arg
parameter_list|)
value|BGET_objindex(arg, opindex)
end_define

begin_define
define|#
directive|define
name|BGET_pvindex
parameter_list|(
name|arg
parameter_list|)
value|STMT_START {			\ 	BGET_objindex(arg, pvindex);			\ 	arg = arg ? savepv(arg) : arg;			\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_ldspecsv
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|sv = specialsv_list[arg]
end_define

begin_define
define|#
directive|define
name|BSET_stpv
parameter_list|(
name|pv
parameter_list|,
name|arg
parameter_list|)
value|STMT_START {		\ 	BSET_OBJ_STORE(pv, arg);		\ 	SAVEFREEPV(pv);				\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_sv_refcnt_add
parameter_list|(
name|svrefcnt
parameter_list|,
name|arg
parameter_list|)
value|svrefcnt += arg
end_define

begin_define
define|#
directive|define
name|BSET_gp_refcnt_add
parameter_list|(
name|gprefcnt
parameter_list|,
name|arg
parameter_list|)
value|gprefcnt += arg
end_define

begin_define
define|#
directive|define
name|BSET_gp_share
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|STMT_START {	\ 	gp_free((GV*)sv);			\ 	GvGP(sv) = GvGP(arg);			\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_gv_fetchpv
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|sv = (SV*)gv_fetchpv(arg, TRUE, SVt_PV)
end_define

begin_define
define|#
directive|define
name|BSET_gv_stashpv
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|sv = (SV*)gv_stashpv(arg, TRUE)
end_define

begin_define
define|#
directive|define
name|BSET_sv_magic
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|sv_magic(sv, Nullsv, arg, 0, 0)
end_define

begin_define
define|#
directive|define
name|BSET_mg_pv
parameter_list|(
name|mg
parameter_list|,
name|arg
parameter_list|)
value|mg->mg_ptr = arg; mg->mg_len = bstate->bs_pv.xpv_cur
end_define

begin_define
define|#
directive|define
name|BSET_sv_upgrade
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|(void)SvUPGRADE(sv, arg)
end_define

begin_define
define|#
directive|define
name|BSET_xpv
parameter_list|(
name|sv
parameter_list|)
value|do {	\ 	SvPV_set(sv, bstate->bs_pv.xpv_pv);	\ 	SvCUR_set(sv, bstate->bs_pv.xpv_cur);	\ 	SvLEN_set(sv, bstate->bs_pv.xpv_len);	\     } while (0)
end_define

begin_define
define|#
directive|define
name|BSET_av_extend
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|av_extend((AV*)sv, arg)
end_define

begin_define
define|#
directive|define
name|BSET_av_push
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
value|av_push((AV*)sv, arg)
end_define

begin_define
define|#
directive|define
name|BSET_hv_store
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
define|\
value|hv_store((HV*)sv, bstate->bs_pv.xpv_pv, bstate->bs_pv.xpv_cur, arg, 0)
end_define

begin_define
define|#
directive|define
name|BSET_pv_free
parameter_list|(
name|pv
parameter_list|)
value|Safefree(pv.xpv_pv)
end_define

begin_define
define|#
directive|define
name|BSET_pregcomp
parameter_list|(
name|o
parameter_list|,
name|arg
parameter_list|)
define|\
value|((PMOP*)o)->op_pmregexp = arg ? \ 		CALLREGCOMP(aTHX_ arg, arg + bstate->bs_pv.xpv_cur, ((PMOP*)o)) : 0
end_define

begin_define
define|#
directive|define
name|BSET_newsv
parameter_list|(
name|sv
parameter_list|,
name|arg
parameter_list|)
define|\
value|STMT_START {					\ 	    sv = (arg == SVt_PVAV ? (SV*)newAV() :	\ 		  arg == SVt_PVHV ? (SV*)newHV() :	\ 		  NEWSV(666,0));			\ 	    SvUPGRADE(sv, arg);				\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_newop
parameter_list|(
name|o
parameter_list|,
name|arg
parameter_list|)
value|((o = (OP*)safemalloc(optype_size[arg])), \ 				 memzero((char*)o,optype_size[arg]))
end_define

begin_define
define|#
directive|define
name|BSET_newopn
parameter_list|(
name|o
parameter_list|,
name|arg
parameter_list|)
value|STMT_START {	\ 	OP *oldop = o;				\ 	BSET_newop(o, arg);			\ 	oldop->op_next = o;			\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_ret
parameter_list|(
name|foo
parameter_list|)
value|STMT_START {			\ 	Safefree(bstate->bs_obj_list);			\ 	return;						\     } STMT_END
end_define

begin_comment
comment|/*  * Kludge special-case workaround for OP_MAPSTART  * which needs the ppaddr for OP_GREPSTART. Blech.  */
end_comment

begin_define
define|#
directive|define
name|BSET_op_type
parameter_list|(
name|o
parameter_list|,
name|arg
parameter_list|)
value|STMT_START {	\ 	o->op_type = arg;			\ 	if (arg == OP_MAPSTART)			\ 	    arg = OP_GREPSTART;			\ 	o->op_ppaddr = PL_ppaddr[arg];		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_op_ppaddr
parameter_list|(
name|o
parameter_list|,
name|arg
parameter_list|)
value|Perl_croak(aTHX_ "op_ppaddr not yet implemented")
end_define

begin_define
define|#
directive|define
name|BSET_curpad
parameter_list|(
name|pad
parameter_list|,
name|arg
parameter_list|)
value|STMT_START {	\ 	PL_comppad = (AV *)arg;			\ 	pad = AvARRAY(arg);			\     } STMT_END
end_define

begin_comment
comment|/* this works now that Sarathy's changed the CopFILE_set macro to do the SvREFCNT_inc() 	-- BKS 6-2-2000 */
end_comment

begin_define
define|#
directive|define
name|BSET_cop_file
parameter_list|(
name|cop
parameter_list|,
name|arg
parameter_list|)
value|CopFILE_set(cop,arg)
end_define

begin_define
define|#
directive|define
name|BSET_cop_line
parameter_list|(
name|cop
parameter_list|,
name|arg
parameter_list|)
value|CopLINE_set(cop,arg)
end_define

begin_define
define|#
directive|define
name|BSET_cop_stashpv
parameter_list|(
name|cop
parameter_list|,
name|arg
parameter_list|)
value|CopSTASHPV_set(cop,arg)
end_define

begin_comment
comment|/* this is simply stolen from the code in newATTRSUB() */
end_comment

begin_define
define|#
directive|define
name|BSET_push_begin
parameter_list|(
name|ary
parameter_list|,
name|cv
parameter_list|)
define|\
value|STMT_START {					\ 	    I32 oldscope = PL_scopestack_ix;		\ 	    ENTER;					\ 	    SAVECOPFILE(&PL_compiling);			\ 	    SAVECOPLINE(&PL_compiling);			\ 	    save_svref(&PL_rs);				\ 	    sv_setsv(PL_rs, PL_nrs);			\ 	    if (!PL_beginav)				\ 		PL_beginav = newAV();			\ 	    av_push(PL_beginav, cv);			\ 	    call_list(oldscope, PL_beginav);		\ 	    PL_curcop =&PL_compiling;			\ 	    PL_compiling.op_private = PL_hints;		\ 	    LEAVE;					\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_push_init
parameter_list|(
name|ary
parameter_list|,
name|cv
parameter_list|)
define|\
value|STMT_START {									\ 	    av_unshift((PL_initav ? PL_initav : (PL_initav = newAV(), PL_initav)), 1); 	\ 	    av_store(PL_initav, 0, cv);							\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_push_end
parameter_list|(
name|ary
parameter_list|,
name|cv
parameter_list|)
define|\
value|STMT_START {									\ 	    av_unshift((PL_endav ? PL_endav : (PL_endav = newAV(), PL_endav)), 1);	\ 	    av_store(PL_endav, 0, cv);							\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|BSET_OBJ_STORE
parameter_list|(
name|obj
parameter_list|,
name|ix
parameter_list|)
define|\
value|(I32)ix> bstate->bs_obj_list_fill ?	\ 	bset_obj_store(aTHXo_ bstate, obj, (I32)ix) : (bstate->bs_obj_list[ix] = obj)
end_define

begin_comment
comment|/* NOTE: the bytecode header only sanity-checks the bytecode. If a script cares about  * what version of Perl it's being called under, it should do a 'require 5.6.0' or  * equivalent. However, since the header includes checks requiring an exact match in  * ByteLoader versions (we can't guarantee forward compatibility), you don't   * need to specify one:  * 	use ByteLoader;  * is all you need.  *	-- BKS, June 2000 */
end_comment

begin_define
define|#
directive|define
name|HEADER_FAIL
parameter_list|(
name|f
parameter_list|)
define|\
value|Perl_croak(aTHX_ "Invalid bytecode for this architecture: " f)
end_define

begin_define
define|#
directive|define
name|HEADER_FAIL1
parameter_list|(
name|f
parameter_list|,
name|arg1
parameter_list|)
define|\
value|Perl_croak(aTHX_ "Invalid bytecode for this architecture: " f, arg1)
end_define

begin_define
define|#
directive|define
name|HEADER_FAIL2
parameter_list|(
name|f
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|Perl_croak(aTHX_ "Invalid bytecode for this architecture: " f, arg1, arg2)
end_define

begin_define
define|#
directive|define
name|BYTECODE_HEADER_CHECK
define|\
value|STMT_START {						\ 	    U32 sz = 0;						\ 	    strconst str;					\ 								\ 	    BGET_U32(sz);
comment|/* Magic: 'PLBC' */
value|\ 	    if (sz != 0x43424c50) {				\ 		HEADER_FAIL1("bad magic (want 0x43424c50, got %#x)", (int)sz);		\ 	    }							\ 	    BGET_strconst(str);
comment|/* archname */
value|\ 	    if (strNE(str, ARCHNAME)) {				\ 		HEADER_FAIL2("wrong architecture (want %s, you have %s)",str,ARCHNAME);	\ 	    }							\ 	    BGET_strconst(str);
comment|/* ByteLoader version */
value|\ 	    if (strNE(str, VERSION)) {				\ 		HEADER_FAIL2("mismatched ByteLoader versions (want %s, you have %s)",	\ 			str, VERSION);				\ 	    }							\ 	    BGET_U32(sz);
comment|/* ivsize */
value|\ 	    if (sz != IVSIZE) {					\ 		HEADER_FAIL("different IVSIZE");		\ 	    }							\ 	    BGET_U32(sz);
comment|/* ptrsize */
value|\ 	    if (sz != PTRSIZE) {				\ 		HEADER_FAIL("different PTRSIZE");		\ 	    }							\ 	    BGET_strconst(str);
comment|/* byteorder */
value|\ 	    if (strNE(str, STRINGIFY(BYTEORDER))) {		\ 		HEADER_FAIL("different byteorder");	\ 	    }							\ 	} STMT_END
end_define

end_unit

