begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmklust.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Klustering constants.  Klustering is the gathering  * of pages together for pagein/pageout, while clustering  * is the treatment of hardware page size as though it were  * larger than it really is.  *  * KLMAX gives maximum cluster size in CLSIZE page (cluster-page)  * units.  Note that KLMAX*CLSIZE must be<= DMMIN in dmap.h.  */
end_comment

begin_define
define|#
directive|define
name|KLMAX
value|(16/CLSIZE)
end_define

begin_define
define|#
directive|define
name|KLIN
value|(4/CLSIZE)
end_define

begin_comment
comment|/* Read up to 4 pages */
end_comment

begin_define
define|#
directive|define
name|KLOUT
value|(16/CLSIZE)
end_define

begin_comment
comment|/* Write up to 16 pages */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|klin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|klout
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

