begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** jmp.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	jmp.h,v $  * Revision 5.1  91/12/05  07:59:24  brennan  * 1.1 pre-release  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JMP_H
end_ifndef

begin_define
define|#
directive|define
name|JMP_H
end_define

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|BC_new
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|BC_insert
argument_list|,
operator|(
name|int
operator|,
name|INST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|BC_clear
argument_list|,
operator|(
name|INST
operator|*
operator|,
name|INST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|code_push
argument_list|,
operator|(
name|INST
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|PROTO
argument_list|(
name|code_pop
argument_list|,
operator|(
name|INST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|code_jmp
argument_list|,
operator|(
name|int
operator|,
name|INST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|patch_jmp
argument_list|,
operator|(
name|INST
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JMP_H  */
end_comment

end_unit

