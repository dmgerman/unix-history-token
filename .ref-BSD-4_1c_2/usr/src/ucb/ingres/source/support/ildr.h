begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  ILDR.H -- header file for INGRES lock driver. ** **	@(#)ildr.h	7.1	2/5/81 */
end_comment

begin_define
define|#
directive|define
name|KEYSIZE
value|12
end_define

begin_define
define|#
directive|define
name|DLOCKS
value|10
end_define

begin_comment
comment|/* max number of data base locks (limits # of ingreses */
end_comment

begin_define
define|#
directive|define
name|RLOCKS
value|2*DLOCKS + 6
end_define

begin_define
define|#
directive|define
name|PLOCKS
value|RLOCKS + 3
end_define

begin_define
define|#
directive|define
name|NLOCKS
value|PLOCKS + 1
end_define

begin_define
define|#
directive|define
name|LOCKPRI
value|1
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|M_EMTY
value|0
end_define

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
name|A_ABT
value|5
end_define

begin_define
define|#
directive|define
name|W_ON
value|1
end_define

begin_define
define|#
directive|define
name|W_OFF
value|0
end_define

begin_comment
comment|/*	Device driver for the /dev/ILOCK   *	an in core device used as a Lock table  */
end_comment

begin_comment
comment|/* Only the parameters NLOCKS, PLOCKS, RLOCKS and DLOCKS  * may be changed by an INGRES installation.  See   * 'HOW TO INSTALL CONCURRENCY DEVICE' for details.  * The file can be printed by "nroff .../doc/other/lockdev.nr"  */
end_comment

begin_comment
comment|/*  *	data structure for Lock table  */
end_comment

begin_struct
struct|struct
name|Lockform
block|{
name|int
name|l_pid
decl_stmt|;
name|char
name|l_wflag
decl_stmt|;
comment|/* wait flag: = 1 a process is waiting*/
name|char
name|l_type
decl_stmt|;
comment|/* type of lock: 					= 0 for critical section 					= 1 for page 					= 2 for logical 					= 3 for data base 				*/
name|char
name|l_mod
decl_stmt|;
comment|/* mod of Lock or lock action requested  				 *	= 0 slot empty 				 *	= 1 exclusive lock 				 *	= 2 shared lock 				 */
name|char
name|l_key
index|[
name|KEYSIZE
index|]
decl_stmt|;
block|}
name|Locktab
index|[
name|NLOCKS
index|]
struct|;
end_struct

begin_decl_stmt
name|int
name|Lockset
index|[]
comment|/* array of number of locks which can be 			 * set for each lock. 			 */
block|{
name|NLOCKS
operator|,
name|PLOCKS
operator|,
name|RLOCKS
operator|,
name|DLOCKS
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|Lockreq
comment|/* Lock Request */
block|{
name|int
name|lr_pid
decl_stmt|;
comment|/* requesting process id */
name|char
name|lr_act
decl_stmt|;
comment|/* requested action: 				 *	=1 request lock, err return 				 *	=2 request lock, sleep 				 *	=3 release lock 				 *	=4 release all locks for pid 				 */
name|char
name|lr_type
decl_stmt|;
comment|/* same as Locktab l_type */
name|char
name|lr_mod
decl_stmt|;
comment|/* same as Locktab l_mod */
name|char
name|lr_key
index|[
name|KEYSIZE
index|]
decl_stmt|;
comment|/* requested key	*/
block|}
struct|;
end_struct

end_unit

