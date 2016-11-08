
#include "operation.hpp"

std::unique_ptr<OperationBase>
OperationBase::read(std::string const& command) {
    auto args = split(command, ' ');
    if (args[0] == "quit")
        return std::make_unique<Operation<OpType::Quit> >();
    else if (args[0] == "load")
        return std::make_unique<Operation<OpType::Load> >(args[1]);
    else if (args[0] == "forward")
        return std::make_unique<Operation<OpType::Forward> >(std::stoi(args[1]));
    else if (args[0] == "backward")
        return std::make_unique<Operation<OpType::Backward> >(std::stoi(args[1]));
    else if (args[0] == "left")
        return std::make_unique<Operation<OpType::TurnLeft> >();
    else if (args[0] == "right")
        return std::make_unique<Operation<OpType::TurnRight> >();
    else
        return std::make_unique<Operation<OpType::Invalid> >();
}


