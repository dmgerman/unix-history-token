begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* readfile.h */
end_comment

begin_include
include|#
directive|include
file|"bptypes.h"
end_include

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|boolean
name|hwlookcmp
name|P
argument_list|(
operator|(
name|hash_datum
operator|*
operator|,
name|hash_datum
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|iplookcmp
name|P
argument_list|(
operator|(
name|hash_datum
operator|*
operator|,
name|hash_datum
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|nmcmp
name|P
argument_list|(
operator|(
name|hash_datum
operator|*
operator|,
name|hash_datum
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|readtab
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rdtab_init
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|P
end_undef

end_unit

