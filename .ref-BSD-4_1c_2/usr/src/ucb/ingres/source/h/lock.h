begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  LOCK.H -- Concurency structs and global variables ** **	Version: **		@(#)lock.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KEYSIZE
end_ifndef

begin_define
define|#
directive|define
name|M_SHARE
value|2
end_define

begin_define
define|#
directive|define
name|M_EXCL
value|1
end_define

begin_define
define|#
directive|define
name|T_CS
value|0
end_define

begin_define
define|#
directive|define
name|T_PAGE
value|1
end_define

begin_define
define|#
directive|define
name|T_REL
value|2
end_define

begin_define
define|#
directive|define
name|T_DB
value|3
end_define

begin_define
define|#
directive|define
name|A_RTN
value|1
end_define

begin_define
define|#
directive|define
name|A_SLP
value|2
end_define

begin_define
define|#
directive|define
name|A_RLS1
value|3
end_define

begin_define
define|#
directive|define
name|A_RLSA
value|4
end_define

begin_define
define|#
directive|define
name|KEYSIZE
value|12
end_define

begin_struct
struct|struct
name|lockreq
block|{
name|char
name|lract
decl_stmt|;
comment|/* requested action 					 *	=1 request lock,err return 					 *	=2 request lock,sleep 					 *	=3 release lock 					 *	=release all locks for pid 					 */
name|char
name|lrtype
decl_stmt|;
comment|/* type of lock: 					 *   =0, critical section lock 					 *   =1, page lock 					 *   =2, logical lock 					 *   =3, data base lock 					 */
name|char
name|lrmod
decl_stmt|;
comment|/* mode of lock 					 *	=1 exclusive lock 					 *	=2 shared lock 					*/
comment|/* key for the lock */
name|char
name|dbnode
index|[
literal|4
index|]
decl_stmt|;
comment|/* inode of data base */
name|char
name|lrel
index|[
literal|4
index|]
decl_stmt|;
comment|/* relation tid */
name|char
name|lpage
index|[
literal|4
index|]
decl_stmt|;
comment|/* page address		*/
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|Acclock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* locks enabled flag */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Alockdes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for lock device*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Lockrel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock relations flag*/
end_comment

begin_endif
endif|#
directive|endif
endif|KEYSIZE
end_endif

end_unit

