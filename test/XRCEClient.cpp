#include <micrortps/client/client.h>
#include <micrortps/client/xrce_protocol_spec.h>

#include <gtest/gtest.h>
#include <cstdint>
#include <unistd.h>

#include <fstream>

#define BUFFER_SIZE 1024

class ClientLogicTest : public ::testing::Test
{
    public:
        ClientLogicTest()
        {
            state = new_udp_client_state(BUFFER_SIZE, 2020, 2019);
        }

        ~ClientLogicTest()
        {
            free_client_state(state);
        }

        void checkStatus(uint8_t operation)
        {
            ASSERT_EQ(statusOperation, operation);
            ASSERT_EQ(statusImplementation, STATUS_OK);
        }

        void createClient()
        {
            create_client(state, on_status, this);
            send_to_agent(state);
            usleep(2000000);
            receive_from_agent(state);
        }

        uint16_t createParticipant()
        {
            uint16_t participant_id = create_participant(state);
            send_to_agent(state);
            receive_from_agent(state);

            return participant_id;
        }

        uint16_t createPublisher(uint16_t participant_id)
        {
            uint16_t publisher_id = create_publisher(state, participant_id);
            send_to_agent(state);
            receive_from_agent(state);

            return publisher_id;
        }

        uint16_t createSubscriber(uint16_t participant_id)
        {
            uint16_t subscriber_id = create_subscriber(state, participant_id);
            send_to_agent(state);
            receive_from_agent(state);

            return subscriber_id;
        }

        uint16_t createDataWriter(uint16_t participant_id, uint16_t publisher_id)
        {
            String xml;
            std::ifstream in("data_writer_profile");
            in.seekg (0, in.end);
            xml.length = in.tellg();
            in.seekg (0, in.beg);
            xml.data = new char [xml.length];
            in.read(xml.data, xml.length);

            uint16_t data_writer_id = create_data_writer(state, participant_id, publisher_id, xml);
            send_to_agent(state);
            receive_from_agent(state);

            return data_writer_id;
        }

        uint16_t createDataReader(uint16_t participant_id, uint16_t subscriber_id)
        {
            String xml;
            std::ifstream in("data_reader_profile");
            in.seekg (0, in.end);
            xml.length = in.tellg();
            in.seekg (0, in.beg);
            xml.data = new char [xml.length];
            in.read(xml.data, xml.length);

            uint16_t data_reader_id = create_data_reader(state, participant_id, subscriber_id, xml);
            send_to_agent(state);
            receive_from_agent(state);

            return data_reader_id;
        }

        void deleteClient()
        {
            //TODO
        }

        void deleteXRCEObject(uint16_t id)
        {
            delete_resource(state, id);
            send_to_agent(state);
            receive_from_agent(state);
        }

        ClientState* state;
        OnStatusReceived on_status;

        uint16_t statusId;
        uint8_t statusOperation;
        uint8_t statusImplementation;
};

void on_status(uint16_t id, uint8_t operation, uint8_t status, void* args)
{
    ClientLogicTest* test = static_cast<ClientLogicTest*>(args);

    test->statusId = id;
    test->statusOperation = operation;
    test->statusImplementation = status;
}

TEST_F(ClientLogicTest, CreateDeleteClient)
{
    createClient();
    createClient();

    checkStatus(STATUS_LAST_OP_CREATE);

    //deleteClient();
    //checkStatus(STATUS_LAST_OP_DELETE);
}

/*
TEST_F(ClientLogicTest, CreateDeleteParticipant)
{
    createClient();
    uint16_t participant_id = createParticipant();

    checkStatus(STATUS_LAST_OP_CREATE);

    deleteXRCEObject(participant_id);
    checkStatus(STATUS_LAST_OP_DELETE);
}

TEST_F(ClientLogicTest, CreateDeletePublisher)
{
    createClient();
    uint16_t participant_id = createParticipant();
    uint16_t publisher_id = createPublisher(participant_id);

    checkStatus(STATUS_LAST_OP_CREATE);

    deleteXRCEObject(publisher_id);
    checkStatus(STATUS_LAST_OP_DELETE);
}

TEST_F(ClientLogicTest, CreateDeleteSubscriber)
{
    createClient();
    uint16_t participant_id = createParticipant();
    uint16_t subscriber_id = createSubscriber(participant_id);

    checkStatus(STATUS_LAST_OP_CREATE);

    deleteXRCEObject(subscriber_id);
    checkStatus(STATUS_LAST_OP_DELETE);
}
*/