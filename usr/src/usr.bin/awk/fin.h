begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** fin.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	fin.h,v $  * Revision 5.2  92/01/06  08:16:24  brennan  * setmode() proto for MSDOS  *   * Revision 5.1  91/12/05  07:59:20  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* fin.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FIN_H
end_ifndef

begin_define
define|#
directive|define
name|FIN_H
end_define

begin_comment
comment|/* structure to control input files */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fd
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* NULL unless interactive */
name|char
modifier|*
name|buff
decl_stmt|;
name|char
modifier|*
name|buffp
decl_stmt|;
name|unsigned
name|nbuffs
decl_stmt|;
comment|/* sizeof *buff in BUFFSZs */
name|int
name|flags
decl_stmt|;
block|}
name|FIN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAIN_FLAG
value|1
end_define

begin_comment
comment|/* part of main input stream if on */
end_comment

begin_define
define|#
directive|define
name|EOF_FLAG
value|2
end_define

begin_define
define|#
directive|define
name|START_FLAG
value|4
end_define

begin_comment
comment|/* used when RS == "" */
end_comment

begin_decl_stmt
name|FIN
modifier|*
name|PROTO
argument_list|(
name|FINdopen
argument_list|,
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FIN
modifier|*
name|PROTO
argument_list|(
name|FINopen
argument_list|,
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
name|void
name|PROTO
argument_list|(
name|FINclose
argument_list|,
operator|(
name|FIN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|FINsemi_close
argument_list|,
operator|(
name|FIN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|FINgets
argument_list|,
operator|(
name|FIN
operator|*
operator|,
name|unsigned
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|PROTO
argument_list|(
name|fillbuff
argument_list|,
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FIN
modifier|*
name|main_fin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for the main input stream */
end_comment

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|open_main
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
name|setmode
argument_list|,
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIN_H */
end_comment

end_unit

