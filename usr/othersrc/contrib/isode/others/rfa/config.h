begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RFA - Remote File Access  *  * Access and Management for a partial file system tree that exists  * at two sites either as master files or slave files  *  * Contributed by Oliver Wenzel 1990  *  * config.h - installation dependant configuration  *  * $Header: /f/osi/others/rfa/RCS/config.h,v 7.3 91/02/22 09:27:49 mrose Interim $  *  * $Log:	config.h,v $  * Revision 7.3  91/02/22  09:27:49  mrose  * Interim 6.8  *   * Revision 7.2  91/01/14  13:54:24  mrose  * update  *  Revision 1.1  91/01/04  16:25:12  ow Initial revision   */
end_comment

begin_comment
comment|/*  *                              NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/*--- default root for RFA tree (can be changed at runtime) ---*/
end_comment

begin_define
define|#
directive|define
name|FS_BASE
value|"/usr/something"
end_define

begin_comment
comment|/*--- dir where isotailor and .rfarc files are expected ---*/
end_comment

begin_define
define|#
directive|define
name|RFA_TAILDIR
value|"/usr/local/isode/etc"
end_define

begin_comment
comment|/*--- number of secs. for sending the time during the timeSync operation ---*/
end_comment

begin_define
define|#
directive|define
name|SENDTIME_DELAY
value|1
end_define

begin_comment
comment|/*--- default limit for filesize when compression of file shall occur.        (can be changed at runtime) ---*/
end_comment

begin_define
define|#
directive|define
name|COMPRESSLIMIT
value|4500
end_define

begin_comment
comment|/*--- Will be calculated as follows:  	     C0 : time required to start compress process 	     U0 : time required to start compress process 	     C	: time required to compress 1K data 	     U	: time required to compress 1K data 	     T	: time required to transfer 1K data 	     FC : factor by which the data size is reduced by compression 	     L  : Limit when data should be transfered compressed  	           FC * (C0 + U0)  	     L = --------------------------- 		  (FC - 1) * T - FC * (U + C)  	     With:  		  C0 = 1s 		  CU = 1s 		  C  = 1/50s (1/100 on Sparc with load = 1) 		  U  = 1/70s (1/140 on Sparc with load = 1) 		  T  = 8/10 s (X.25) 		  FC = 2.5  		  then  L =  4.48 Kbytes  ---*/
end_comment

end_unit

