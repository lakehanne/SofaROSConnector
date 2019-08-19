/***********************************************************************
ROS service definition headers and ROS connector template instantiations.
This file is AUTO-GENERATED during the CMake run.
Please do not modify it by hand.
The contents will be overwritten and re-generated.
************************************************************************/




#include "ZyROSConnectorServiceServer.inl"

using namespace Zyklio::ROSConnector;

ZyROSConnectorServiceServer::ZyROSConnectorServiceServer(/*ros::NodeHandlePtr rosNode,*/ const std::string& serviceURI): m_d(NULL)
{
    m_d = new ZyROSConnectorServiceServerPrivate();
    m_d->m_serviceURI = serviceURI;
    m_d->m_rosNodeHandle.reset(new ros::NodeHandle());
    m_shutdownRequested = false;
}

ZyROSConnectorServiceServer::ZyROSConnectorServiceServer(const ZyROSConnectorServiceServer& other): m_d(NULL)
{
    m_d = new ZyROSConnectorServiceServerPrivate();
    m_d->m_serviceURI = other.m_d->m_serviceURI;
    m_d->m_rosNodeHandle.reset(new ros::NodeHandle());
    m_shutdownRequested = other.m_shutdownRequested;
}

ZyROSConnectorServiceServer::~ZyROSConnectorServiceServer()
{
    if (m_d)
    {
        if (m_d->m_rosNodeHandle)
            m_d->m_rosNodeHandle->shutdown();

        delete m_d;
        m_d = NULL;
    }
}

void ZyROSConnectorServiceServer::shutdownServer()
{
    boost::mutex::scoped_lock lock(m_mutex);
    m_shutdownRequested = true;
}

