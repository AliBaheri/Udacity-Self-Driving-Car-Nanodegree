#ifndef TRAJECTORY_GENERATOR_H
#define TRAJECTORY_GENERATOR_H

#include <vector>

#include "ego_vehicle_data.h"
#include "map_data.h"

#include "behavior_planner.h"

class TrajectoryGenerator
{
public:
    TrajectoryGenerator();
    void generateTrajectory(const CarBehavior next_action,
                            const EgoVehicleData& ego_vehicle_data,
                            const MapData& map_data,
                            std::vector<double>& out_x,
                            std::vector<double>& out_y);
private:
    // The number of waypoints for the output trajectory
    static const std::size_t kNrTrajectoryPoints = 50U;

    // The delta time between waypoints, in seconds
    static constexpr double kSimulationTimeStep = 0.02;

    void generateTrajectoryFollowLane(const EgoVehicleData& ego_vehicle_data,
                                      const MapData& map_data,
                                      std::vector<double>& out_x,
                                      std::vector<double>& out_y);
};

#endif // TRAJECTORY_GENERATOR_H
