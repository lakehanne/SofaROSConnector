/***********************************************************************
ROS service definition headers and ROS connector template instantiations.
This file is AUTO-GENERATED during the CMake run.
Please do not modify it by hand.
The contents will be overwritten and re-generated.
************************************************************************/


#include <ZyROS_ServiceType_Client_Instantiations.h>


#include "ZyROSConnectorServiceClient.inl"

using namespace Zyklio::ROSConnector;

ZyROSServiceClient::ZyROSServiceClient(): m_uuid(boost::uuids::random_generator()())
{

}
        

using namespace control_msgs;
using namespace control_toolbox;
using namespace controller_manager_msgs;
using namespace diagnostic_msgs;
using namespace dynamic_reconfigure;
using namespace gazebo_msgs;
using namespace laser_assembler;
using namespace map_msgs;
using namespace nav_msgs;
using namespace nodelet;
using namespace polled_camera;
using namespace roscpp;
using namespace roscpp_tutorials;
using namespace rospy_tutorials;
using namespace sensor_msgs;
using namespace std_srvs;
using namespace tf;
using namespace tf2_msgs;
using namespace topic_tools;
using namespace turtlesim;

template class ZyROSConnectorServiceClient<control_msgs::QueryCalibrationState, control_msgs::QueryCalibrationStateRequest, control_msgs::QueryCalibrationStateResponse>;
template class ZyROSConnectorServiceClient<control_msgs::QueryTrajectoryState, control_msgs::QueryTrajectoryStateRequest, control_msgs::QueryTrajectoryStateResponse>;
template class ZyROSConnectorServiceClient<control_toolbox::SetPidGains, control_toolbox::SetPidGainsRequest, control_toolbox::SetPidGainsResponse>;
template class ZyROSConnectorServiceClient<controller_manager_msgs::ListControllerTypes, controller_manager_msgs::ListControllerTypesRequest, controller_manager_msgs::ListControllerTypesResponse>;
template class ZyROSConnectorServiceClient<controller_manager_msgs::ListControllers, controller_manager_msgs::ListControllersRequest, controller_manager_msgs::ListControllersResponse>;
template class ZyROSConnectorServiceClient<controller_manager_msgs::LoadController, controller_manager_msgs::LoadControllerRequest, controller_manager_msgs::LoadControllerResponse>;
template class ZyROSConnectorServiceClient<controller_manager_msgs::ReloadControllerLibraries, controller_manager_msgs::ReloadControllerLibrariesRequest, controller_manager_msgs::ReloadControllerLibrariesResponse>;
template class ZyROSConnectorServiceClient<controller_manager_msgs::SwitchController, controller_manager_msgs::SwitchControllerRequest, controller_manager_msgs::SwitchControllerResponse>;
template class ZyROSConnectorServiceClient<controller_manager_msgs::UnloadController, controller_manager_msgs::UnloadControllerRequest, controller_manager_msgs::UnloadControllerResponse>;
template class ZyROSConnectorServiceClient<diagnostic_msgs::AddDiagnostics, diagnostic_msgs::AddDiagnosticsRequest, diagnostic_msgs::AddDiagnosticsResponse>;
template class ZyROSConnectorServiceClient<diagnostic_msgs::SelfTest, diagnostic_msgs::SelfTestRequest, diagnostic_msgs::SelfTestResponse>;
template class ZyROSConnectorServiceClient<dynamic_reconfigure::Reconfigure, dynamic_reconfigure::ReconfigureRequest, dynamic_reconfigure::ReconfigureResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::ApplyBodyWrench, gazebo_msgs::ApplyBodyWrenchRequest, gazebo_msgs::ApplyBodyWrenchResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::ApplyJointEffort, gazebo_msgs::ApplyJointEffortRequest, gazebo_msgs::ApplyJointEffortResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::BodyRequest, gazebo_msgs::BodyRequestRequest, gazebo_msgs::BodyRequestResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::DeleteLight, gazebo_msgs::DeleteLightRequest, gazebo_msgs::DeleteLightResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::DeleteModel, gazebo_msgs::DeleteModelRequest, gazebo_msgs::DeleteModelResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetJointProperties, gazebo_msgs::GetJointPropertiesRequest, gazebo_msgs::GetJointPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetLightProperties, gazebo_msgs::GetLightPropertiesRequest, gazebo_msgs::GetLightPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetLinkProperties, gazebo_msgs::GetLinkPropertiesRequest, gazebo_msgs::GetLinkPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetLinkState, gazebo_msgs::GetLinkStateRequest, gazebo_msgs::GetLinkStateResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetModelProperties, gazebo_msgs::GetModelPropertiesRequest, gazebo_msgs::GetModelPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetModelState, gazebo_msgs::GetModelStateRequest, gazebo_msgs::GetModelStateResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetPhysicsProperties, gazebo_msgs::GetPhysicsPropertiesRequest, gazebo_msgs::GetPhysicsPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::GetWorldProperties, gazebo_msgs::GetWorldPropertiesRequest, gazebo_msgs::GetWorldPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::JointRequest, gazebo_msgs::JointRequestRequest, gazebo_msgs::JointRequestResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetJointProperties, gazebo_msgs::SetJointPropertiesRequest, gazebo_msgs::SetJointPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetJointTrajectory, gazebo_msgs::SetJointTrajectoryRequest, gazebo_msgs::SetJointTrajectoryResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetLightProperties, gazebo_msgs::SetLightPropertiesRequest, gazebo_msgs::SetLightPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetLinkProperties, gazebo_msgs::SetLinkPropertiesRequest, gazebo_msgs::SetLinkPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetLinkState, gazebo_msgs::SetLinkStateRequest, gazebo_msgs::SetLinkStateResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetModelConfiguration, gazebo_msgs::SetModelConfigurationRequest, gazebo_msgs::SetModelConfigurationResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetModelState, gazebo_msgs::SetModelStateRequest, gazebo_msgs::SetModelStateResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SetPhysicsProperties, gazebo_msgs::SetPhysicsPropertiesRequest, gazebo_msgs::SetPhysicsPropertiesResponse>;
template class ZyROSConnectorServiceClient<gazebo_msgs::SpawnModel, gazebo_msgs::SpawnModelRequest, gazebo_msgs::SpawnModelResponse>;
template class ZyROSConnectorServiceClient<laser_assembler::AssembleScans, laser_assembler::AssembleScansRequest, laser_assembler::AssembleScansResponse>;
template class ZyROSConnectorServiceClient<laser_assembler::AssembleScans2, laser_assembler::AssembleScans2Request, laser_assembler::AssembleScans2Response>;
template class ZyROSConnectorServiceClient<map_msgs::GetMapROI, map_msgs::GetMapROIRequest, map_msgs::GetMapROIResponse>;
template class ZyROSConnectorServiceClient<map_msgs::GetPointMap, map_msgs::GetPointMapRequest, map_msgs::GetPointMapResponse>;
template class ZyROSConnectorServiceClient<map_msgs::GetPointMapROI, map_msgs::GetPointMapROIRequest, map_msgs::GetPointMapROIResponse>;
template class ZyROSConnectorServiceClient<map_msgs::ProjectedMapsInfo, map_msgs::ProjectedMapsInfoRequest, map_msgs::ProjectedMapsInfoResponse>;
template class ZyROSConnectorServiceClient<map_msgs::SaveMap, map_msgs::SaveMapRequest, map_msgs::SaveMapResponse>;
template class ZyROSConnectorServiceClient<map_msgs::SetMapProjections, map_msgs::SetMapProjectionsRequest, map_msgs::SetMapProjectionsResponse>;
template class ZyROSConnectorServiceClient<nav_msgs::GetMap, nav_msgs::GetMapRequest, nav_msgs::GetMapResponse>;
template class ZyROSConnectorServiceClient<nav_msgs::GetPlan, nav_msgs::GetPlanRequest, nav_msgs::GetPlanResponse>;
template class ZyROSConnectorServiceClient<nav_msgs::SetMap, nav_msgs::SetMapRequest, nav_msgs::SetMapResponse>;
template class ZyROSConnectorServiceClient<nodelet::NodeletList, nodelet::NodeletListRequest, nodelet::NodeletListResponse>;
template class ZyROSConnectorServiceClient<nodelet::NodeletLoad, nodelet::NodeletLoadRequest, nodelet::NodeletLoadResponse>;
template class ZyROSConnectorServiceClient<nodelet::NodeletUnload, nodelet::NodeletUnloadRequest, nodelet::NodeletUnloadResponse>;
template class ZyROSConnectorServiceClient<polled_camera::GetPolledImage, polled_camera::GetPolledImageRequest, polled_camera::GetPolledImageResponse>;
template class ZyROSConnectorServiceClient<roscpp::Empty, roscpp::EmptyRequest, roscpp::EmptyResponse>;
template class ZyROSConnectorServiceClient<roscpp::GetLoggers, roscpp::GetLoggersRequest, roscpp::GetLoggersResponse>;
template class ZyROSConnectorServiceClient<roscpp::SetLoggerLevel, roscpp::SetLoggerLevelRequest, roscpp::SetLoggerLevelResponse>;
template class ZyROSConnectorServiceClient<roscpp_tutorials::TwoInts, roscpp_tutorials::TwoIntsRequest, roscpp_tutorials::TwoIntsResponse>;
template class ZyROSConnectorServiceClient<rospy_tutorials::AddTwoInts, rospy_tutorials::AddTwoIntsRequest, rospy_tutorials::AddTwoIntsResponse>;
template class ZyROSConnectorServiceClient<rospy_tutorials::BadTwoInts, rospy_tutorials::BadTwoIntsRequest, rospy_tutorials::BadTwoIntsResponse>;
template class ZyROSConnectorServiceClient<sensor_msgs::SetCameraInfo, sensor_msgs::SetCameraInfoRequest, sensor_msgs::SetCameraInfoResponse>;
template class ZyROSConnectorServiceClient<std_srvs::Empty, std_srvs::EmptyRequest, std_srvs::EmptyResponse>;
template class ZyROSConnectorServiceClient<std_srvs::SetBool, std_srvs::SetBoolRequest, std_srvs::SetBoolResponse>;
template class ZyROSConnectorServiceClient<std_srvs::Trigger, std_srvs::TriggerRequest, std_srvs::TriggerResponse>;
template class ZyROSConnectorServiceClient<tf::FrameGraph, tf::FrameGraphRequest, tf::FrameGraphResponse>;
template class ZyROSConnectorServiceClient<tf2_msgs::FrameGraph, tf2_msgs::FrameGraphRequest, tf2_msgs::FrameGraphResponse>;
template class ZyROSConnectorServiceClient<topic_tools::DemuxAdd, topic_tools::DemuxAddRequest, topic_tools::DemuxAddResponse>;
template class ZyROSConnectorServiceClient<topic_tools::DemuxDelete, topic_tools::DemuxDeleteRequest, topic_tools::DemuxDeleteResponse>;
template class ZyROSConnectorServiceClient<topic_tools::DemuxList, topic_tools::DemuxListRequest, topic_tools::DemuxListResponse>;
template class ZyROSConnectorServiceClient<topic_tools::DemuxSelect, topic_tools::DemuxSelectRequest, topic_tools::DemuxSelectResponse>;
template class ZyROSConnectorServiceClient<topic_tools::MuxAdd, topic_tools::MuxAddRequest, topic_tools::MuxAddResponse>;
template class ZyROSConnectorServiceClient<topic_tools::MuxDelete, topic_tools::MuxDeleteRequest, topic_tools::MuxDeleteResponse>;
template class ZyROSConnectorServiceClient<topic_tools::MuxList, topic_tools::MuxListRequest, topic_tools::MuxListResponse>;
template class ZyROSConnectorServiceClient<topic_tools::MuxSelect, topic_tools::MuxSelectRequest, topic_tools::MuxSelectResponse>;
template class ZyROSConnectorServiceClient<turtlesim::Kill, turtlesim::KillRequest, turtlesim::KillResponse>;
template class ZyROSConnectorServiceClient<turtlesim::SetPen, turtlesim::SetPenRequest, turtlesim::SetPenResponse>;
template class ZyROSConnectorServiceClient<turtlesim::Spawn, turtlesim::SpawnRequest, turtlesim::SpawnResponse>;
template class ZyROSConnectorServiceClient<turtlesim::TeleportAbsolute, turtlesim::TeleportAbsoluteRequest, turtlesim::TeleportAbsoluteResponse>;
template class ZyROSConnectorServiceClient<turtlesim::TeleportRelative, turtlesim::TeleportRelativeRequest, turtlesim::TeleportRelativeResponse>;
boost::shared_ptr<ZyROSServiceClient> ZyROSConnectorServiceClientFactory::createServiceClient(ros::NodeHandlePtr rosNode, const std::string& serviceURI, const std::string& serviceType)
{
	bool supported = false;
	boost::shared_ptr<ZyROSServiceClient> serviceClient;
	// Service client instance for ROS service type: control_msgs/QueryCalibrationState
	if (serviceType == "control_msgs::QueryCalibrationState")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<control_msgs::QueryCalibrationState, control_msgs::QueryCalibrationStateRequest, control_msgs::QueryCalibrationStateResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: control_msgs/QueryTrajectoryState
	if (serviceType == "control_msgs::QueryTrajectoryState")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<control_msgs::QueryTrajectoryState, control_msgs::QueryTrajectoryStateRequest, control_msgs::QueryTrajectoryStateResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: control_toolbox/SetPidGains
	if (serviceType == "control_toolbox::SetPidGains")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<control_toolbox::SetPidGains, control_toolbox::SetPidGainsRequest, control_toolbox::SetPidGainsResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: controller_manager_msgs/ListControllerTypes
	if (serviceType == "controller_manager_msgs::ListControllerTypes")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<controller_manager_msgs::ListControllerTypes, controller_manager_msgs::ListControllerTypesRequest, controller_manager_msgs::ListControllerTypesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: controller_manager_msgs/ListControllers
	if (serviceType == "controller_manager_msgs::ListControllers")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<controller_manager_msgs::ListControllers, controller_manager_msgs::ListControllersRequest, controller_manager_msgs::ListControllersResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: controller_manager_msgs/LoadController
	if (serviceType == "controller_manager_msgs::LoadController")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<controller_manager_msgs::LoadController, controller_manager_msgs::LoadControllerRequest, controller_manager_msgs::LoadControllerResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: controller_manager_msgs/ReloadControllerLibraries
	if (serviceType == "controller_manager_msgs::ReloadControllerLibraries")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<controller_manager_msgs::ReloadControllerLibraries, controller_manager_msgs::ReloadControllerLibrariesRequest, controller_manager_msgs::ReloadControllerLibrariesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: controller_manager_msgs/SwitchController
	if (serviceType == "controller_manager_msgs::SwitchController")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<controller_manager_msgs::SwitchController, controller_manager_msgs::SwitchControllerRequest, controller_manager_msgs::SwitchControllerResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: controller_manager_msgs/UnloadController
	if (serviceType == "controller_manager_msgs::UnloadController")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<controller_manager_msgs::UnloadController, controller_manager_msgs::UnloadControllerRequest, controller_manager_msgs::UnloadControllerResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: diagnostic_msgs/AddDiagnostics
	if (serviceType == "diagnostic_msgs::AddDiagnostics")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<diagnostic_msgs::AddDiagnostics, diagnostic_msgs::AddDiagnosticsRequest, diagnostic_msgs::AddDiagnosticsResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: diagnostic_msgs/SelfTest
	if (serviceType == "diagnostic_msgs::SelfTest")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<diagnostic_msgs::SelfTest, diagnostic_msgs::SelfTestRequest, diagnostic_msgs::SelfTestResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: dynamic_reconfigure/Reconfigure
	if (serviceType == "dynamic_reconfigure::Reconfigure")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<dynamic_reconfigure::Reconfigure, dynamic_reconfigure::ReconfigureRequest, dynamic_reconfigure::ReconfigureResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/ApplyBodyWrench
	if (serviceType == "gazebo_msgs::ApplyBodyWrench")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::ApplyBodyWrench, gazebo_msgs::ApplyBodyWrenchRequest, gazebo_msgs::ApplyBodyWrenchResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/ApplyJointEffort
	if (serviceType == "gazebo_msgs::ApplyJointEffort")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::ApplyJointEffort, gazebo_msgs::ApplyJointEffortRequest, gazebo_msgs::ApplyJointEffortResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/BodyRequest
	if (serviceType == "gazebo_msgs::BodyRequest")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::BodyRequest, gazebo_msgs::BodyRequestRequest, gazebo_msgs::BodyRequestResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/DeleteLight
	if (serviceType == "gazebo_msgs::DeleteLight")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::DeleteLight, gazebo_msgs::DeleteLightRequest, gazebo_msgs::DeleteLightResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/DeleteModel
	if (serviceType == "gazebo_msgs::DeleteModel")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::DeleteModel, gazebo_msgs::DeleteModelRequest, gazebo_msgs::DeleteModelResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetJointProperties
	if (serviceType == "gazebo_msgs::GetJointProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetJointProperties, gazebo_msgs::GetJointPropertiesRequest, gazebo_msgs::GetJointPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetLightProperties
	if (serviceType == "gazebo_msgs::GetLightProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetLightProperties, gazebo_msgs::GetLightPropertiesRequest, gazebo_msgs::GetLightPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetLinkProperties
	if (serviceType == "gazebo_msgs::GetLinkProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetLinkProperties, gazebo_msgs::GetLinkPropertiesRequest, gazebo_msgs::GetLinkPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetLinkState
	if (serviceType == "gazebo_msgs::GetLinkState")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetLinkState, gazebo_msgs::GetLinkStateRequest, gazebo_msgs::GetLinkStateResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetModelProperties
	if (serviceType == "gazebo_msgs::GetModelProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetModelProperties, gazebo_msgs::GetModelPropertiesRequest, gazebo_msgs::GetModelPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetModelState
	if (serviceType == "gazebo_msgs::GetModelState")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetModelState, gazebo_msgs::GetModelStateRequest, gazebo_msgs::GetModelStateResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetPhysicsProperties
	if (serviceType == "gazebo_msgs::GetPhysicsProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetPhysicsProperties, gazebo_msgs::GetPhysicsPropertiesRequest, gazebo_msgs::GetPhysicsPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/GetWorldProperties
	if (serviceType == "gazebo_msgs::GetWorldProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::GetWorldProperties, gazebo_msgs::GetWorldPropertiesRequest, gazebo_msgs::GetWorldPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/JointRequest
	if (serviceType == "gazebo_msgs::JointRequest")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::JointRequest, gazebo_msgs::JointRequestRequest, gazebo_msgs::JointRequestResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetJointProperties
	if (serviceType == "gazebo_msgs::SetJointProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetJointProperties, gazebo_msgs::SetJointPropertiesRequest, gazebo_msgs::SetJointPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetJointTrajectory
	if (serviceType == "gazebo_msgs::SetJointTrajectory")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetJointTrajectory, gazebo_msgs::SetJointTrajectoryRequest, gazebo_msgs::SetJointTrajectoryResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetLightProperties
	if (serviceType == "gazebo_msgs::SetLightProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetLightProperties, gazebo_msgs::SetLightPropertiesRequest, gazebo_msgs::SetLightPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetLinkProperties
	if (serviceType == "gazebo_msgs::SetLinkProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetLinkProperties, gazebo_msgs::SetLinkPropertiesRequest, gazebo_msgs::SetLinkPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetLinkState
	if (serviceType == "gazebo_msgs::SetLinkState")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetLinkState, gazebo_msgs::SetLinkStateRequest, gazebo_msgs::SetLinkStateResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetModelConfiguration
	if (serviceType == "gazebo_msgs::SetModelConfiguration")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetModelConfiguration, gazebo_msgs::SetModelConfigurationRequest, gazebo_msgs::SetModelConfigurationResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetModelState
	if (serviceType == "gazebo_msgs::SetModelState")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetModelState, gazebo_msgs::SetModelStateRequest, gazebo_msgs::SetModelStateResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SetPhysicsProperties
	if (serviceType == "gazebo_msgs::SetPhysicsProperties")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SetPhysicsProperties, gazebo_msgs::SetPhysicsPropertiesRequest, gazebo_msgs::SetPhysicsPropertiesResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: gazebo_msgs/SpawnModel
	if (serviceType == "gazebo_msgs::SpawnModel")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<gazebo_msgs::SpawnModel, gazebo_msgs::SpawnModelRequest, gazebo_msgs::SpawnModelResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: laser_assembler/AssembleScans
	if (serviceType == "laser_assembler::AssembleScans")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<laser_assembler::AssembleScans, laser_assembler::AssembleScansRequest, laser_assembler::AssembleScansResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: laser_assembler/AssembleScans2
	if (serviceType == "laser_assembler::AssembleScans2")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<laser_assembler::AssembleScans2, laser_assembler::AssembleScans2Request, laser_assembler::AssembleScans2Response>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: map_msgs/GetMapROI
	if (serviceType == "map_msgs::GetMapROI")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<map_msgs::GetMapROI, map_msgs::GetMapROIRequest, map_msgs::GetMapROIResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: map_msgs/GetPointMap
	if (serviceType == "map_msgs::GetPointMap")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<map_msgs::GetPointMap, map_msgs::GetPointMapRequest, map_msgs::GetPointMapResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: map_msgs/GetPointMapROI
	if (serviceType == "map_msgs::GetPointMapROI")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<map_msgs::GetPointMapROI, map_msgs::GetPointMapROIRequest, map_msgs::GetPointMapROIResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: map_msgs/ProjectedMapsInfo
	if (serviceType == "map_msgs::ProjectedMapsInfo")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<map_msgs::ProjectedMapsInfo, map_msgs::ProjectedMapsInfoRequest, map_msgs::ProjectedMapsInfoResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: map_msgs/SaveMap
	if (serviceType == "map_msgs::SaveMap")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<map_msgs::SaveMap, map_msgs::SaveMapRequest, map_msgs::SaveMapResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: map_msgs/SetMapProjections
	if (serviceType == "map_msgs::SetMapProjections")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<map_msgs::SetMapProjections, map_msgs::SetMapProjectionsRequest, map_msgs::SetMapProjectionsResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: nav_msgs/GetMap
	if (serviceType == "nav_msgs::GetMap")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<nav_msgs::GetMap, nav_msgs::GetMapRequest, nav_msgs::GetMapResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: nav_msgs/GetPlan
	if (serviceType == "nav_msgs::GetPlan")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<nav_msgs::GetPlan, nav_msgs::GetPlanRequest, nav_msgs::GetPlanResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: nav_msgs/SetMap
	if (serviceType == "nav_msgs::SetMap")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<nav_msgs::SetMap, nav_msgs::SetMapRequest, nav_msgs::SetMapResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: nodelet/NodeletList
	if (serviceType == "nodelet::NodeletList")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<nodelet::NodeletList, nodelet::NodeletListRequest, nodelet::NodeletListResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: nodelet/NodeletLoad
	if (serviceType == "nodelet::NodeletLoad")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<nodelet::NodeletLoad, nodelet::NodeletLoadRequest, nodelet::NodeletLoadResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: nodelet/NodeletUnload
	if (serviceType == "nodelet::NodeletUnload")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<nodelet::NodeletUnload, nodelet::NodeletUnloadRequest, nodelet::NodeletUnloadResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: polled_camera/GetPolledImage
	if (serviceType == "polled_camera::GetPolledImage")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<polled_camera::GetPolledImage, polled_camera::GetPolledImageRequest, polled_camera::GetPolledImageResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: roscpp/Empty
	if (serviceType == "roscpp::Empty")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<roscpp::Empty, roscpp::EmptyRequest, roscpp::EmptyResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: roscpp/GetLoggers
	if (serviceType == "roscpp::GetLoggers")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<roscpp::GetLoggers, roscpp::GetLoggersRequest, roscpp::GetLoggersResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: roscpp/SetLoggerLevel
	if (serviceType == "roscpp::SetLoggerLevel")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<roscpp::SetLoggerLevel, roscpp::SetLoggerLevelRequest, roscpp::SetLoggerLevelResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: roscpp_tutorials/TwoInts
	if (serviceType == "roscpp_tutorials::TwoInts")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<roscpp_tutorials::TwoInts, roscpp_tutorials::TwoIntsRequest, roscpp_tutorials::TwoIntsResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: rospy_tutorials/AddTwoInts
	if (serviceType == "rospy_tutorials::AddTwoInts")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<rospy_tutorials::AddTwoInts, rospy_tutorials::AddTwoIntsRequest, rospy_tutorials::AddTwoIntsResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: rospy_tutorials/BadTwoInts
	if (serviceType == "rospy_tutorials::BadTwoInts")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<rospy_tutorials::BadTwoInts, rospy_tutorials::BadTwoIntsRequest, rospy_tutorials::BadTwoIntsResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: sensor_msgs/SetCameraInfo
	if (serviceType == "sensor_msgs::SetCameraInfo")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<sensor_msgs::SetCameraInfo, sensor_msgs::SetCameraInfoRequest, sensor_msgs::SetCameraInfoResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: std_srvs/Empty
	if (serviceType == "std_srvs::Empty")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<std_srvs::Empty, std_srvs::EmptyRequest, std_srvs::EmptyResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: std_srvs/SetBool
	if (serviceType == "std_srvs::SetBool")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<std_srvs::SetBool, std_srvs::SetBoolRequest, std_srvs::SetBoolResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: std_srvs/Trigger
	if (serviceType == "std_srvs::Trigger")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<std_srvs::Trigger, std_srvs::TriggerRequest, std_srvs::TriggerResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: tf/FrameGraph
	if (serviceType == "tf::FrameGraph")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<tf::FrameGraph, tf::FrameGraphRequest, tf::FrameGraphResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: tf2_msgs/FrameGraph
	if (serviceType == "tf2_msgs::FrameGraph")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<tf2_msgs::FrameGraph, tf2_msgs::FrameGraphRequest, tf2_msgs::FrameGraphResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/DemuxAdd
	if (serviceType == "topic_tools::DemuxAdd")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::DemuxAdd, topic_tools::DemuxAddRequest, topic_tools::DemuxAddResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/DemuxDelete
	if (serviceType == "topic_tools::DemuxDelete")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::DemuxDelete, topic_tools::DemuxDeleteRequest, topic_tools::DemuxDeleteResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/DemuxList
	if (serviceType == "topic_tools::DemuxList")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::DemuxList, topic_tools::DemuxListRequest, topic_tools::DemuxListResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/DemuxSelect
	if (serviceType == "topic_tools::DemuxSelect")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::DemuxSelect, topic_tools::DemuxSelectRequest, topic_tools::DemuxSelectResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/MuxAdd
	if (serviceType == "topic_tools::MuxAdd")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::MuxAdd, topic_tools::MuxAddRequest, topic_tools::MuxAddResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/MuxDelete
	if (serviceType == "topic_tools::MuxDelete")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::MuxDelete, topic_tools::MuxDeleteRequest, topic_tools::MuxDeleteResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/MuxList
	if (serviceType == "topic_tools::MuxList")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::MuxList, topic_tools::MuxListRequest, topic_tools::MuxListResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: topic_tools/MuxSelect
	if (serviceType == "topic_tools::MuxSelect")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<topic_tools::MuxSelect, topic_tools::MuxSelectRequest, topic_tools::MuxSelectResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: turtlesim/Kill
	if (serviceType == "turtlesim::Kill")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<turtlesim::Kill, turtlesim::KillRequest, turtlesim::KillResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: turtlesim/SetPen
	if (serviceType == "turtlesim::SetPen")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<turtlesim::SetPen, turtlesim::SetPenRequest, turtlesim::SetPenResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: turtlesim/Spawn
	if (serviceType == "turtlesim::Spawn")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<turtlesim::Spawn, turtlesim::SpawnRequest, turtlesim::SpawnResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: turtlesim/TeleportAbsolute
	if (serviceType == "turtlesim::TeleportAbsolute")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<turtlesim::TeleportAbsolute, turtlesim::TeleportAbsoluteRequest, turtlesim::TeleportAbsoluteResponse>(rosNode, serviceURI, 10));
	}
	// Service client instance for ROS service type: turtlesim/TeleportRelative
	if (serviceType == "turtlesim::TeleportRelative")
	{
		supported = true;
		serviceClient.reset(new ZyROSConnectorServiceClient<turtlesim::TeleportRelative, turtlesim::TeleportRelativeRequest, turtlesim::TeleportRelativeResponse>(rosNode, serviceURI, 10));
	}

	if (supported)
	{
		msg_info("ZyROSConnectorServiceClientFactory") << "ROS service type supported: " << serviceType;
	}
	else
	{
		msg_warning("ZyROSConnectorServiceClientFactory") << "ROS service type NOT supported: " << serviceType;
	}
	return serviceClient;
}