void ZyROSConnectorServiceServer::serverLoop()
{
    msg_info("ZyROSConnectorServiceServer") << "Entering serverLoop.";

    ros::Rate service_server_rate(25);
    m_serverThreadActive = true;
    while (ros::ok())
    {
        if (m_shutdownRequested)
            break;

        service_server_rate.sleep();
    }

    m_serverThreadActive = false;

    if (m_d->m_rosServer)
    {
        msg_info("ZyROSConnectorServiceServer") << "Shutting down ROS service server.";
        m_d->m_rosServer.shutdown();
    }

    if (m_d->m_rosNodeHandle)
    {
        msg_info("ZyROSConnectorServiceServer") << "Shutting down service server ROS node.";
        m_d->m_rosNodeHandle->shutdown();
    }
}

        
#include <control_msgs/QueryCalibrationStateRequest.h>
#include <control_msgs/QueryCalibrationStateResponse.h>
#include <control_msgs/QueryCalibrationState.h>
#include <control_msgs/QueryTrajectoryState.h>
#include <control_msgs/QueryTrajectoryStateRequest.h>
#include <control_msgs/QueryTrajectoryStateResponse.h>
#include <control_toolbox/SetPidGains.h>
#include <control_toolbox/SetPidGainsRequest.h>
#include <control_toolbox/SetPidGainsResponse.h>
#include <controller_manager_msgs/ListControllerTypes.h>
#include <controller_manager_msgs/ListControllerTypesRequest.h>
#include <controller_manager_msgs/ListControllerTypesResponse.h>
#include <controller_manager_msgs/ListControllersRequest.h>
#include <controller_manager_msgs/ListControllers.h>
#include <controller_manager_msgs/ListControllersResponse.h>
#include <controller_manager_msgs/LoadControllerResponse.h>
#include <controller_manager_msgs/LoadController.h>
#include <controller_manager_msgs/LoadControllerRequest.h>
#include <controller_manager_msgs/ReloadControllerLibrariesResponse.h>
#include <controller_manager_msgs/ReloadControllerLibraries.h>
#include <controller_manager_msgs/ReloadControllerLibrariesRequest.h>
#include <controller_manager_msgs/SwitchController.h>
#include <controller_manager_msgs/SwitchControllerRequest.h>
#include <controller_manager_msgs/SwitchControllerResponse.h>
#include <controller_manager_msgs/UnloadControllerRequest.h>
#include <controller_manager_msgs/UnloadControllerResponse.h>
#include <controller_manager_msgs/UnloadController.h>
#include <diagnostic_msgs/AddDiagnosticsResponse.h>
#include <diagnostic_msgs/AddDiagnostics.h>
#include <diagnostic_msgs/AddDiagnosticsRequest.h>
#include <diagnostic_msgs/SelfTestResponse.h>
#include <diagnostic_msgs/SelfTest.h>
#include <diagnostic_msgs/SelfTestRequest.h>
#include <dynamic_reconfigure/ReconfigureResponse.h>
#include <dynamic_reconfigure/ReconfigureRequest.h>
#include <dynamic_reconfigure/Reconfigure.h>
#include <gazebo_msgs/ApplyBodyWrenchRequest.h>
#include <gazebo_msgs/ApplyBodyWrench.h>
#include <gazebo_msgs/ApplyBodyWrenchResponse.h>
#include <gazebo_msgs/ApplyJointEffort.h>
#include <gazebo_msgs/ApplyJointEffortRequest.h>
#include <gazebo_msgs/ApplyJointEffortResponse.h>
#include <gazebo_msgs/BodyRequestRequest.h>
#include <gazebo_msgs/BodyRequest.h>
#include <gazebo_msgs/BodyRequestResponse.h>
#include <gazebo_msgs/DeleteLight.h>
#include <gazebo_msgs/DeleteLightRequest.h>
#include <gazebo_msgs/DeleteLightResponse.h>
#include <gazebo_msgs/DeleteModelResponse.h>
#include <gazebo_msgs/DeleteModelRequest.h>
#include <gazebo_msgs/DeleteModel.h>
#include <gazebo_msgs/GetJointProperties.h>
#include <gazebo_msgs/GetJointPropertiesRequest.h>
#include <gazebo_msgs/GetJointPropertiesResponse.h>
#include <gazebo_msgs/GetLightPropertiesResponse.h>
#include <gazebo_msgs/GetLightPropertiesRequest.h>
#include <gazebo_msgs/GetLightProperties.h>
#include <gazebo_msgs/GetLinkProperties.h>
#include <gazebo_msgs/GetLinkPropertiesRequest.h>
#include <gazebo_msgs/GetLinkPropertiesResponse.h>
#include <gazebo_msgs/GetLinkStateResponse.h>
#include <gazebo_msgs/GetLinkState.h>
#include <gazebo_msgs/GetLinkStateRequest.h>
#include <gazebo_msgs/GetModelProperties.h>
#include <gazebo_msgs/GetModelPropertiesRequest.h>
#include <gazebo_msgs/GetModelPropertiesResponse.h>
#include <gazebo_msgs/GetModelStateResponse.h>
#include <gazebo_msgs/GetModelState.h>
#include <gazebo_msgs/GetModelStateRequest.h>
#include <gazebo_msgs/GetPhysicsPropertiesRequest.h>
#include <gazebo_msgs/GetPhysicsProperties.h>
#include <gazebo_msgs/GetPhysicsPropertiesResponse.h>
#include <gazebo_msgs/GetWorldPropertiesRequest.h>
#include <gazebo_msgs/GetWorldProperties.h>
#include <gazebo_msgs/GetWorldPropertiesResponse.h>
#include <gazebo_msgs/JointRequestRequest.h>
#include <gazebo_msgs/JointRequestResponse.h>
#include <gazebo_msgs/JointRequest.h>
#include <gazebo_msgs/SetJointPropertiesRequest.h>
#include <gazebo_msgs/SetJointProperties.h>
#include <gazebo_msgs/SetJointPropertiesResponse.h>
#include <gazebo_msgs/SetJointTrajectoryRequest.h>
#include <gazebo_msgs/SetJointTrajectoryResponse.h>
#include <gazebo_msgs/SetJointTrajectory.h>
#include <gazebo_msgs/SetLightProperties.h>
#include <gazebo_msgs/SetLightPropertiesResponse.h>
#include <gazebo_msgs/SetLightPropertiesRequest.h>
#include <gazebo_msgs/SetLinkPropertiesResponse.h>
#include <gazebo_msgs/SetLinkPropertiesRequest.h>
#include <gazebo_msgs/SetLinkProperties.h>
#include <gazebo_msgs/SetLinkStateRequest.h>
#include <gazebo_msgs/SetLinkState.h>
#include <gazebo_msgs/SetLinkStateResponse.h>
#include <gazebo_msgs/SetModelConfigurationResponse.h>
#include <gazebo_msgs/SetModelConfiguration.h>
#include <gazebo_msgs/SetModelConfigurationRequest.h>
#include <gazebo_msgs/SetModelState.h>
#include <gazebo_msgs/SetModelStateRequest.h>
#include <gazebo_msgs/SetModelStateResponse.h>
#include <gazebo_msgs/SetPhysicsProperties.h>
#include <gazebo_msgs/SetPhysicsPropertiesRequest.h>
#include <gazebo_msgs/SetPhysicsPropertiesResponse.h>
#include <gazebo_msgs/SpawnModel.h>
#include <gazebo_msgs/SpawnModelRequest.h>
#include <gazebo_msgs/SpawnModelResponse.h>
#include <laser_assembler/AssembleScansResponse.h>
#include <laser_assembler/AssembleScans2Request.h>
#include <laser_assembler/AssembleScans2Response.h>
#include <laser_assembler/AssembleScans.h>
#include <laser_assembler/AssembleScans2.h>
#include <laser_assembler/AssembleScansRequest.h>
#include <laser_assembler/AssembleScans2Request.h>
#include <laser_assembler/AssembleScans2Response.h>
#include <laser_assembler/AssembleScans2.h>
#include <map_msgs/GetMapROI.h>
#include <map_msgs/GetMapROIRequest.h>
#include <map_msgs/GetMapROIResponse.h>
#include <map_msgs/GetPointMapRequest.h>
#include <map_msgs/GetPointMapROI.h>
#include <map_msgs/GetPointMapROIRequest.h>
#include <map_msgs/GetPointMapROIResponse.h>
#include <map_msgs/GetPointMap.h>
#include <map_msgs/GetPointMapResponse.h>
#include <map_msgs/GetPointMapROI.h>
#include <map_msgs/GetPointMapROIRequest.h>
#include <map_msgs/GetPointMapROIResponse.h>
#include <map_msgs/ProjectedMapsInfoResponse.h>
#include <map_msgs/ProjectedMapsInfo.h>
#include <map_msgs/ProjectedMapsInfoRequest.h>
#include <map_msgs/SaveMapRequest.h>
#include <map_msgs/SaveMapResponse.h>
#include <map_msgs/SaveMap.h>
#include <map_msgs/SetMapProjections.h>
#include <map_msgs/SetMapProjectionsRequest.h>
#include <map_msgs/SetMapProjectionsResponse.h>
#include <nav_msgs/GetMapRequest.h>
#include <nav_msgs/GetMapActionResult.h>
#include <nav_msgs/GetMapResponse.h>
#include <nav_msgs/GetMap.h>
#include <nav_msgs/GetMapResult.h>
#include <nav_msgs/GetMapGoal.h>
#include <nav_msgs/GetMapAction.h>
#include <nav_msgs/GetMapActionGoal.h>
#include <nav_msgs/GetMapFeedback.h>
#include <nav_msgs/GetMapActionFeedback.h>
#include <nav_msgs/GetPlan.h>
#include <nav_msgs/GetPlanResponse.h>
#include <nav_msgs/GetPlanRequest.h>
#include <nav_msgs/SetMap.h>
#include <nav_msgs/SetMapResponse.h>
#include <nav_msgs/SetMapRequest.h>
#include <nodelet/NodeletListRequest.h>
#include <nodelet/NodeletList.h>
#include <nodelet/NodeletListResponse.h>
#include <nodelet/NodeletLoadResponse.h>
#include <nodelet/NodeletLoad.h>
#include <nodelet/NodeletLoadRequest.h>
#include <nodelet/NodeletUnloadResponse.h>
#include <nodelet/NodeletUnload.h>
#include <nodelet/NodeletUnloadRequest.h>
#include <polled_camera/GetPolledImageRequest.h>
#include <polled_camera/GetPolledImage.h>
#include <polled_camera/GetPolledImageResponse.h>
#include <roscpp/EmptyRequest.h>
#include <roscpp/EmptyResponse.h>
#include <roscpp/Empty.h>
#include <roscpp/GetLoggersResponse.h>
#include <roscpp/GetLoggersRequest.h>
#include <roscpp/GetLoggers.h>
#include <roscpp/SetLoggerLevel.h>
#include <roscpp/SetLoggerLevelRequest.h>
#include <roscpp/SetLoggerLevelResponse.h>
#include <roscpp_tutorials/TwoIntsRequest.h>
#include <roscpp_tutorials/TwoInts.h>
#include <roscpp_tutorials/TwoIntsResponse.h>
#include <rospy_tutorials/AddTwoInts.h>
#include <rospy_tutorials/AddTwoIntsRequest.h>
#include <rospy_tutorials/AddTwoIntsResponse.h>
#include <rospy_tutorials/BadTwoIntsResponse.h>
#include <rospy_tutorials/BadTwoInts.h>
#include <rospy_tutorials/BadTwoIntsRequest.h>
#include <sensor_msgs/SetCameraInfoResponse.h>
#include <sensor_msgs/SetCameraInfoRequest.h>
#include <sensor_msgs/SetCameraInfo.h>
#include <std_srvs/EmptyRequest.h>
#include <std_srvs/EmptyResponse.h>
#include <std_srvs/Empty.h>
#include <std_srvs/SetBool.h>
#include <std_srvs/SetBoolResponse.h>
#include <std_srvs/SetBoolRequest.h>
#include <std_srvs/TriggerResponse.h>
#include <std_srvs/Trigger.h>
#include <std_srvs/TriggerRequest.h>
#include <tf/FrameGraphRequest.h>
#include <tf/FrameGraphResponse.h>
#include <tf/FrameGraph.h>
#include <tf2_msgs/FrameGraphRequest.h>
#include <tf2_msgs/FrameGraphResponse.h>
#include <tf2_msgs/FrameGraph.h>
#include <topic_tools/DemuxAddResponse.h>
#include <topic_tools/DemuxAddRequest.h>
#include <topic_tools/DemuxAdd.h>
#include <topic_tools/DemuxDelete.h>
#include <topic_tools/DemuxDeleteResponse.h>
#include <topic_tools/DemuxDeleteRequest.h>
#include <topic_tools/DemuxListResponse.h>
#include <topic_tools/DemuxList.h>
#include <topic_tools/DemuxListRequest.h>
#include <topic_tools/DemuxSelect.h>
#include <topic_tools/DemuxSelectRequest.h>
#include <topic_tools/DemuxSelectResponse.h>
#include <topic_tools/MuxAddRequest.h>
#include <topic_tools/MuxAddResponse.h>
#include <topic_tools/MuxAdd.h>
#include <topic_tools/MuxDeleteResponse.h>
#include <topic_tools/MuxDeleteRequest.h>
#include <topic_tools/MuxDelete.h>
#include <topic_tools/MuxListRequest.h>
#include <topic_tools/MuxList.h>
#include <topic_tools/MuxListResponse.h>
#include <topic_tools/MuxSelectResponse.h>
#include <topic_tools/MuxSelect.h>
#include <topic_tools/MuxSelectRequest.h>
#include <turtlesim/KillRequest.h>
#include <turtlesim/KillResponse.h>
#include <turtlesim/Kill.h>
#include <turtlesim/SetPenResponse.h>
#include <turtlesim/SetPenRequest.h>
#include <turtlesim/SetPen.h>
#include <turtlesim/SpawnRequest.h>
#include <turtlesim/SpawnResponse.h>
#include <turtlesim/Spawn.h>
#include <turtlesim/TeleportAbsoluteRequest.h>
#include <turtlesim/TeleportAbsoluteResponse.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/TeleportRelative.h>
#include <turtlesim/TeleportRelativeRequest.h>
#include <turtlesim/TeleportRelativeResponse.h>
// ROS service server template type instantiations
template class ZyROSConnectorServiceServerImpl<control_msgs::QueryCalibrationStateRequest, control_msgs::QueryCalibrationStateResponse, ZyROSConnectorServerRequestHandler<control_msgs::QueryCalibrationStateRequest, control_msgs::QueryCalibrationStateResponse>>;
template class ZyROSConnectorServiceServerImpl<control_msgs::QueryTrajectoryStateRequest, control_msgs::QueryTrajectoryStateResponse, ZyROSConnectorServerRequestHandler<control_msgs::QueryTrajectoryStateRequest, control_msgs::QueryTrajectoryStateResponse>>;
template class ZyROSConnectorServiceServerImpl<control_toolbox::SetPidGainsRequest, control_toolbox::SetPidGainsResponse, ZyROSConnectorServerRequestHandler<control_toolbox::SetPidGainsRequest, control_toolbox::SetPidGainsResponse>>;
template class ZyROSConnectorServiceServerImpl<controller_manager_msgs::ListControllerTypesRequest, controller_manager_msgs::ListControllerTypesResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::ListControllerTypesRequest, controller_manager_msgs::ListControllerTypesResponse>>;
template class ZyROSConnectorServiceServerImpl<controller_manager_msgs::ListControllersRequest, controller_manager_msgs::ListControllersResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::ListControllersRequest, controller_manager_msgs::ListControllersResponse>>;
template class ZyROSConnectorServiceServerImpl<controller_manager_msgs::LoadControllerRequest, controller_manager_msgs::LoadControllerResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::LoadControllerRequest, controller_manager_msgs::LoadControllerResponse>>;
template class ZyROSConnectorServiceServerImpl<controller_manager_msgs::ReloadControllerLibrariesRequest, controller_manager_msgs::ReloadControllerLibrariesResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::ReloadControllerLibrariesRequest, controller_manager_msgs::ReloadControllerLibrariesResponse>>;
template class ZyROSConnectorServiceServerImpl<controller_manager_msgs::SwitchControllerRequest, controller_manager_msgs::SwitchControllerResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::SwitchControllerRequest, controller_manager_msgs::SwitchControllerResponse>>;
template class ZyROSConnectorServiceServerImpl<controller_manager_msgs::UnloadControllerRequest, controller_manager_msgs::UnloadControllerResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::UnloadControllerRequest, controller_manager_msgs::UnloadControllerResponse>>;
template class ZyROSConnectorServiceServerImpl<diagnostic_msgs::AddDiagnosticsRequest, diagnostic_msgs::AddDiagnosticsResponse, ZyROSConnectorServerRequestHandler<diagnostic_msgs::AddDiagnosticsRequest, diagnostic_msgs::AddDiagnosticsResponse>>;
template class ZyROSConnectorServiceServerImpl<diagnostic_msgs::SelfTestRequest, diagnostic_msgs::SelfTestResponse, ZyROSConnectorServerRequestHandler<diagnostic_msgs::SelfTestRequest, diagnostic_msgs::SelfTestResponse>>;
template class ZyROSConnectorServiceServerImpl<dynamic_reconfigure::ReconfigureRequest, dynamic_reconfigure::ReconfigureResponse, ZyROSConnectorServerRequestHandler<dynamic_reconfigure::ReconfigureRequest, dynamic_reconfigure::ReconfigureResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::ApplyBodyWrenchRequest, gazebo_msgs::ApplyBodyWrenchResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::ApplyBodyWrenchRequest, gazebo_msgs::ApplyBodyWrenchResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::ApplyJointEffortRequest, gazebo_msgs::ApplyJointEffortResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::ApplyJointEffortRequest, gazebo_msgs::ApplyJointEffortResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::BodyRequestRequest, gazebo_msgs::BodyRequestResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::BodyRequestRequest, gazebo_msgs::BodyRequestResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::DeleteLightRequest, gazebo_msgs::DeleteLightResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::DeleteLightRequest, gazebo_msgs::DeleteLightResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::DeleteModelRequest, gazebo_msgs::DeleteModelResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::DeleteModelRequest, gazebo_msgs::DeleteModelResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetJointPropertiesRequest, gazebo_msgs::GetJointPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetJointPropertiesRequest, gazebo_msgs::GetJointPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetLightPropertiesRequest, gazebo_msgs::GetLightPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetLightPropertiesRequest, gazebo_msgs::GetLightPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetLinkPropertiesRequest, gazebo_msgs::GetLinkPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetLinkPropertiesRequest, gazebo_msgs::GetLinkPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetLinkStateRequest, gazebo_msgs::GetLinkStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetLinkStateRequest, gazebo_msgs::GetLinkStateResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetModelPropertiesRequest, gazebo_msgs::GetModelPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetModelPropertiesRequest, gazebo_msgs::GetModelPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetModelStateRequest, gazebo_msgs::GetModelStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetModelStateRequest, gazebo_msgs::GetModelStateResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetPhysicsPropertiesRequest, gazebo_msgs::GetPhysicsPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetPhysicsPropertiesRequest, gazebo_msgs::GetPhysicsPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::GetWorldPropertiesRequest, gazebo_msgs::GetWorldPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetWorldPropertiesRequest, gazebo_msgs::GetWorldPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::JointRequestRequest, gazebo_msgs::JointRequestResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::JointRequestRequest, gazebo_msgs::JointRequestResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetJointPropertiesRequest, gazebo_msgs::SetJointPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetJointPropertiesRequest, gazebo_msgs::SetJointPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetJointTrajectoryRequest, gazebo_msgs::SetJointTrajectoryResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetJointTrajectoryRequest, gazebo_msgs::SetJointTrajectoryResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetLightPropertiesRequest, gazebo_msgs::SetLightPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetLightPropertiesRequest, gazebo_msgs::SetLightPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetLinkPropertiesRequest, gazebo_msgs::SetLinkPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetLinkPropertiesRequest, gazebo_msgs::SetLinkPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetLinkStateRequest, gazebo_msgs::SetLinkStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetLinkStateRequest, gazebo_msgs::SetLinkStateResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetModelConfigurationRequest, gazebo_msgs::SetModelConfigurationResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetModelConfigurationRequest, gazebo_msgs::SetModelConfigurationResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetModelStateRequest, gazebo_msgs::SetModelStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetModelStateRequest, gazebo_msgs::SetModelStateResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SetPhysicsPropertiesRequest, gazebo_msgs::SetPhysicsPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetPhysicsPropertiesRequest, gazebo_msgs::SetPhysicsPropertiesResponse>>;
template class ZyROSConnectorServiceServerImpl<gazebo_msgs::SpawnModelRequest, gazebo_msgs::SpawnModelResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SpawnModelRequest, gazebo_msgs::SpawnModelResponse>>;
template class ZyROSConnectorServiceServerImpl<laser_assembler::AssembleScansRequest, laser_assembler::AssembleScansResponse, ZyROSConnectorServerRequestHandler<laser_assembler::AssembleScansRequest, laser_assembler::AssembleScansResponse>>;
template class ZyROSConnectorServiceServerImpl<laser_assembler::AssembleScans2Request, laser_assembler::AssembleScans2Response, ZyROSConnectorServerRequestHandler<laser_assembler::AssembleScans2Request, laser_assembler::AssembleScans2Response>>;
template class ZyROSConnectorServiceServerImpl<map_msgs::GetMapROIRequest, map_msgs::GetMapROIResponse, ZyROSConnectorServerRequestHandler<map_msgs::GetMapROIRequest, map_msgs::GetMapROIResponse>>;
template class ZyROSConnectorServiceServerImpl<map_msgs::GetPointMapRequest, map_msgs::GetPointMapResponse, ZyROSConnectorServerRequestHandler<map_msgs::GetPointMapRequest, map_msgs::GetPointMapResponse>>;
template class ZyROSConnectorServiceServerImpl<map_msgs::GetPointMapROIRequest, map_msgs::GetPointMapROIResponse, ZyROSConnectorServerRequestHandler<map_msgs::GetPointMapROIRequest, map_msgs::GetPointMapROIResponse>>;
template class ZyROSConnectorServiceServerImpl<map_msgs::ProjectedMapsInfoRequest, map_msgs::ProjectedMapsInfoResponse, ZyROSConnectorServerRequestHandler<map_msgs::ProjectedMapsInfoRequest, map_msgs::ProjectedMapsInfoResponse>>;
template class ZyROSConnectorServiceServerImpl<map_msgs::SaveMapRequest, map_msgs::SaveMapResponse, ZyROSConnectorServerRequestHandler<map_msgs::SaveMapRequest, map_msgs::SaveMapResponse>>;
template class ZyROSConnectorServiceServerImpl<map_msgs::SetMapProjectionsRequest, map_msgs::SetMapProjectionsResponse, ZyROSConnectorServerRequestHandler<map_msgs::SetMapProjectionsRequest, map_msgs::SetMapProjectionsResponse>>;
template class ZyROSConnectorServiceServerImpl<nav_msgs::GetMapRequest, nav_msgs::GetMapResponse, ZyROSConnectorServerRequestHandler<nav_msgs::GetMapRequest, nav_msgs::GetMapResponse>>;
template class ZyROSConnectorServiceServerImpl<nav_msgs::GetPlanRequest, nav_msgs::GetPlanResponse, ZyROSConnectorServerRequestHandler<nav_msgs::GetPlanRequest, nav_msgs::GetPlanResponse>>;
template class ZyROSConnectorServiceServerImpl<nav_msgs::SetMapRequest, nav_msgs::SetMapResponse, ZyROSConnectorServerRequestHandler<nav_msgs::SetMapRequest, nav_msgs::SetMapResponse>>;
template class ZyROSConnectorServiceServerImpl<nodelet::NodeletListRequest, nodelet::NodeletListResponse, ZyROSConnectorServerRequestHandler<nodelet::NodeletListRequest, nodelet::NodeletListResponse>>;
template class ZyROSConnectorServiceServerImpl<nodelet::NodeletLoadRequest, nodelet::NodeletLoadResponse, ZyROSConnectorServerRequestHandler<nodelet::NodeletLoadRequest, nodelet::NodeletLoadResponse>>;
template class ZyROSConnectorServiceServerImpl<nodelet::NodeletUnloadRequest, nodelet::NodeletUnloadResponse, ZyROSConnectorServerRequestHandler<nodelet::NodeletUnloadRequest, nodelet::NodeletUnloadResponse>>;
template class ZyROSConnectorServiceServerImpl<polled_camera::GetPolledImageRequest, polled_camera::GetPolledImageResponse, ZyROSConnectorServerRequestHandler<polled_camera::GetPolledImageRequest, polled_camera::GetPolledImageResponse>>;
template class ZyROSConnectorServiceServerImpl<roscpp::EmptyRequest, roscpp::EmptyResponse, ZyROSConnectorServerRequestHandler<roscpp::EmptyRequest, roscpp::EmptyResponse>>;
template class ZyROSConnectorServiceServerImpl<roscpp::GetLoggersRequest, roscpp::GetLoggersResponse, ZyROSConnectorServerRequestHandler<roscpp::GetLoggersRequest, roscpp::GetLoggersResponse>>;
template class ZyROSConnectorServiceServerImpl<roscpp::SetLoggerLevelRequest, roscpp::SetLoggerLevelResponse, ZyROSConnectorServerRequestHandler<roscpp::SetLoggerLevelRequest, roscpp::SetLoggerLevelResponse>>;
template class ZyROSConnectorServiceServerImpl<roscpp_tutorials::TwoIntsRequest, roscpp_tutorials::TwoIntsResponse, ZyROSConnectorServerRequestHandler<roscpp_tutorials::TwoIntsRequest, roscpp_tutorials::TwoIntsResponse>>;
template class ZyROSConnectorServiceServerImpl<rospy_tutorials::AddTwoIntsRequest, rospy_tutorials::AddTwoIntsResponse, ZyROSConnectorServerRequestHandler<rospy_tutorials::AddTwoIntsRequest, rospy_tutorials::AddTwoIntsResponse>>;
template class ZyROSConnectorServiceServerImpl<rospy_tutorials::BadTwoIntsRequest, rospy_tutorials::BadTwoIntsResponse, ZyROSConnectorServerRequestHandler<rospy_tutorials::BadTwoIntsRequest, rospy_tutorials::BadTwoIntsResponse>>;
template class ZyROSConnectorServiceServerImpl<sensor_msgs::SetCameraInfoRequest, sensor_msgs::SetCameraInfoResponse, ZyROSConnectorServerRequestHandler<sensor_msgs::SetCameraInfoRequest, sensor_msgs::SetCameraInfoResponse>>;
template class ZyROSConnectorServiceServerImpl<std_srvs::EmptyRequest, std_srvs::EmptyResponse, ZyROSConnectorServerRequestHandler<std_srvs::EmptyRequest, std_srvs::EmptyResponse>>;
template class ZyROSConnectorServiceServerImpl<std_srvs::SetBoolRequest, std_srvs::SetBoolResponse, ZyROSConnectorServerRequestHandler<std_srvs::SetBoolRequest, std_srvs::SetBoolResponse>>;
template class ZyROSConnectorServiceServerImpl<std_srvs::TriggerRequest, std_srvs::TriggerResponse, ZyROSConnectorServerRequestHandler<std_srvs::TriggerRequest, std_srvs::TriggerResponse>>;
template class ZyROSConnectorServiceServerImpl<tf::FrameGraphRequest, tf::FrameGraphResponse, ZyROSConnectorServerRequestHandler<tf::FrameGraphRequest, tf::FrameGraphResponse>>;
template class ZyROSConnectorServiceServerImpl<tf2_msgs::FrameGraphRequest, tf2_msgs::FrameGraphResponse, ZyROSConnectorServerRequestHandler<tf2_msgs::FrameGraphRequest, tf2_msgs::FrameGraphResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::DemuxAddRequest, topic_tools::DemuxAddResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxAddRequest, topic_tools::DemuxAddResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::DemuxDeleteRequest, topic_tools::DemuxDeleteResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxDeleteRequest, topic_tools::DemuxDeleteResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::DemuxListRequest, topic_tools::DemuxListResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxListRequest, topic_tools::DemuxListResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::DemuxSelectRequest, topic_tools::DemuxSelectResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxSelectRequest, topic_tools::DemuxSelectResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::MuxAddRequest, topic_tools::MuxAddResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxAddRequest, topic_tools::MuxAddResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::MuxDeleteRequest, topic_tools::MuxDeleteResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxDeleteRequest, topic_tools::MuxDeleteResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::MuxListRequest, topic_tools::MuxListResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxListRequest, topic_tools::MuxListResponse>>;
template class ZyROSConnectorServiceServerImpl<topic_tools::MuxSelectRequest, topic_tools::MuxSelectResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxSelectRequest, topic_tools::MuxSelectResponse>>;
template class ZyROSConnectorServiceServerImpl<turtlesim::KillRequest, turtlesim::KillResponse, ZyROSConnectorServerRequestHandler<turtlesim::KillRequest, turtlesim::KillResponse>>;
template class ZyROSConnectorServiceServerImpl<turtlesim::SetPenRequest, turtlesim::SetPenResponse, ZyROSConnectorServerRequestHandler<turtlesim::SetPenRequest, turtlesim::SetPenResponse>>;
template class ZyROSConnectorServiceServerImpl<turtlesim::SpawnRequest, turtlesim::SpawnResponse, ZyROSConnectorServerRequestHandler<turtlesim::SpawnRequest, turtlesim::SpawnResponse>>;
template class ZyROSConnectorServiceServerImpl<turtlesim::TeleportAbsoluteRequest, turtlesim::TeleportAbsoluteResponse, ZyROSConnectorServerRequestHandler<turtlesim::TeleportAbsoluteRequest, turtlesim::TeleportAbsoluteResponse>>;
template class ZyROSConnectorServiceServerImpl<turtlesim::TeleportRelativeRequest, turtlesim::TeleportRelativeResponse, ZyROSConnectorServerRequestHandler<turtlesim::TeleportRelativeRequest, turtlesim::TeleportRelativeResponse>>;


