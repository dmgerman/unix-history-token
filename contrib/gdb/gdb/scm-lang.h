begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|SICP
end_define

begin_include
include|#
directive|include
file|"scm-tags.h"
end_include

begin_undef
undef|#
directive|undef
name|SCM_NCELLP
end_undef

begin_define
define|#
directive|define
name|SCM_NCELLP
parameter_list|(
name|x
parameter_list|)
value|((SCM_SIZE-1)& (int)(x))
end_define

begin_define
define|#
directive|define
name|SCM_ITAG8_DATA
parameter_list|(
name|X
parameter_list|)
value|((X)>>8)
end_define

begin_define
define|#
directive|define
name|SCM_ICHR
parameter_list|(
name|x
parameter_list|)
value|((unsigned char)SCM_ITAG8_DATA(x))
end_define

begin_define
define|#
directive|define
name|SCM_ICHRP
parameter_list|(
name|x
parameter_list|)
value|(SCM_ITAG8(x) == scm_tc8_char)
end_define

begin_define
define|#
directive|define
name|scm_tc8_char
value|0xf4
end_define

begin_define
define|#
directive|define
name|SCM_IFLAGP
parameter_list|(
name|n
parameter_list|)
value|((0x87& (int)(n))==4)
end_define

begin_define
define|#
directive|define
name|SCM_ISYMNUM
parameter_list|(
name|n
parameter_list|)
value|((int)((n)>>9))
end_define

begin_define
define|#
directive|define
name|SCM_ISYMCHARS
parameter_list|(
name|n
parameter_list|)
value|(scm_isymnames[SCM_ISYMNUM(n)])
end_define

begin_define
define|#
directive|define
name|SCM_ILOCP
parameter_list|(
name|n
parameter_list|)
value|((0xff& (int)(n))==0xfc)
end_define

begin_define
define|#
directive|define
name|SCM_ITAG8
parameter_list|(
name|X
parameter_list|)
value|((int)(X)& 0xff)
end_define

begin_define
define|#
directive|define
name|SCM_TYP7
parameter_list|(
name|x
parameter_list|)
value|(0x7f& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_LENGTH
parameter_list|(
name|x
parameter_list|)
value|(((unsigned long)SCM_CAR(x))>>8)
end_define

begin_define
define|#
directive|define
name|SCM_NCONSP
parameter_list|(
name|x
parameter_list|)
value|(1& (int)SCM_CAR(x))
end_define

begin_define
define|#
directive|define
name|SCM_NECONSP
parameter_list|(
name|x
parameter_list|)
value|(SCM_NCONSP(x)&& (1 != SCM_TYP3(x)))
end_define

begin_define
define|#
directive|define
name|SCM_CAR
parameter_list|(
name|x
parameter_list|)
value|scm_get_field (x, 0)
end_define

begin_define
define|#
directive|define
name|SCM_CDR
parameter_list|(
name|x
parameter_list|)
value|scm_get_field (x, 1)
end_define

begin_define
define|#
directive|define
name|SCM_VELTS
parameter_list|(
name|x
parameter_list|)
value|((SCM *)SCM_CDR(x))
end_define

begin_define
define|#
directive|define
name|SCM_CLOSCAR
parameter_list|(
name|x
parameter_list|)
value|(SCM_CAR(x)-scm_tc3_closure)
end_define

begin_define
define|#
directive|define
name|SCM_CODE
parameter_list|(
name|x
parameter_list|)
value|SCM_CAR(SCM_CLOSCAR (x))
end_define

begin_define
define|#
directive|define
name|SCM_MAKINUM
parameter_list|(
name|x
parameter_list|)
value|(((x)<<2)+2L)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Forward decls for prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|scm_value_print
name|PARAMS
argument_list|(
operator|(
expr|struct
name|value
operator|*
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scm_val_print
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LONGEST
name|scm_get_field
name|PARAMS
argument_list|(
operator|(
name|LONGEST
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|scm_scmval_print
name|PARAMS
argument_list|(
operator|(
name|LONGEST
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|is_scmvalue_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|scm_printchar
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|GDB_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|value
modifier|*
name|scm_evaluate_string
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|builtin_type_scm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scm_parse
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LONGEST
name|scm_unpack
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
expr|enum
name|type_code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

