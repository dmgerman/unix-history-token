begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /f/osi/others/quipu/uips/xd/RCS/filt.h,v 7.1 91/02/22 09:32:48 mrose Interim $ */
end_comment

begin_comment
comment|/*  $Log:	filt.h,v $  * Revision 7.1  91/02/22  09:32:48  mrose  * Interim 6.8  *   * Revision 7.0  90/06/12  13:10:55  mrose  * *** empty log message ***  *   * Revision 1.5  90/04/26  10:22:41  emsrssn  * Installation fixed  *   *   * Revision 1.4  90/04/25  17:28:11  emsrssn  * Lint tidy up  *   *   * Revision 1.3  90/04/19  13:54:12  emsrssn  * keyboard accelerator now activates button highlight.  *   * search types available is dependent on current position  * to prevent unreasonable searches.  *   * the help popup changes automatically depending on the   * position of the cursor  *   * buttons remain a fixed size when the application is  * resized  *   * command line options are now handled properly  *   * logging added  *   * "reads" are now sorted to show mail address at top etc.  *   *   * Revision 1.2  90/03/09  15:57:31  emsrssn  * First public distribution  *   *   * Revision 1.1  90/03/08  13:18:46  emsrssn  * Initial revision  *   *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FILT
end_ifndef

begin_define
define|#
directive|define
name|FILT
end_define

begin_typedef
typedef|typedef
struct|struct
name|stroid_list
block|{
name|int
name|fi_type
decl_stmt|;
name|char
modifier|*
name|stroid
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|filt_item
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|filter_struct
block|{
name|int
name|flt_type
decl_stmt|;
union|union
name|ftype
block|{
name|filt_item
name|item
decl_stmt|;
name|struct
name|filter_struct
modifier|*
name|sub_filt
decl_stmt|;
block|}
name|fu_cont
union|;
name|struct
name|filter_struct
modifier|*
name|next
decl_stmt|;
block|}
name|filt_struct
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

