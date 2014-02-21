begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RADEON_TRACE_H
argument_list|)
operator|||
name|defined
argument_list|(
name|TRACE_HEADER_MULTI_READ
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RADEON_TRACE_H_
end_define

begin_include
include|#
directive|include
file|<linux/stringify.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/tracepoint.h>
end_include

begin_include
include|#
directive|include
file|<drm/drmP.h>
end_include

begin_undef
undef|#
directive|undef
name|TRACE_SYSTEM
end_undef

begin_define
define|#
directive|define
name|TRACE_SYSTEM
value|radeon
end_define

begin_define
define|#
directive|define
name|TRACE_SYSTEM_STRING
value|__stringify(TRACE_SYSTEM)
end_define

begin_define
define|#
directive|define
name|TRACE_INCLUDE_FILE
value|radeon_trace
end_define

begin_macro
name|TRACE_EVENT
argument_list|(
argument|radeon_bo_create
argument_list|,
argument|TP_PROTO(struct radeon_bo *bo)
argument_list|,
argument|TP_ARGS(bo)
argument_list|,
argument|TP_STRUCT__entry( 			     __field(struct radeon_bo *, bo) 			     __field(u32, pages) 			     )
argument_list|,
argument|TP_fast_assign( 			   __entry->bo = bo; 			   __entry->pages = bo->tbo.num_pages; 			   )
argument_list|,
argument|TP_printk(
literal|"bo=%p, pages=%u"
argument|, __entry->bo, __entry->pages)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|DECLARE_EVENT_CLASS
argument_list|(
argument|radeon_fence_request
argument_list|,
argument|TP_PROTO(struct drm_device *dev, u32 seqno)
argument_list|,
argument|TP_ARGS(dev, seqno)
argument_list|,
argument|TP_STRUCT__entry( 			     __field(u32, dev) 			     __field(u32, seqno) 			     )
argument_list|,
argument|TP_fast_assign( 			   __entry->dev = dev->primary->index; 			   __entry->seqno = seqno; 			   )
argument_list|,
argument|TP_printk(
literal|"dev=%u, seqno=%u"
argument|, __entry->dev, __entry->seqno)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DEFINE_EVENT
argument_list|(
name|radeon_fence_request
argument_list|,
name|radeon_fence_emit
argument_list|,
name|TP_PROTO
argument_list|(
argument|struct drm_device *dev
argument_list|,
argument|u32 seqno
argument_list|)
argument_list|,
name|TP_ARGS
argument_list|(
name|dev
argument_list|,
name|seqno
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_EVENT
argument_list|(
name|radeon_fence_request
argument_list|,
name|radeon_fence_retire
argument_list|,
name|TP_PROTO
argument_list|(
argument|struct drm_device *dev
argument_list|,
argument|u32 seqno
argument_list|)
argument_list|,
name|TP_ARGS
argument_list|(
name|dev
argument_list|,
name|seqno
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_EVENT
argument_list|(
name|radeon_fence_request
argument_list|,
name|radeon_fence_wait_begin
argument_list|,
name|TP_PROTO
argument_list|(
argument|struct drm_device *dev
argument_list|,
argument|u32 seqno
argument_list|)
argument_list|,
name|TP_ARGS
argument_list|(
name|dev
argument_list|,
name|seqno
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_EVENT
argument_list|(
name|radeon_fence_request
argument_list|,
name|radeon_fence_wait_end
argument_list|,
name|TP_PROTO
argument_list|(
argument|struct drm_device *dev
argument_list|,
argument|u32 seqno
argument_list|)
argument_list|,
name|TP_ARGS
argument_list|(
name|dev
argument_list|,
name|seqno
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This part must be outside protection */
end_comment

begin_undef
undef|#
directive|undef
name|TRACE_INCLUDE_PATH
end_undef

begin_define
define|#
directive|define
name|TRACE_INCLUDE_PATH
value|.
end_define

begin_include
include|#
directive|include
file|<trace/define_trace.h>
end_include

end_unit

