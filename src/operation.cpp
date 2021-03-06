
#include "operation.hpp"
std::unique_ptr<OperationBase>
OperationBase::read(std::string const& command) {
    auto args = split(command, ' ');
    if (args[0] == "quit")
        return std::make_unique<Operation<OpType::Quit> >();
    else if (args[0] == "load")
        return std::make_unique<Operation<OpType::Load> >(args[1]);
    else if (args[0] == "sleep")
        return std::make_unique<Operation<OpType::Sleep> >(std::stoi(args[1]));
    else if (args[0] == "forward")
        return std::make_unique<Operation<OpType::Go> >(Operation<OpType::Go>::Dir::Forward, std::stoi(args[1]));
    else if (args[0] == "backward")
        return std::make_unique<Operation<OpType::Go> >(Operation<OpType::Go>::Dir::Backward, std::stoi(args[1]));
    else if (args[0] == "left")
        return std::make_unique<Operation<OpType::Turn> >(Operation<OpType::Turn>::Dir::Left);
    else if (args[0] == "right")
        return std::make_unique<Operation<OpType::Turn> >(Operation<OpType::Turn>::Dir::Right);
    else if (args[0] == "pen" && args[1] == "up")
        return std::make_unique<Operation<OpType::Pen> >(Operation<OpType::Pen>::Action::Up);
    else if (args[0] == "pen" && args[1] == "down")
        return std::make_unique<Operation<OpType::Pen> >(Operation<OpType::Pen>::Action::Down);
    else
        return std::make_unique<Operation<OpType::Invalid> >();
}


