begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: B1num.h,v 1.1 84/06/28 00:48:38 timo Exp $ */
end_comment

begin_comment
comment|/* Definitions for number internals */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|p
decl_stmt|,
name|q
decl_stmt|;
block|}
name|number
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|double
name|integer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Zero
value|((integer) 0)
end_define

begin_define
define|#
directive|define
name|One
value|((integer) 1)
end_define

begin_define
define|#
directive|define
name|Two
value|((integer) 2)
end_define

begin_define
define|#
directive|define
name|Checknum
parameter_list|(
name|v
parameter_list|)
value|if ((v)->type != Num) error("value not a number")
end_define

begin_define
define|#
directive|define
name|Numerator
parameter_list|(
name|v
parameter_list|)
value|((integer) ((number *)Ats(v))->p)
end_define

begin_define
define|#
directive|define
name|Denominator
parameter_list|(
name|v
parameter_list|)
value|((integer) ((number *)Ats(v))->q)
end_define

begin_define
define|#
directive|define
name|Exact
parameter_list|(
name|v
parameter_list|)
value|(((number *)Ats(v))->q != Zero)
end_define

begin_define
define|#
directive|define
name|Integral
parameter_list|(
name|v
parameter_list|)
value|(Exact(v)&& (Denominator(v)==One))
end_define

begin_define
define|#
directive|define
name|Approxval
parameter_list|(
name|v
parameter_list|)
value|(((number *)Ats(v))->p)
end_define

begin_define
define|#
directive|define
name|Numval
parameter_list|(
name|v
parameter_list|)
value|(Exact(v) ? Numerator(v)/Denominator(v) : Approxval(v))
end_define

begin_function_decl
name|value
name|mk_int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_approx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|mk_exact
parameter_list|()
function_decl|;
end_function_decl

end_unit

