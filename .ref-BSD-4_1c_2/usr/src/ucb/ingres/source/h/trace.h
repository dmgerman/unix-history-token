begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  TRACE.H -- conditional compilation flags ** **	Some of these may be commented out to set them to "off". **	The comment should be removed to set them to "on". ** **	Version: **		@(#)trace.h	7.1	2/5/81 */
end_comment

begin_comment
comment|/* access methods compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xATM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xATR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xATR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xATR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* decomposition compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xDTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xDTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xDTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xDTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* EQUEL compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xETM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xETR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xETR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xETR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* monitor compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xMTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xMTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xMTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xMTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* OVQP compilatiion flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xOTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xOTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xOTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xOTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* parser compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xPTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xPTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xPTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xPTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* qrymod compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xQTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xQTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xQTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xQTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* scanner compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xSTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xSTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xSTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xSTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* DBU compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xZTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xZTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xZTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xZTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* support compilation flags */
end_comment

begin_comment
comment|/*	disable timing information # define	xTTM		/* timing information */
end_comment

begin_define
define|#
directive|define
name|xTTR1
end_define

begin_comment
comment|/* trace info, level 1 */
end_comment

begin_define
define|#
directive|define
name|xTTR2
end_define

begin_comment
comment|/* trace info, level 2, implies xTR1 */
end_comment

begin_define
define|#
directive|define
name|xTTR3
end_define

begin_comment
comment|/* trace info, level 3, implies xTR1& xTR2 */
end_comment

begin_comment
comment|/* **  Inline expansion for trace flags */
end_comment

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|tT
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|tTf
end_ifndef

begin_define
define|#
directive|define
name|tTf
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((b< 0) ? tT[a] : (tT[a]& (1<< b)))
end_define

begin_endif
endif|#
directive|endif
endif|tTf
end_endif

end_unit

