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

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|new_pgp_checker
name|__P
argument_list|(
operator|(
expr|struct
name|mygzip_header
operator|*
name|h
operator|,
expr|\ 	struct
name|signature
operator|*
name|sign
operator|,
specifier|const
name|char
operator|*
name|userid
operator|,
name|char
operator|*
name|envp
index|[]
operator|,
expr|\
specifier|const
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pgp_add
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|,
specifier|const
name|char
operator|*
name|buffer
operator|,
expr|\
name|size_t
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pgp_sign_ok
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|handle_pgp_passphrase
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|retrieve_pgp_signature
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|filename
operator|,
expr|\ struct
name|signature
operator|*
operator|*
name|sign
operator|,
specifier|const
name|char
operator|*
name|userid
operator|,
name|char
operator|*
name|envp
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

