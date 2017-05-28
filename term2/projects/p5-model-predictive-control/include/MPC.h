#ifndef MPC_H
#define MPC_H

#include <vector>
#include <Eigen/Core>

#include "actuators.h"
#include "optimizer.h"
#include "mpc_model.h"

class MPC
{
public:
    MPC();

    /// \brief Solves the MPC model, outputting actuator commands
    /// \param state current state of the car
    /// \param coeffs desired trajectory
    /// \return actuator commands for next control loop
    bool computeCommands(const Eigen::VectorXd& state,
                         const Eigen::VectorXd& des_trajectory_coeffs,
                         Actuators& actuator_commands,
                         std::vector<double>& output_trajectory_x,
                         std::vector<double>& output_trajectory_y);

private:
    Optimizer optimizer_;
};

#endif  // MPC_H
