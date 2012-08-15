begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|objc_arr
argument_list|)
end_if

begin_define
define|#
directive|define
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
value|__attribute__((unavailable("not available in automatic reference counting mode")))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NS_RETURNS_RETAINED
value|__attribute__((ns_returns_retained))
end_define

begin_define
define|#
directive|define
name|CF_CONSUMED
value|__attribute__((cf_consumed))
end_define

begin_define
define|#
directive|define
name|CF_RETURNS_RETAINED
value|__attribute__((cf_returns_retained))
end_define

begin_define
define|#
directive|define
name|NS_INLINE
value|static __inline__ __attribute__((always_inline))
end_define

begin_define
define|#
directive|define
name|nil
value|((void*) 0)
end_define

begin_typedef
typedef|typedef
name|int
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|NSUInteger
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|UChar32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UChar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_NSZone
name|NSZone
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|CFTypeRef
typedef|;
end_typedef

begin_function_decl
name|CFTypeRef
name|CFRetain
parameter_list|(
name|CFTypeRef
name|cf
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|CFTypeRef
name|CFMakeCollectable
argument_list|(
name|CFTypeRef
name|cf
argument_list|)
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|NS_INLINE
name|NS_RETURNS_RETAINED
name|id
name|NSMakeCollectable
argument_list|(
name|CFTypeRef
name|CF_CONSUMED
name|cf
argument_list|)
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|@
name|protocol
name|NSObject
operator|-
operator|(
name|BOOL
operator|)
name|isEqual
operator|:
operator|(
name|id
operator|)
name|object
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|NSZone
operator|*
operator|)
name|zone
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|retain
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|NSUInteger
operator|)
name|retainCount
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|oneway
name|void
operator|)
name|release
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|autorelease
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
expr|@
name|interface
name|NSObject
operator|<
name|NSObject
operator|>
block|{}
operator|-
operator|(
name|id
operator|)
name|init
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|id
operator|)
name|new
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|id
operator|)
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|dealloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|finalize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|id
operator|)
name|mutableCopy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|@
name|end
name|NS_AUTOMATED_REFCOUNT_UNAVAILABLE
expr|@
name|interface
name|NSAutoreleasePool
operator|:
name|NSObject
block|{ @
name|private
name|void
operator|*
name|_token
block|;
name|void
operator|*
name|_reserved3
block|;
name|void
operator|*
name|_reserved2
block|;
name|void
operator|*
name|_reserved
block|; }
operator|+
operator|(
name|void
operator|)
name|addObject
operator|:
operator|(
name|id
operator|)
name|anObject
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|addObject
operator|:
operator|(
name|id
operator|)
name|anObject
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|void
operator|)
name|drain
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|objc_objectptr_t
typedef|;
end_typedef

begin_extern
extern|extern __attribute__((ns_returns_retained
end_extern

begin_decl_stmt
unit|))
name|id
name|objc_retainedObject
argument_list|(
name|objc_objectptr_t
name|__attribute__
argument_list|(
argument|(cf_consumed)
argument_list|)
name|pointer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern __attribute__((ns_returns_not_retained
end_extern

begin_function_decl
unit|))
name|id
name|objc_unretainedObject
parameter_list|(
name|objc_objectptr_t
name|pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|objc_objectptr_t
name|objc_unretainedPointer
parameter_list|(
name|id
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|dispatch_retain
parameter_list|(
name|object
parameter_list|)
value|({ dispatch_object_t _o = (object); _dispatch_object_validate(_o); (void)[_o retain]; })
end_define

begin_define
define|#
directive|define
name|dispatch_release
parameter_list|(
name|object
parameter_list|)
value|({ dispatch_object_t _o = (object); _dispatch_object_validate(_o); [_o release]; })
end_define

begin_define
define|#
directive|define
name|xpc_retain
parameter_list|(
name|object
parameter_list|)
value|({ xpc_object_t _o = (object); _xpc_object_validate(_o); [_o retain]; })
end_define

begin_define
define|#
directive|define
name|xpc_release
parameter_list|(
name|object
parameter_list|)
value|({ xpc_object_t _o = (object); _xpc_object_validate(_o); [_o release]; })
end_define

begin_typedef
typedef|typedef
name|id
name|dispatch_object_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|id
name|xpc_object_t
typedef|;
end_typedef

begin_function_decl
name|void
name|_dispatch_object_validate
parameter_list|(
name|dispatch_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_xpc_object_validate
parameter_list|(
name|xpc_object_t
name|object
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|objc_arc
argument_list|)
end_if

begin_function
name|NS_INLINE
name|CF_RETURNS_RETAINED
name|CFTypeRef
name|CFBridgingRetain
parameter_list|(
name|id
name|X
parameter_list|)
block|{
return|return
operator|(
name|__bridge_retained
name|CFTypeRef
operator|)
name|X
return|;
block|}
end_function

begin_function
name|NS_INLINE
name|id
name|CFBridgingRelease
parameter_list|(
name|CFTypeRef
name|CF_CONSUMED
name|X
parameter_list|)
block|{
return|return
operator|(
name|__bridge_transfer
name|id
operator|)
name|X
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|NS_INLINE
name|CF_RETURNS_RETAINED
name|CFTypeRef
name|CFBridgingRetain
parameter_list|(
name|id
name|X
parameter_list|)
block|{
return|return
name|X
condition|?
name|CFRetain
argument_list|(
operator|(
name|CFTypeRef
operator|)
name|X
argument_list|)
else|:
name|NULL
return|;
block|}
end_function

begin_function
name|NS_INLINE
name|id
name|CFBridgingRelease
parameter_list|(
name|CFTypeRef
name|CF_CONSUMED
name|X
parameter_list|)
block|{
return|return
index|[
operator|(
name|id
operator|)
name|CFMakeCollectable
argument_list|(
argument|X
argument_list|)
name|autorelease
index|]
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