// ROS service server worker thread template type instantiations
template class ZyROSConnectorServiceServerWorkerThread<control_msgs::QueryCalibrationStateRequest, control_msgs::QueryCalibrationStateResponse, ZyROSConnectorServerRequestHandler<control_msgs::QueryCalibrationStateRequest, control_msgs::QueryCalibrationStateResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<control_msgs::QueryTrajectoryStateRequest, control_msgs::QueryTrajectoryStateResponse, ZyROSConnectorServerRequestHandler<control_msgs::QueryTrajectoryStateRequest, control_msgs::QueryTrajectoryStateResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<control_toolbox::SetPidGainsRequest, control_toolbox::SetPidGainsResponse, ZyROSConnectorServerRequestHandler<control_toolbox::SetPidGainsRequest, control_toolbox::SetPidGainsResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<controller_manager_msgs::ListControllerTypesRequest, controller_manager_msgs::ListControllerTypesResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::ListControllerTypesRequest, controller_manager_msgs::ListControllerTypesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<controller_manager_msgs::ListControllersRequest, controller_manager_msgs::ListControllersResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::ListControllersRequest, controller_manager_msgs::ListControllersResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<controller_manager_msgs::LoadControllerRequest, controller_manager_msgs::LoadControllerResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::LoadControllerRequest, controller_manager_msgs::LoadControllerResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<controller_manager_msgs::ReloadControllerLibrariesRequest, controller_manager_msgs::ReloadControllerLibrariesResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::ReloadControllerLibrariesRequest, controller_manager_msgs::ReloadControllerLibrariesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<controller_manager_msgs::SwitchControllerRequest, controller_manager_msgs::SwitchControllerResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::SwitchControllerRequest, controller_manager_msgs::SwitchControllerResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<controller_manager_msgs::UnloadControllerRequest, controller_manager_msgs::UnloadControllerResponse, ZyROSConnectorServerRequestHandler<controller_manager_msgs::UnloadControllerRequest, controller_manager_msgs::UnloadControllerResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<diagnostic_msgs::AddDiagnosticsRequest, diagnostic_msgs::AddDiagnosticsResponse, ZyROSConnectorServerRequestHandler<diagnostic_msgs::AddDiagnosticsRequest, diagnostic_msgs::AddDiagnosticsResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<diagnostic_msgs::SelfTestRequest, diagnostic_msgs::SelfTestResponse, ZyROSConnectorServerRequestHandler<diagnostic_msgs::SelfTestRequest, diagnostic_msgs::SelfTestResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<dynamic_reconfigure::ReconfigureRequest, dynamic_reconfigure::ReconfigureResponse, ZyROSConnectorServerRequestHandler<dynamic_reconfigure::ReconfigureRequest, dynamic_reconfigure::ReconfigureResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::ApplyBodyWrenchRequest, gazebo_msgs::ApplyBodyWrenchResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::ApplyBodyWrenchRequest, gazebo_msgs::ApplyBodyWrenchResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::ApplyJointEffortRequest, gazebo_msgs::ApplyJointEffortResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::ApplyJointEffortRequest, gazebo_msgs::ApplyJointEffortResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::BodyRequestRequest, gazebo_msgs::BodyRequestResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::BodyRequestRequest, gazebo_msgs::BodyRequestResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::DeleteLightRequest, gazebo_msgs::DeleteLightResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::DeleteLightRequest, gazebo_msgs::DeleteLightResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::DeleteModelRequest, gazebo_msgs::DeleteModelResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::DeleteModelRequest, gazebo_msgs::DeleteModelResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetJointPropertiesRequest, gazebo_msgs::GetJointPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetJointPropertiesRequest, gazebo_msgs::GetJointPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetLightPropertiesRequest, gazebo_msgs::GetLightPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetLightPropertiesRequest, gazebo_msgs::GetLightPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetLinkPropertiesRequest, gazebo_msgs::GetLinkPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetLinkPropertiesRequest, gazebo_msgs::GetLinkPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetLinkStateRequest, gazebo_msgs::GetLinkStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetLinkStateRequest, gazebo_msgs::GetLinkStateResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetModelPropertiesRequest, gazebo_msgs::GetModelPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetModelPropertiesRequest, gazebo_msgs::GetModelPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetModelStateRequest, gazebo_msgs::GetModelStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetModelStateRequest, gazebo_msgs::GetModelStateResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetPhysicsPropertiesRequest, gazebo_msgs::GetPhysicsPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetPhysicsPropertiesRequest, gazebo_msgs::GetPhysicsPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::GetWorldPropertiesRequest, gazebo_msgs::GetWorldPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::GetWorldPropertiesRequest, gazebo_msgs::GetWorldPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::JointRequestRequest, gazebo_msgs::JointRequestResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::JointRequestRequest, gazebo_msgs::JointRequestResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetJointPropertiesRequest, gazebo_msgs::SetJointPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetJointPropertiesRequest, gazebo_msgs::SetJointPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetJointTrajectoryRequest, gazebo_msgs::SetJointTrajectoryResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetJointTrajectoryRequest, gazebo_msgs::SetJointTrajectoryResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetLightPropertiesRequest, gazebo_msgs::SetLightPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetLightPropertiesRequest, gazebo_msgs::SetLightPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetLinkPropertiesRequest, gazebo_msgs::SetLinkPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetLinkPropertiesRequest, gazebo_msgs::SetLinkPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetLinkStateRequest, gazebo_msgs::SetLinkStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetLinkStateRequest, gazebo_msgs::SetLinkStateResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetModelConfigurationRequest, gazebo_msgs::SetModelConfigurationResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetModelConfigurationRequest, gazebo_msgs::SetModelConfigurationResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetModelStateRequest, gazebo_msgs::SetModelStateResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetModelStateRequest, gazebo_msgs::SetModelStateResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SetPhysicsPropertiesRequest, gazebo_msgs::SetPhysicsPropertiesResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SetPhysicsPropertiesRequest, gazebo_msgs::SetPhysicsPropertiesResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<gazebo_msgs::SpawnModelRequest, gazebo_msgs::SpawnModelResponse, ZyROSConnectorServerRequestHandler<gazebo_msgs::SpawnModelRequest, gazebo_msgs::SpawnModelResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<laser_assembler::AssembleScansRequest, laser_assembler::AssembleScansResponse, ZyROSConnectorServerRequestHandler<laser_assembler::AssembleScansRequest, laser_assembler::AssembleScansResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<laser_assembler::AssembleScans2Request, laser_assembler::AssembleScans2Response, ZyROSConnectorServerRequestHandler<laser_assembler::AssembleScans2Request, laser_assembler::AssembleScans2Response>>;
template class ZyROSConnectorServiceServerWorkerThread<map_msgs::GetMapROIRequest, map_msgs::GetMapROIResponse, ZyROSConnectorServerRequestHandler<map_msgs::GetMapROIRequest, map_msgs::GetMapROIResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<map_msgs::GetPointMapRequest, map_msgs::GetPointMapResponse, ZyROSConnectorServerRequestHandler<map_msgs::GetPointMapRequest, map_msgs::GetPointMapResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<map_msgs::GetPointMapROIRequest, map_msgs::GetPointMapROIResponse, ZyROSConnectorServerRequestHandler<map_msgs::GetPointMapROIRequest, map_msgs::GetPointMapROIResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<map_msgs::ProjectedMapsInfoRequest, map_msgs::ProjectedMapsInfoResponse, ZyROSConnectorServerRequestHandler<map_msgs::ProjectedMapsInfoRequest, map_msgs::ProjectedMapsInfoResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<map_msgs::SaveMapRequest, map_msgs::SaveMapResponse, ZyROSConnectorServerRequestHandler<map_msgs::SaveMapRequest, map_msgs::SaveMapResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<map_msgs::SetMapProjectionsRequest, map_msgs::SetMapProjectionsResponse, ZyROSConnectorServerRequestHandler<map_msgs::SetMapProjectionsRequest, map_msgs::SetMapProjectionsResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<nav_msgs::GetMapRequest, nav_msgs::GetMapResponse, ZyROSConnectorServerRequestHandler<nav_msgs::GetMapRequest, nav_msgs::GetMapResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<nav_msgs::GetPlanRequest, nav_msgs::GetPlanResponse, ZyROSConnectorServerRequestHandler<nav_msgs::GetPlanRequest, nav_msgs::GetPlanResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<nav_msgs::SetMapRequest, nav_msgs::SetMapResponse, ZyROSConnectorServerRequestHandler<nav_msgs::SetMapRequest, nav_msgs::SetMapResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<nodelet::NodeletListRequest, nodelet::NodeletListResponse, ZyROSConnectorServerRequestHandler<nodelet::NodeletListRequest, nodelet::NodeletListResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<nodelet::NodeletLoadRequest, nodelet::NodeletLoadResponse, ZyROSConnectorServerRequestHandler<nodelet::NodeletLoadRequest, nodelet::NodeletLoadResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<nodelet::NodeletUnloadRequest, nodelet::NodeletUnloadResponse, ZyROSConnectorServerRequestHandler<nodelet::NodeletUnloadRequest, nodelet::NodeletUnloadResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<polled_camera::GetPolledImageRequest, polled_camera::GetPolledImageResponse, ZyROSConnectorServerRequestHandler<polled_camera::GetPolledImageRequest, polled_camera::GetPolledImageResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<roscpp::EmptyRequest, roscpp::EmptyResponse, ZyROSConnectorServerRequestHandler<roscpp::EmptyRequest, roscpp::EmptyResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<roscpp::GetLoggersRequest, roscpp::GetLoggersResponse, ZyROSConnectorServerRequestHandler<roscpp::GetLoggersRequest, roscpp::GetLoggersResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<roscpp::SetLoggerLevelRequest, roscpp::SetLoggerLevelResponse, ZyROSConnectorServerRequestHandler<roscpp::SetLoggerLevelRequest, roscpp::SetLoggerLevelResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<roscpp_tutorials::TwoIntsRequest, roscpp_tutorials::TwoIntsResponse, ZyROSConnectorServerRequestHandler<roscpp_tutorials::TwoIntsRequest, roscpp_tutorials::TwoIntsResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<rospy_tutorials::AddTwoIntsRequest, rospy_tutorials::AddTwoIntsResponse, ZyROSConnectorServerRequestHandler<rospy_tutorials::AddTwoIntsRequest, rospy_tutorials::AddTwoIntsResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<rospy_tutorials::BadTwoIntsRequest, rospy_tutorials::BadTwoIntsResponse, ZyROSConnectorServerRequestHandler<rospy_tutorials::BadTwoIntsRequest, rospy_tutorials::BadTwoIntsResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<sensor_msgs::SetCameraInfoRequest, sensor_msgs::SetCameraInfoResponse, ZyROSConnectorServerRequestHandler<sensor_msgs::SetCameraInfoRequest, sensor_msgs::SetCameraInfoResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<std_srvs::EmptyRequest, std_srvs::EmptyResponse, ZyROSConnectorServerRequestHandler<std_srvs::EmptyRequest, std_srvs::EmptyResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<std_srvs::SetBoolRequest, std_srvs::SetBoolResponse, ZyROSConnectorServerRequestHandler<std_srvs::SetBoolRequest, std_srvs::SetBoolResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<std_srvs::TriggerRequest, std_srvs::TriggerResponse, ZyROSConnectorServerRequestHandler<std_srvs::TriggerRequest, std_srvs::TriggerResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<tf::FrameGraphRequest, tf::FrameGraphResponse, ZyROSConnectorServerRequestHandler<tf::FrameGraphRequest, tf::FrameGraphResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<tf2_msgs::FrameGraphRequest, tf2_msgs::FrameGraphResponse, ZyROSConnectorServerRequestHandler<tf2_msgs::FrameGraphRequest, tf2_msgs::FrameGraphResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::DemuxAddRequest, topic_tools::DemuxAddResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxAddRequest, topic_tools::DemuxAddResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::DemuxDeleteRequest, topic_tools::DemuxDeleteResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxDeleteRequest, topic_tools::DemuxDeleteResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::DemuxListRequest, topic_tools::DemuxListResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxListRequest, topic_tools::DemuxListResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::DemuxSelectRequest, topic_tools::DemuxSelectResponse, ZyROSConnectorServerRequestHandler<topic_tools::DemuxSelectRequest, topic_tools::DemuxSelectResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::MuxAddRequest, topic_tools::MuxAddResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxAddRequest, topic_tools::MuxAddResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::MuxDeleteRequest, topic_tools::MuxDeleteResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxDeleteRequest, topic_tools::MuxDeleteResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::MuxListRequest, topic_tools::MuxListResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxListRequest, topic_tools::MuxListResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<topic_tools::MuxSelectRequest, topic_tools::MuxSelectResponse, ZyROSConnectorServerRequestHandler<topic_tools::MuxSelectRequest, topic_tools::MuxSelectResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<turtlesim::KillRequest, turtlesim::KillResponse, ZyROSConnectorServerRequestHandler<turtlesim::KillRequest, turtlesim::KillResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<turtlesim::SetPenRequest, turtlesim::SetPenResponse, ZyROSConnectorServerRequestHandler<turtlesim::SetPenRequest, turtlesim::SetPenResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<turtlesim::SpawnRequest, turtlesim::SpawnResponse, ZyROSConnectorServerRequestHandler<turtlesim::SpawnRequest, turtlesim::SpawnResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<turtlesim::TeleportAbsoluteRequest, turtlesim::TeleportAbsoluteResponse, ZyROSConnectorServerRequestHandler<turtlesim::TeleportAbsoluteRequest, turtlesim::TeleportAbsoluteResponse>>;
template class ZyROSConnectorServiceServerWorkerThread<turtlesim::TeleportRelativeRequest, turtlesim::TeleportRelativeResponse, ZyROSConnectorServerRequestHandler<turtlesim::TeleportRelativeRequest, turtlesim::TeleportRelativeResponse>>;
