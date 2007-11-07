begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $OpenBSD: pgp.h,v 1.2 1999/10/04 21:46:28 espie Exp $ */
end_comment

begin_comment
comment|/* Estimate size of pgp signature */
end_comment

begin_define
define|#
directive|define
name|MAXPGPSIGNSIZE
value|1024
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PGP
end_ifndef

begin_define
define|#
directive|define
name|PGP
value|"/usr/local/bin/pgp"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|mygzip_header
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|signature
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|new_pgp_checker
parameter_list|(
name|struct
name|mygzip_header
modifier|*
name|h
parameter_list|, \
name|struct
name|signature
modifier|*
name|sign
parameter_list|,
specifier|const
name|char
modifier|*
name|userid
parameter_list|,
name|char
modifier|*
name|envp
index|[]
parameter_list|, \
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pgp_add
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
specifier|const
name|char
modifier|*
name|buffer
parameter_list|, \
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pgp_sign_ok
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|handle_pgp_passphrase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|retrieve_pgp_signature
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|, \
name|struct
name|signature
modifier|*
modifier|*
name|sign
parameter_list|,
specifier|const
name|char
modifier|*
name|userid
parameter_list|,
name|char
modifier|*
name|envp
index|[]
parameter_list|)
function_decl|;
end_function_decl

end_unit

