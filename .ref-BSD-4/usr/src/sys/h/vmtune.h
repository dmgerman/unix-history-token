begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vmtune.h	4.1	11/9/80	*/
end_comment

begin_comment
comment|/*  * Tunable performance parameters  *  * These may vary per-cpu due to configuration as well as the flavor of  * the local job mix.  MAXPGIO in multiplied by the number of swap devices  * available (nswdev) at boot time.  */
end_comment

begin_define
define|#
directive|define
name|LOOPSIZ
value|((maxfree - firstfree) / CLSIZE)
end_define

begin_comment
comment|/* loop circumference */
end_comment

begin_define
define|#
directive|define
name|LOTSFREE
value|((maxfree - firstfree) / 4)
end_define

begin_comment
comment|/* very high mark to freeze scans */
end_comment

begin_define
define|#
directive|define
name|DESFREE
value|200
end_define

begin_comment
comment|/* minimum desirable free memory */
end_comment

begin_define
define|#
directive|define
name|MINFREE
value|64
end_define

begin_comment
comment|/* water mark to run swap daemon */
end_comment

begin_define
define|#
directive|define
name|MAXSLP
value|20
end_define

begin_comment
comment|/* max blocked time (in seconds) allowed 					   before being very swappable */
end_comment

begin_define
define|#
directive|define
name|SLOWSCAN
value|25
end_define

begin_comment
comment|/* seconds per loop when memory easy */
end_comment

begin_define
define|#
directive|define
name|FASTSCAN
value|15
end_define

begin_comment
comment|/* seconds per loop when memory tight */
end_comment

begin_define
define|#
directive|define
name|SAFERSS
value|32
end_define

begin_comment
comment|/* nominal ``small'' resident set size 					   protected against replacement */
end_comment

begin_define
define|#
directive|define
name|MAXPGIO
value|50
end_define

begin_comment
comment|/* max desired paging i/o per second 					   per paging device, controls max 					   paging ops per second */
end_comment

begin_comment
comment|/* WITH MAXPGIO SET TO 50, IT RARELY TAKES OVER */
end_comment

end_unit

