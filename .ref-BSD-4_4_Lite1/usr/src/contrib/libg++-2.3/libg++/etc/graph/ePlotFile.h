begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|ePlotFile_h
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_define
define|#
directive|define
name|ePlotFile_h
value|1
end_define

begin_include
include|#
directive|include
file|<PlotFile.h>
end_include

begin_comment
comment|// ePlotFile is an extended plot file class which has adjusted labels.
end_comment

begin_comment
comment|// put the left center or right edge of the text at the current point.
end_comment

begin_typedef
typedef|typedef
enum|enum
name|alabel_xadj
block|{
name|LEFT_JUSTIFY
init|=
literal|'l'
block|,
name|CENTER_JUSTIFY
init|=
literal|'c'
block|,
name|RIGHT_JUSTIFY
init|=
literal|'r'
block|}
empty_stmt|;
end_typedef

begin_comment
comment|// put the top center or bottom edge of the text at the current point.
end_comment

begin_typedef
typedef|typedef
enum|enum
name|alabel_yadj
block|{
name|BOTTOM_FLUSH
init|=
literal|'b'
block|,
name|CENTER_FLUSH
init|=
literal|'c'
block|,
name|TOP_FLUSH
init|=
literal|'t'
block|}
empty_stmt|;
end_typedef

begin_decl_stmt
name|class
name|ePlotFile
range|:
name|public
name|PlotFile
block|{
name|public
operator|:
name|ePlotFile
argument_list|()
operator|:
name|PlotFile
argument_list|()
block|{}
ifndef|#
directive|ifndef
name|_OLD_STREAMS
name|ePlotFile
argument_list|(
argument|int fd
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|fd
argument_list|)
block|{ }
name|ePlotFile
argument_list|(
argument|const char *name
argument_list|,
argument|int mode=ios::out
argument_list|,
argument|int prot=
literal|0664
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|name
argument_list|,
argument|mode
argument_list|,
argument|prot
argument_list|)
block|{ }
else|#
directive|else
name|ePlotFile
argument_list|(
argument|const char* filename
argument_list|,
argument|io_mode m
argument_list|,
argument|access_mode a
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|filename
argument_list|,
argument|m
argument_list|,
argument|a
argument_list|)
block|{}
name|ePlotFile
argument_list|(
specifier|const
name|char
operator|*
name|filename
argument_list|,
specifier|const
name|char
operator|*
name|m
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|filename
argument_list|,
argument|m
argument_list|)
block|{}
name|ePlotFile
argument_list|(
argument|int filedesc
argument_list|,
argument|io_mode m = io_writeonly
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|filedesc
argument_list|,
argument|m
argument_list|)
block|{}
name|ePlotFile
argument_list|(
name|FILE
operator|*
name|fileptr
argument_list|)
operator|:
name|PlotFile
argument_list|(
argument|fileptr
argument_list|)
block|{}
endif|#
directive|endif
name|ePlotFile
operator|&
name|alabel
argument_list|(
argument|alabel_xadj x_adjust
argument_list|,
argument|alabel_yadj y_adjust
argument_list|,
argument|char *s
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

