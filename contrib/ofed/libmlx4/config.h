begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
modifier|...
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|SWITCH_FALLTHROUGH
value|(void)0
end_define

begin_define
define|#
directive|define
name|ALWAYS_INLINE
value|__attribute__ ((__always_inline__))
end_define

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__predict_true(x)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__predict_false(x)
end_define

end_unit

