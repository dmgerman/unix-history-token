begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * vint64ops.h - operations on 'vint64' values  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  * ----------------------------------------------------------------------  * This is an attempt to get the vint64 calculations stuff centralised.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VINT64OPS_H
end_ifndef

begin_define
define|#
directive|define
name|VINT64OPS_H
end_define

begin_comment
comment|/* signed/unsigned compare. returns 1/0/-1 if lhs>/=/< rhs */
end_comment

begin_function_decl
specifier|extern
name|int
name|icmpv64
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
specifier|const
name|vint64
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ucmpv64
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
specifier|const
name|vint64
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* add / subtract */
end_comment

begin_function_decl
specifier|extern
name|vint64
name|addv64
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
specifier|const
name|vint64
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vint64
name|addv64i32
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
name|int32_t
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vint64
name|addv64u32
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
name|uint32_t
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vint64
name|subv64
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
specifier|const
name|vint64
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vint64
name|subv64i32
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
name|int32_t
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|vint64
name|subv64u32
parameter_list|(
specifier|const
name|vint64
modifier|*
name|lhs
parameter_list|,
name|uint32_t
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parsing. works like strtoul() or strtoull() */
end_comment

begin_function_decl
specifier|extern
name|vint64
name|strtouv64
parameter_list|(
specifier|const
name|char
modifier|*
name|begp
parameter_list|,
name|char
modifier|*
modifier|*
name|endp
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!defined(VINT64OPS_H)*/
end_comment

end_unit

