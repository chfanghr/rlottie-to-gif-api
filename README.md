# rlottie-to-gif api [![works badge](https://cdn.jsdelivr.net/gh/nikku/works-on-my-machine@v0.2.0/badge.svg)](https://github.com/nikku/works-on-my-machine)

***THIS PROJECT IS A SHITHOLE***

Convert [rlottie animation](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiD3vfGvaTwAhVOM94KHYkGAO4QFjACegQIBBAD&url=https%3A%2F%2Flottiefiles.com%2Fwhat-is-lottie&usg=AOvVaw3N_cxM02U_n5Rl2jUCWwn9)
json data to gif image, but as an api service.

Currently, you can't build a docker image because there is an unresolved linkage issue:

```
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `run()':
#14 41.31 App.cc:(.text+0x94): undefined reference to `oatpp::base::Environment::getComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 App.cc:(.text+0x14d): undefined reference to `oatpp::base::Environment::getComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 App.cc:(.text+0x1be): undefined reference to `oatpp::base::Environment::getComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 App.cc:(.text+0x258): undefined reference to `oatpp::base::Environment::logFormatted(unsigned int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*, ...)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `AppComponent::AppComponent()':
#14 41.31 App.cc:(.text._ZN12AppComponentC2Ev[_ZN12AppComponentC2Ev]+0x320): undefined reference to `oatpp::base::Environment::getComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::network::ConnectionHandler> >::~Component()':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network17ConnectionHandlerEEED2Ev[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network17ConnectionHandlerEEED2Ev]+0x10): undefined reference to `oatpp::base::Environment::unregisterComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::web::server::HttpRouterTemplate<std::shared_ptr<oatpp::web::server::HttpRequestHandler> > > >::~Component()':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_3web6server18HttpRouterTemplateIS3_INS5_18HttpRequestHandlerEEEEEED2Ev[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_3web6server18HttpRouterTemplateIS3_INS5_18HttpRequestHandlerEEEEEED2Ev]+0x10): undefined reference to `oatpp::base::Environment::unregisterComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::network::ServerConnectionProvider> >::~Component()':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network24ServerConnectionProviderEEED2Ev[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network24ServerConnectionProviderEEED2Ev]+0x10): undefined reference to `oatpp::base::Environment::unregisterComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::network::ServerConnectionProvider> >::Component(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::shared_ptr<oatpp::network::ServerConnectionProvider> const&)':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network24ServerConnectionProviderEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKS6_[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network24ServerConnectionProviderEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKS6_]+0x11e): undefined reference to `oatpp::base::Environment::registerComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, void*)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::web::server::HttpRouterTemplate<std::shared_ptr<oatpp::web::server::HttpRequestHandler> > > >::Component(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::shared_ptr<oatpp::web::server::HttpRouterTemplate<std::shared_ptr<oatpp::web::server::HttpRequestHandler> > > const&)':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_3web6server18HttpRouterTemplateIS3_INS5_18HttpRequestHandlerEEEEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSA_[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_3web6server18HttpRouterTemplateIS3_INS5_18HttpRequestHandlerEEEEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKSA_]+0x137): undefined reference to `oatpp::base::Environment::registerComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, void*)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::network::ConnectionHandler> >::Component(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::shared_ptr<oatpp::network::ConnectionHandler> const&)':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network17ConnectionHandlerEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKS6_[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_7network17ConnectionHandlerEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKS6_]+0x11a): undefined reference to `oatpp::base::Environment::registerComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, void*)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::data::mapping::ObjectMapper> >::Component(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::shared_ptr<oatpp::data::mapping::ObjectMapper> const&)':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_4data7mapping12ObjectMapperEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKS7_[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_4data7mapping12ObjectMapperEEEC2ERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERKS7_]+0x11a): undefined reference to `oatpp::base::Environment::registerComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, void*)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::data::mapping::type::__class::String::getType()':
#14 41.31 App.cc:(.text._ZN5oatpp4data7mapping4type7__class6String7getTypeEv[_ZN5oatpp4data7mapping4type7__class6String7getTypeEv]+0x83): undefined reference to `oatpp::data::mapping::type::Type::Type(oatpp::data::mapping::type::ClassId const&, char const*, void*, std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, oatpp::data::mapping::type::Type::AbstractInterpretation const*, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, oatpp::data::mapping::type::Type::AbstractInterpretation const*> > >&&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::Environment::Component<std::shared_ptr<oatpp::data::mapping::ObjectMapper> >::~Component()':
#14 41.31 App.cc:(.text._ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_4data7mapping12ObjectMapperEEED2Ev[_ZN5oatpp4base11Environment9ComponentISt10shared_ptrINS_4data7mapping12ObjectMapperEEED2Ev]+0x10): undefined reference to `oatpp::base::Environment::unregisterComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `void __gnu_cxx::new_allocator<RenderController>::construct<RenderController>(RenderController*)':
#14 41.31 App.cc:(.text._ZN9__gnu_cxx13new_allocatorI16RenderControllerE9constructIS1_JEEEvPT_DpOT0_[_ZN9__gnu_cxx13new_allocatorI16RenderControllerE9constructIS1_JEEEvPT_DpOT0_]+0x66): undefined reference to `oatpp::base::Environment::getComponent(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `std::shared_ptr<oatpp::web::server::api::ApiController::Handler<RenderController> > RenderController::Z__ENDPOINT_HANDLER_GET_INSTANCE_render<RenderController>(RenderController*)':
#14 41.31 App.cc:(.text._ZN16RenderController39Z__ENDPOINT_HANDLER_GET_INSTANCE_renderIS_EESt10shared_ptrIN5oatpp3web6server3api13ApiController7HandlerIT_EEEPS8_[_ZN16RenderController39Z__ENDPOINT_HANDLER_GET_INSTANCE_renderIS_EESt10shared_ptrIN5oatpp3web6server3api13ApiController7HandlerIT_EEEPS8_]+0x43): undefined reference to `oatpp::web::server::api::ApiController::getEndpointHandler(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 App.cc:(.text._ZN16RenderController39Z__ENDPOINT_HANDLER_GET_INSTANCE_renderIS_EESt10shared_ptrIN5oatpp3web6server3api13ApiController7HandlerIT_EEEPS8_[_ZN16RenderController39Z__ENDPOINT_HANDLER_GET_INSTANCE_renderIS_EESt10shared_ptrIN5oatpp3web6server3api13ApiController7HandlerIT_EEEPS8_]+0x21d): undefined reference to `oatpp::web::server::api::ApiController::setEndpointHandler(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::shared_ptr<oatpp::web::server::HttpRequestHandler> const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::base::memory::PoolSharedObjectAllocator<std::_Sp_counted_ptr_inplace<oatpp::collection::LinkedList<std::shared_ptr<oatpp::web::server::api::Endpoint> >, oatpp::base::memory::PoolSharedObjectAllocator<oatpp::collection::LinkedList<std::shared_ptr<oatpp::web::server::api::Endpoint> > >, (__gnu_cxx::_Lock_policy)2> >::getPool(oatpp::base::memory::AllocatorPoolInfo const&)':
#14 41.31 App.cc:(.text._ZN5oatpp4base6memory25PoolSharedObjectAllocatorISt23_Sp_counted_ptr_inplaceINS_10collection10LinkedListISt10shared_ptrINS_3web6server3api8EndpointEEEENS2_ISC_EELN9__gnu_cxx12_Lock_policyE2EEE7getPoolERKNS1_17AllocatorPoolInfoE[_ZN5oatpp4base6memory25PoolSharedObjectAllocatorISt23_Sp_counted_ptr_inplaceINS_10collection10LinkedListISt10shared_ptrINS_3web6server3api8EndpointEEEENS2_ISC_EELN9__gnu_cxx12_Lock_policyE2EEE7getPoolERKNS1_17AllocatorPoolInfoE]+0xf5): undefined reference to `oatpp::base::memory::ThreadDistributedMemoryPool::ThreadDistributedMemoryPool(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, long, long, long)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::collection::LinkedList<std::shared_ptr<oatpp::web::server::api::Endpoint> >::LinkedListNode::LinkedList_Node_Pool::getPool()':
#14 41.31 App.cc:(.text._ZN5oatpp10collection10LinkedListISt10shared_ptrINS_3web6server3api8EndpointEEE14LinkedListNode20LinkedList_Node_Pool7getPoolEv[_ZN5oatpp10collection10LinkedListISt10shared_ptrINS_3web6server3api8EndpointEEE14LinkedListNode20LinkedList_Node_Pool7getPoolEv]+0x95): undefined reference to `oatpp::base::memory::MemoryPool::MemoryPool(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, long, long)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `RenderController::Z__EDNPOINT_INFO_GET_INSTANCE_render()':
#14 41.31 App.cc:(.text._ZN16RenderController36Z__EDNPOINT_INFO_GET_INSTANCE_renderEv[_ZN16RenderController36Z__EDNPOINT_INFO_GET_INSTANCE_renderEv]+0x3b): undefined reference to `oatpp::web::server::api::ApiController::getEndpointInfo(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
#14 41.31 App.cc:(.text._ZN16RenderController36Z__EDNPOINT_INFO_GET_INSTANCE_renderEv[_ZN16RenderController36Z__EDNPOINT_INFO_GET_INSTANCE_renderEv]+0x17f): undefined reference to `oatpp::web::server::api::ApiController::setEndpointInfo(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::shared_ptr<oatpp::web::server::api::Endpoint::Info> const&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::data::mapping::type::__class::Object<RenderRequest>::getType()':
#14 41.31 App.cc:(.text._ZN5oatpp4data7mapping4type7__class6ObjectI13RenderRequestE7getTypeEv[_ZN5oatpp4data7mapping4type7__class6ObjectI13RenderRequestE7getTypeEv]+0xa7): undefined reference to `oatpp::data::mapping::type::Type::Type(oatpp::data::mapping::type::ClassId const&, char const*, void*, std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, oatpp::data::mapping::type::Type::AbstractInterpretation const*, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, oatpp::data::mapping::type::Type::AbstractInterpretation const*> > >&&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::data::mapping::type::__class::UInt32::getType()':
#14 41.31 App.cc:(.text._ZN5oatpp4data7mapping4type7__class6UInt327getTypeEv[_ZN5oatpp4data7mapping4type7__class6UInt327getTypeEv]+0x83): undefined reference to `oatpp::data::mapping::type::Type::Type(oatpp::data::mapping::type::ClassId const&, char const*, void*, std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, oatpp::data::mapping::type::Type::AbstractInterpretation const*, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, oatpp::data::mapping::type::Type::AbstractInterpretation const*> > >&&)'
#14 41.31 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::data::mapping::type::__class::Float64::getType()':
#14 41.31 App.cc:(.text._ZN5oatpp4data7mapping4type7__class7Float647getTypeEv[_ZN5oatpp4data7mapping4type7__class7Float647getTypeEv]+0x83): undefined reference to `oatpp::data::mapping::type::Type::Type(oatpp::data::mapping::type::ClassId const&, char const*, void*, std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, oatpp::data::mapping::type::Type::AbstractInterpretation const*, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, oatpp::data::mapping::type::Type::AbstractInterpretation const*> > >&&)'
#14 41.32 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::data::mapping::type::__class::Vector<oatpp::data::mapping::type::Primitive<unsigned char, oatpp::data::mapping::type::__class::UInt8> >::createType()':
#14 41.32 App.cc:(.text._ZN5oatpp4data7mapping4type7__class6VectorINS2_9PrimitiveIhNS3_5UInt8EEEE10createTypeEv[_ZN5oatpp4data7mapping4type7__class6VectorINS2_9PrimitiveIhNS3_5UInt8EEEE10createTypeEv]+0x6b): undefined reference to `oatpp::data::mapping::type::Type::Type(oatpp::data::mapping::type::ClassId const&, char const*, void*, std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, oatpp::data::mapping::type::Type::AbstractInterpretation const*, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, oatpp::data::mapping::type::Type::AbstractInterpretation const*> > >&&)'
#14 41.32 CMakeFiles/service.dir/src/App.cc.o: In function `oatpp::data::mapping::type::__class::UInt8::getType()':
#14 41.32 App.cc:(.text._ZN5oatpp4data7mapping4type7__class5UInt87getTypeEv[_ZN5oatpp4data7mapping4type7__class5UInt87getTypeEv]+0x83): undefined reference to `oatpp::data::mapping::type::Type::Type(oatpp::data::mapping::type::ClassId const&, char const*, void*, std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, oatpp::data::mapping::type::Type::AbstractInterpretation const*, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, oatpp::data::mapping::type::Type::AbstractInterpretation const*> > >&&)'
#14 41.32 lib/libservice-lib.a(render.cc.o):render.cc:(.text._ZN5oatpp4data7mapping4type7__class6ObjectI11RenderErrorE7getTypeEv[_ZN5oatpp4data7mapping4type7__class6ObjectI11RenderErrorE7getTypeEv]+0xa7): more undefined references to `oatpp::data::mapping::type::Type::Type(oatpp::data::mapping::type::ClassId const&, char const*, void*, std::unordered_map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, oatpp::data::mapping::type::Type::AbstractInterpretation const*, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, oatpp::data::mapping::type::Type::AbstractInterpretation const*> > >&&)' follow
#14 41.33 clang: error: linker command failed with exit code 1 (use -v to see invocation)
#14 41.34 make[2]: *** [bin/service] Error 1
#14 41.34 CMakeFiles/service.dir/build.make:105: recipe for target 'bin/service' failed
#14 41.34 CMakeFiles/Makefile2:320: recipe for target 'CMakeFiles/service.dir/all' failed
#14 41.34 make[1]: *** [CMakeFiles/service.dir/all] Error 2
#14 41.34 Makefile:148: recipe for target 'all' failed
#14 41.34 make: *** [all] Error 2
```

I'll try to address it - if I have some spare time.

It works fine on my MacBook Pro for now, so let's assume that it will work on all the macOS machines.